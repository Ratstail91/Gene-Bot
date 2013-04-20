#include "scene_manager.h"

//these are the scenes used in the scene strategy
#include "strategy_list.h"

#include "scene.h"
#include "test_systems.h"

#include <stdexcept>

SceneManager::SceneManager() {
	screen = nullptr;
	scenePtr = nullptr;
}

SceneManager::~SceneManager() {
	UnloadScene();
}

//outermost functions
void SceneManager::Init() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		throw(std::runtime_error("Failed to initialize SDL"));
	}
	SetScreen(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
}

void SceneManager::Loop() {
	LoadScene(FIRST);
	while (scenePtr->GetStrategy() != QUIT) {
		if (scenePtr->GetStrategy() != CONTINUE) {
			LoadScene(scenePtr->GetStrategy());
			continue;
		}
		scenePtr->RunFrame();
	}
	UnloadScene();
}

void SceneManager::Quit() {
	SDL_Quit();
}

//screen hooks
SDL_Surface* SceneManager::SetScreen(int w, int h, int bpp, Uint32 flags) {
	//use simplest and fastest option for now; assume windows or linux platforms
	screen = SDL_SetVideoMode(w, h, bpp, flags);
	if (!screen) {
		throw(std::runtime_error("Failed to create the screen surface"));
	}
	//kind of bloated, but a convinience for SDL 1.2
	if (scenePtr) {
		scenePtr->SetScreen(screen);
	}
}

SDL_Surface* SceneManager::GetScreen() const {
	return screen;
}

//singleton hooks
SceneManager* SceneManager::GetSingleton() {
	static SceneManager sceneManager;
	return &sceneManager;
}

//protected
void SceneManager::LoadScene(int index) {
	UnloadScene();
	switch(index) {
		case FIRST:
		case TESTSYSTEMS:
			scenePtr = new TestSystems();
		break;
		case SCENE:
			scenePtr = new Scene();
		break;
		case QUIT:
		case CONTINUE:
			throw(std::logic_error("Reserved scene values accessed"));
		default:
			throw(std::logic_error("Unknown scene value received"));
	}
	scenePtr->SetScreen(screen);
}

void SceneManager::UnloadScene() {
	delete scenePtr;
	scenePtr = nullptr;
}
