#include "test_systems.h"
#include "error.h"
#include "strategy_list.h"

#include <iostream>
using namespace std;

TestSystems::TestSystems() {
	cout << "\"TestSystems\" active" << endl;
}

TestSystems::~TestSystems() {
	cout << "\"TestSystems\" closing" << endl;
}

//frame loop
void TestSystems::UpdateObjects() {
	//
}

void TestSystems::Render() {
	//
}

//events
void TestSystems::QuitEvent(SDL_Event& event) {
	SetStrategy(QUIT);
}

void TestSystems::MouseMotion(SDL_Event& event) {
	//
}

void TestSystems::MouseButtonDown(SDL_Event& event) {
	//
}

void TestSystems::MouseButtonUp(SDL_Event& event) {
	//
}

void TestSystems::KeyDown(SDL_Event& event) {
	switch(event.key.keysym.sym) {
		case SDLK_ESCAPE:
			SetStrategy(QUIT);
		break;
	}
}

void TestSystems::KeyUp(SDL_Event& event) {
	//
}
