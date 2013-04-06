#include "test_scene.h"

#include "SDL_gfx/SDL_gfxPrimitives.h"

#include <iostream>

void TestScene::Render() {
	boxRGBA(screen, 300, 300, 400, 400, 255, 126, 64, 255);
	SDL_Flip(screen);
}

void TestScene::QuitEvent(SDL_Event& e) {
	strategy = -1;
}