#include "test_systems.h"
#include "error.h"
#include "strategy_list.h"

#include "SDL_gfx/SDL_gfxPrimitives.h"

#include <iostream>
using namespace std;

TestSystems::TestSystems() {
	cout << "\"TestSystems\" active" << endl;
	Point* p1 = waypointMgr.NewPoint(32, 32);
	Point* p2 = waypointMgr.NewPoint(64, 64);
	Point* p3 = waypointMgr.NewPoint(128, 128);
	Point* p4 = waypointMgr.NewPoint(512, 128);
	Point* p5 = waypointMgr.NewPoint(128, 512);
	Point* p6 = waypointMgr.NewPoint(512, 512);

	waypointMgr.NewPath(p1, p2);
	waypointMgr.NewPath(p2, p3);
	waypointMgr.NewPath(p3, p4);
	waypointMgr.NewPath(p4, p6);
	waypointMgr.NewPath(p6, p5);
	waypointMgr.NewPath(p5, p3);
	waypointMgr.NewPath(p4, p5);
}

TestSystems::~TestSystems() {
	cout << "\"TestSystems\" closing" << endl;
}

//frame loop
void TestSystems::UpdateObjects() {
	//
}

void TestSystems::Render() {
	SDL_FillRect(GetScreen(), nullptr, 0);

	for (auto it : *waypointMgr.GetPathList()) {
		lineColor(GetScreen(), it.one->x, it.one->y, it.two->x, it.two->y, 0x00FF00FF);
	}

	for (auto it : *waypointMgr.GetPointList()) {
		circleColor(GetScreen(), it.x, it.y, 4, 0xFF0000FF);
	}

	int x, y;
	SDL_GetMouseState(&x, &y);
	Point* p = waypointMgr.GetNearestPoint(x, y);
	if (p != nullptr) {
		circleColor(GetScreen(), p->x, p->y, 8, 0x000FFFF);
	}
}

//events
void TestSystems::QuitEvent(SDL_Event& event) {
	SetStrategy(QUIT);
}

void TestSystems::MouseMotion(SDL_Event& event) {
	//
}

void TestSystems::MouseButtonDown(SDL_Event& event) {
	switch(event.button.button) {
		case SDL_BUTTON_LEFT:
			waypointMgr.NewPoint(event.button.x, event.button.y);
		break;
		case SDL_BUTTON_RIGHT:
			waypointMgr.DeleteNearestPoint(event.button.x, event.button.y);
		break;
	}
}

void TestSystems::MouseButtonUp(SDL_Event& event) {
	//
}

void TestSystems::KeyDown(SDL_Event& event) {
	switch(event.key.keysym.sym) {
		case SDLK_ESCAPE:
			SetStrategy(QUIT);
		break;
		case SDLK_SPACE:
			SetStrategy(TESTSYSTEMS);
		break;
	}
}

void TestSystems::KeyUp(SDL_Event& event) {
	//
}

void TestSystems::TestFunction(int x, int y) {
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,500);
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,64);

//	if (it == waypointMgr.GetPointList()->end()) {
//		cout << "attempting to erase point " << it->index << endl;
//		waypointMgr.GetPointList()->erase(it);
//	}
}
