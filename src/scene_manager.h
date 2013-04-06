#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "base_scene.h"

#include "SDL/SDL.h"

class SceneManager {
public:
	//outermost function calls
	SceneManager();
	virtual ~SceneManager();

	void Run();

	//screen hooks
	SDL_Surface* SetScreen(SDL_Surface* p) {
		return screen = p;
	}
	SDL_Surface* GetScreen() {
		return screen;
	}
private:
	BaseScene* activeScene;
	SDL_Surface* screen;
};

#endif
