#include "scene.h"
#include "error.h"
#include "strategy_list.h"

Scene::Scene() {
	//
}

Scene::~Scene() {
	//
}

//frame loop
void Scene::UpdateObjects() {
	//
}

void Scene::Render() {
	SDL_Flip(GetScreen());
}

//events
void Scene::QuitEvent(SDL_Event& event) {
	SetStrategy(QUIT);
}

void Scene::KeyDown(SDL_Event& event) {
	switch(event.key.keysym.sym) {
		case SDLK_ESCAPE:
			SetStrategy(QUIT);
		break;
	}
}