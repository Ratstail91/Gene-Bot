#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "base_scene.h"

#include "SDL/SDL.h"

class SceneManager {
public:
	//outermost functions
	void Init();
	void Loop();
	void Quit();
	//screen hooks
	SDL_Surface* SetScreen(int w, int h, int bpp, Uint32 flags);
	SDL_Surface* GetScreen() const;
	//singleton hooks
	static SceneManager* GetSingleton();
private:
	SceneManager();
	virtual ~SceneManager();
	void LoadScene(int);
	void UnloadScene();
	SDL_Surface* screen;
	BaseScene* scenePtr;
};

#endif
