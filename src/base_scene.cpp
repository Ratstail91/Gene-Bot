#include "base_scene.h"

BaseScene::BaseScene() {
	strategy = 0;
}

//outermost function calls
void BaseScene::RunFrame() {
	BeginLoop();
	HandleEvents();
	UpdateObjects();
	Render();
	EndLoop();
}

//run frame
void BaseScene::HandleEvents() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				QuitEvent(event);
			break;
			case SDL_MOUSEMOTION:
				MouseMotion(event);
			break;
			case SDL_MOUSEBUTTONDOWN:
				MouseButtonDown(event);
			break;
			case SDL_MOUSEBUTTONUP:
				MouseButtonUp(event);
			break;
			case SDL_KEYDOWN:
				KeyDown(event);
			break;
			case SDL_KEYUP:
				KeyUp(event);
			break;
		}
	}
}
