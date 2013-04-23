#ifndef TESTSYSTEMS_H_
#define TESTSYSTEMS_H_

#include "base_scene.h"

#include "keyboard_state.h"
#include "waypoint_manager.h"

#include "SDL/SDL.h"

class TestSystems : public BaseScene {
public:
	TestSystems();
	virtual ~TestSystems();
protected:
	//frame loop
	void Update();
	void Render(SDL_Surface* const screen);
	//events
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);
	virtual void KeyDown			(SDL_KeyboardEvent const&);
	virtual void KeyUp				(SDL_KeyboardEvent const&);
	//things being tested
	void TestFunction(int x, int y);
	WaypointManager waypointMgr;
	Point *pointOne, *pointTwo;

	KeyboardState ks;
};

#endif
