#include "scene_manager.h"

#include "SDL/SDL.h"

#include <exception>
#include <iostream>

using namespace std;

int SDL_main(int, char**) {
	SceneManager* ptr = SceneManager::GetSingleton();
	try {
		ptr->Init();
		ptr->Loop();
		ptr->Quit();
	}
	catch(exception& e) {
		cerr << "Fatal Error: " << e.what() << endl;
		return 1;
	}
	return 0;
}