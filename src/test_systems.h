#ifndef TESTSYSTEMS_H_
#define TESTSYSTEMS_H_

#include "base_scene.h"

#include "SDL/SDL.h"

class TestSystems : public BaseScene {
public:
	TestSystems();
	virtual ~TestSystems();
protected:
	//frame loop
	void UpdateObjects();
	void Render();
	//events
	virtual void QuitEvent(SDL_Event&);
	virtual void MouseMotion(SDL_Event&);
	virtual void MouseButtonDown(SDL_Event&);
	virtual void MouseButtonUp(SDL_Event&);
	virtual void KeyDown(SDL_Event&);
	virtual void KeyUp(SDL_Event&);
};

#endif
