#ifndef TESTSCENE_H_
#define TESTSCENE_H_

#include "base_scene.h"

class TestScene : public BaseScene {
public:
	TestScene() {};
	virtual ~TestScene() {};

	virtual void Render();

	virtual void QuitEvent(SDL_Event&);
private:
};

#endif
