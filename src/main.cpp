#include "error.h"
#include "scene_manager.h"

#include "SDL/SDL.h"

#include <iostream>

int SDL_main(int, char**) {
	SceneManager* ptr = SceneManager::GetSingleton();
	try {
		ptr->Init();
		ptr->Loop();
		ptr->Quit();
	}
	catch(Error& e) {
		std::cerr << "Fatal " << e.GetError() << std::endl;
		return 1;
	}
	return 0;
}