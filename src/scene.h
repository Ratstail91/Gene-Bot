#ifndef SCENE_H_
#define SCENE_H_

#include "base_scene.h"

#include "SDL/SDL.h"

class Scene : public BaseScene {
public:
	Scene();
	virtual ~Scene();
protected:
	//frame loop
	void UpdateObjects();
	void Render();
	//events
	void QuitEvent(SDL_Event&);
	void KeyDown(SDL_Event&);
};

#endif
