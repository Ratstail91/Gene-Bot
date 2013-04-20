#include "test_systems.h"
#include "strategy_list.h"

#include "SDL_gfx/SDL_gfxPrimitives.h"

#include <stdexcept>
#include <iostream>

using namespace std;

TestSystems::TestSystems() {
	cout << "\"TestSystems\" active" << endl;

	pointOne = pointTwo = nullptr;

#ifdef DEBUG
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
#endif
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
	//paths & points
	for (auto it : *waypointMgr.GetPathList()) {
		lineRGBA(GetScreen(), it.one->x, it.one->y, it.two->x, it.two->y, 0, 0, 255, 255);
	}
	for (auto it : *waypointMgr.GetPointList()) {
		circleRGBA(GetScreen(), it.x, it.y, 4, 255, 0, 0, 255);
	}
	//nearest point to the mouse
	int x, y;
	SDL_GetMouseState(&x, &y);
	Point* nearest = waypointMgr.GetNearestPoint(x, y);
	if (nearest != nullptr) {
		circleRGBA(GetScreen(), nearest->x, nearest->y, 8, 255, 0, 255, 255);
	}
	//selected points
	if (pointOne != nullptr) {
		circleRGBA(GetScreen(), pointOne->x, pointOne->y, 8, 0, 255, 0, 255);
	}
	if (pointTwo != nullptr) {
		circleRGBA(GetScreen(), pointTwo->x, pointTwo->y, 8, 2, 255, 0, 255);
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
			if (ks[SDLK_LSHIFT]) {
				if (pointOne == nullptr) {
					pointOne = waypointMgr.GetNearestPoint(event.button.x, event.button.y);
				}
				else if (pointTwo == nullptr) {
					pointTwo = waypointMgr.GetNearestPoint(event.button.x, event.button.y);
					if (pointOne == pointTwo) {
						pointTwo = nullptr;
					}
				}
			}
			else {
				waypointMgr.NewPoint(event.button.x, event.button.y);
			}
		break;
		case SDL_BUTTON_RIGHT:
			if (!ks[SDLK_LSHIFT]) {
				waypointMgr.DeleteNearestPoint(event.button.x, event.button.y);
			}
			pointOne = pointTwo = nullptr;
		break;
	}
}

void TestSystems::MouseButtonUp(SDL_Event& event) {
	//
}

void TestSystems::KeyDown(SDL_Event& event) {
	ks.KeyDown(event.key.keysym.sym);
	switch(event.key.keysym.sym) {
		case SDLK_ESCAPE:
			SetStrategy(QUIT);
		break;
		case SDLK_RETURN:
			SetStrategy(TESTSYSTEMS);
		break;
		case SDLK_SPACE:
			if (pointOne && pointTwo) {
				if (ks[SDLK_LSHIFT]) {
					waypointMgr.DeletePath(pointOne, pointTwo);
				}
				else {
					waypointMgr.NewPath(pointOne, pointTwo);
				}
			}
			pointOne = pointTwo = nullptr;
		break;
	}
}

void TestSystems::KeyUp(SDL_Event& event) {
	ks.KeyUp(event.key.keysym.sym);
}

void TestSystems::TestFunction(int x, int y) {
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,500);
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,64);

//	if (it == waypointMgr.GetPointList()->end()) {
//		cout << "attempting to erase point " << it->index << endl;
//		waypointMgr.GetPointList()->erase(it);
//	}
}
