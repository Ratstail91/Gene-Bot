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
	cout << cam.GetScale() << "\t" << cam.GetPosition().x << "\t" << cam.GetPosition().y << endl;
}

void TestSystems::Render(SDL_Surface* const screen) {
	SDL_FillRect(screen, nullptr, 0);
	//paths & points
	Vector2 v = cam.GetCamPosition();
	for (auto it : *waypointMgr.GetPathList()) {
		lineRGBA(screen, v.x+it.one->x, v.y+it.one->y, v.x+it.two->x, v.y+it.two->y, 0, 0, 255, 255);
	}
	for (auto it : *waypointMgr.GetPointList()) {
		circleRGBA(screen, v.x+it.x, v.y+it.y, 4, 255, 0, 0, 255);
	}
	//nearest point to the mouse
	int x, y;
	SDL_GetMouseState(&x, &y);
	Point* nearest = waypointMgr.GetNearestPoint(x, y);
	if (nearest != nullptr) {
		circleRGBA(screen, v.x+nearest->x, v.y+nearest->y, 8, 255, 0, 255, 255);
	}
	//selected points
	if (pointOne != nullptr) {
		circleRGBA(screen, v.x+pointOne->x, v.y+pointOne->y, 8, 0, 255, 0, 255);
	}
	if (pointTwo != nullptr) {
		circleRGBA(screen, v.x+pointTwo->x, v.y+pointTwo->y, 8, 2, 255, 0, 255);
	}
}

//events
void TestSystems::MouseMotion(SDL_MouseMotionEvent const& motion) {
	if (motion.state & SDL_BUTTON_LMASK) {
		cam.ShiftPosition(Vector2(motion.xrel,motion.yrel));
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
		case SDL_BUTTON_WHEELUP:
			cout << "Wheel up" << endl;
			if (cam.GetScale() >= 6) {
				cam.SetScale(6);
			}
			else {
				cam.ShiftScale(0.2);
			}
		break;
		case SDL_BUTTON_WHEELDOWN:
			cout << "wheel down" << endl;
			if (cam.GetScale() <= 1) {
				cam.SetScale(1);
			}
			else {
				cam.ShiftScale(-.2);
			}
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
