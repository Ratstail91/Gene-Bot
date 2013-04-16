#include "keyboard_state.h"

#include "error.h"

KeyboardState::KeyboardState() {
	for (int i = SDLK_FIRST; i < SDLK_LAST; i++) {
		keys[i] = false;
	}
}

void KeyboardState::KeyDown(SDLKey& key) {
	if (key < SDLK_FIRST || key >= SDLK_LAST) {
		throw(LogicError("Key out of range"));
	}
	keys[key] = true;
}

void KeyboardState::KeyUp(SDLKey& key) {
	if (key < SDLK_FIRST || key >= SDLK_LAST) {
		throw(LogicError("Key out of range"));
	}
	keys[key] = false;
}

bool KeyboardState::operator[](SDLKey key) {
	if (key < SDLK_FIRST || key >= SDLK_LAST) {
		throw(LogicError("Key out of range"));
	}
	return keys[key];
}
