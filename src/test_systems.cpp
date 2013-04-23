#include "test_systems.h"
#include "scene_list.h"

#include "SDL_gfx/SDL_gfxPrimitives.h"

#include <stdexcept>
#include <iostream>

using namespace std;

TestSystems::TestSystems() {
	cout << "\"TestSystems\" active" << endl;

	pointOne = pointTwo = nullptr;

	cam.SetScreenSize(GetScreen()->w, GetScreen()->h);

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
void TestSystems::Update() {
	cout << cam.GetPosition().x << "\t" << cam.GetPosition().y << endl;
}

void TestSystems::Render(SDL_Surface* const screen) {
	SDL_FillRect(screen, nullptr, 0);
	//paths & points
	for (auto it : *waypointMgr.GetPathList()) {
		lineRGBA(screen, it.one->x, it.one->y, it.two->x, it.two->y, 0, 0, 255, 255);
	}
	for (auto it : *waypointMgr.GetPointList()) {
		circleRGBA(screen, it.x, it.y, 4, 255, 0, 0, 255);
	}
	//nearest point to the mouse
	int x, y;
	SDL_GetMouseState(&x, &y);
	Point* nearest = waypointMgr.GetNearestPoint(x, y);
	if (nearest != nullptr) {
		circleRGBA(screen, nearest->x, nearest->y, 8, 255, 0, 255, 255);
	}
	//selected points
	if (pointOne != nullptr) {
		circleRGBA(screen, pointOne->x, pointOne->y, 8, 0, 255, 0, 255);
	}
	if (pointTwo != nullptr) {
		circleRGBA(screen, pointTwo->x, pointTwo->y, 8, 2, 255, 0, 255);
	}
}

//events
void TestSystems::MouseMotion(SDL_MouseMotionEvent const& motion) {
	if (motion.state & SDL_BUTTON_LMASK) {
		cam.ShiftPosition(Vector2(motion.xrel,motion.yrel));
		return;
	}
	if (motion.state & SDL_BUTTON_WHEELDOWN) {
		if (cam.GetScale() >= 6) {
			cam.SetScale(6);
		}
		else {
			cam.ShiftScale(1.2);
		}
		return;
	}
	if (motion.state & SDL_BUTTON_WHEELUP) {
		if (cam.GetScale() <= 1) {
			cam.SetScale(1);
		}
		else {
			cam.ShiftScale(0.8);
		}
		return;
	}
}

void TestSystems::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	switch(button.button) {
		case SDL_BUTTON_LEFT:
			if (ks[SDLK_LSHIFT]) {
				if (pointOne == nullptr) {
					pointOne = waypointMgr.GetNearestPoint(button.x, button.y);
				}
				else if (pointTwo == nullptr) {
					pointTwo = waypointMgr.GetNearestPoint(button.x, button.y);
					if (pointOne == pointTwo) {
						pointTwo = nullptr;
					}
				}
			}
			else {
				waypointMgr.NewPoint(button.x, button.y);
			}
		break;
		case SDL_BUTTON_RIGHT:
			if (!ks[SDLK_LSHIFT]) {
				waypointMgr.DeleteNearestPoint(button.x, button.y);
			}
			pointOne = pointTwo = nullptr;
		break;
	}
}

void TestSystems::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void TestSystems::KeyDown(SDL_KeyboardEvent const& key) {
	ks.KeyDown(key.keysym.sym);
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			SetNextScene(SceneList::QUIT);
		break;
		case SDLK_RETURN:
			SetNextScene(SceneList::TESTSYSTEMS);
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

void TestSystems::KeyUp(SDL_KeyboardEvent const& key) {
	ks.KeyUp(key.keysym.sym);
}

void TestSystems::TestFunction(int x, int y) {
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,500);
//	PointList::iterator it = waypointMgr.GetNearestPointIterator(x,y,64);

//	if (it == waypointMgr.GetPointList()->end()) {
//		cout << "attempting to erase point " << it->index << endl;
//		waypointMgr.GetPointList()->erase(it);
//	}
}
