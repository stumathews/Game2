# Game2

This is an example of a building a simple game called Game2.

The game is comprised of the following files:

* main.cpp 
* GameCommands.cpp 
* InputManager.cpp 
* LevelManager.cpp

The game is built on a foundation of existing functionality provided by primarily the CppGameLib library which provides standard gaming functionality such:

* A game loop
* Resource/asset management
* Event management
* Networking
* more

In addition to CppGameLib, the game uses a game-specific library called Mazer which houses most of the game specific code such as the game characters, Level information etc. 

The game source files call into CppGameLib and Mazer to utilize this functionality and so much of the implementation for example of setting up the game loop in main.cpp is hidden. For example to start the game loop means calling a one-liner provided by CppGameLib.

```cpp
infrastructure.DoGameLoop(&mazer::GameDataManager::Get()->GameWorldData);

```

Other game specific code constructs such as Enemy classes are provided by Mazer, however new games might build all their code within the game itself and not call upon external libraries. Mazer however provides a lot of characters and game objects that are ready to use.

The CppGameLib library depends on functionality provided by other libraries:

* SDL2
* SDL2_ttf
* SDL2_mixer
* SDL2_image
* Sodium

The game build process ensures that these, CppGameLib and Mazer libraries are fetched, built and otherwise made available to the game during build/link time.

# Getting started

You need to ensure you have VCPKG and CMAKE installed.

VCPKG is used as the package manager to build these dependencies and make them available to the game when it builds.

CMake is used to generate the Visual Studio project files and build the game from the command line.

For example, CMake relies on VCPKG_ROOT environment variable being set (which it typically is if you install VCPKG). See CMakePresets.json


## Fetch Dependencies and Generate Project files

First, instruct vcpkg to fetch all the required dependencies:

```
cmake --preset=default
```

This will also generate the game project files and put them in the build folder.


This will install the games dependencies such as SDL2*, CppGamelib, mazer etc. These dependencies are listed in cmakelists.txt

## Build

Them once all the dependencies are built (and there are no errors), instruct the build system to build the game from the project files that were generated in the build folder:

```
cmake --build build
```
This will result in the game2.exe being built and linked to all the dependencies that it uses.

## Run the game

To run the game, run the game's executable:

```
build/game2.exe
```



