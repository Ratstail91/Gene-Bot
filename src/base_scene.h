#ifndef BASESCENE_H_
#define BASESCENE_H_

#include "SDL/SDL.h"

class BaseScene {
public:
	//outermost function calls
	BaseScene();
	virtual ~BaseScene() {}
	virtual void RunFrame();

	//run frame
	virtual void BeginLoop() {};
	virtual void HandleEvents();
	virtual void UpdateObjects() {};
	virtual void Render() {};
	virtual void EndLoop() {};

	//the most common events
	virtual void QuitEvent(SDL_Event&)=0;
	virtual void MouseMotion(SDL_Event&) {};
	virtual void MouseButtonDown(SDL_Event&) {};
	virtual void MouseButtonUp(SDL_Event&) {};
	virtual void KeyDown(SDL_Event&) {};
	virtual void KeyUp(SDL_Event&) {};

	//strategy pattern
	virtual int SetStrategy(int i) {
		return strategy = i;
	}
	virtual int GetStrategy() const {
		return strategy;
	}

	//screen hooks
	SDL_Surface* SetScreen(SDL_Surface* p) {
		return screen = p;
	}
	SDL_Surface* GetScreen() {
		return screen;
	}

protected:
	int strategy;
	SDL_Surface* screen;
};

#endif
