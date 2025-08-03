#include "SDL.h"
#include <vector>
#include <cppgamelib\file\Logger.h>
#include <cppgamelib\file\SettingsManager.h>
#include <iostream>
#include <cppgamelib/file/TextFile.h>
#include <cppgamelib/structure/GameStructure.h>
#include <cppgamelib/structure/FixedStepGameLoop.h>
#include <direct.h> // Add this at the top for _getcwd
#include <cppgamelib/objects/GameWorldData.h>
using namespace std;

int main(int argc, char* argv[])
{
	std::cout << "Starting test exe.\n";

	gamelib::Logger::Get()->LogThis("Help!");

	auto ok = gamelib::SettingsManager::Get()->ReadSettingsFile("settings.xml");

	if (!ok)
	{

            char cwd[1024];
            if (_getcwd(cwd, sizeof(cwd)) != nullptr)
            {
                std::cout << "Current working directory: " << cwd << "\n";
            }
            else
            {
                std::cout << "Failed to get current working directory.\n";
            }
		std::cout << "Could not read settings.xml file.\n";
		return 1;
	}

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

	// Use cppgamelib to read a text file
	gamelib::TextFile textFile("info.log");
	textFile.Append("This is a test log entry.");
	textFile.Flush();
	
	// 60 FPS
	auto fixedStepGameLoop = std::make_shared<gamelib::FixedStepGameLoop>(60,
		[](unsigned long deltaMs) 
		{
			// Update function 
			std::cout << "u. " << deltaMs << " ms\n";
		},
		[]() 
		{
			// Drawing function
			std::cout << "d";
		}, 
		[](unsigned long deltaMs) 
		{
			// Handle input function
			std::cout << "i" << deltaMs << " ms\n";
		});

	gamelib::GameStructure gameStructure(fixedStepGameLoop);
	//gameStructure.Initialize(800, 600, "Test Game", "data\\Resources.xml", "data\\");
	gamelib::GameWorldData gameWorldData;
	gameStructure.DoGameLoop(&gameWorldData);

	gameStructure.Unload();

	return 0;
}