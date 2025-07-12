
#include <vector>
#include <cppgamelib\file\Logger.h>
#include <cppgamelib\file\SettingsManager.h>
#include <iostream>

using namespace std;

int main()
{
	std::cout << "Starting test exe.\n";

	gamelib::Logger::Get()->LogThis("Help!");

	gamelib::SettingsManager::Get()->ReadSettingsFile("settings.xml");

	/*
	 <audio>
                <setting name="invalid_move" type="string">low.wav</setting>
                <setting name="fetched_pickup" type="string">boop.wav</setting>
                <setting name="win_music" type="string">win.wav</setting>
        </audio>
	*/
    // Use cppgamelib to read settings from xml file
	std::cout << "The win music is: " << gamelib::SettingsManager::Get()->GetString("audio","win_music") << "\n";
	std::cout << "The fetched pickup music is: " << gamelib::SettingsManager::Get()->GetString("audio","fetched_pickup") << "\n";
	std::cout << "The invalid move music is: " << gamelib::SettingsManager::Get()->GetString("audio","invalid_move") << "\n";

}