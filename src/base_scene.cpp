#include "base_scene.h"

#include "strategy_list.h"

//outermost function calls
BaseScene::BaseScene() {
	strategy = CONTINUE;
}

void BaseScene::RunFrame() {
	BeginLoop();
	HandleEvents();
	UpdateObjects();
	Render();
	SDL_Flip(screen);
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
