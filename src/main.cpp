#include "base_scene.h"
#include "test_scene.h"

#include "SDL/SDL.h"

#include <iostream>

using namespace std;

int SDL_main(int, char**) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Failed to init SDL" << endl;
		return 1;
	}

	SDL_Surface* screen;

	if (!(screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE))) {
		cerr << "Failed to create the screen" << endl;
		return 1;
	}

	BaseScene* scene = new TestScene();

	scene->SetScreen(screen);

	scene->Setup();

	while(scene->GetStrategy() != -1) {
		scene->RunFrame();
	}
	scene->Cleanup();

	delete scene;

	SDL_Quit();

	cout << "Clean exit" << endl;
	return 0;
}