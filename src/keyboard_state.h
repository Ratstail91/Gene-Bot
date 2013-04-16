#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

/* I always figured that this sort of thing was unnecessary, given SDL's
 * internal key array accessable by SDL_GetKeyState(), but that array doesn't
 * catch a keypress if it happens between event processing. So, technically,
 * this method is better.
 * 
 * This could be adapted to some sort of text input system later, so I'm leaving
 * it in.
*/

#include "SDL/SDL.h"

class KeyboardState {
public:
	KeyboardState();
	void KeyDown(SDLKey&);
	void KeyUp(SDLKey&);

	bool operator[](SDLKey);
private:
	bool keys[SDLK_LAST];
};

#endif
