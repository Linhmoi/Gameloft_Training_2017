#pragma once
#ifndef LOADING_SCENE_H
#define LOADING_SCENE_H

#include "Scene.h"
#include "UIElement.h"
#include "Sprite.h"
#include "Public.h"

#define LOADING_SPRITE_W 160
#define LOADING_SPRITE_H 40

class LoadingScene : public Scene
{
private:
	UIElement* _txtLoading;
	Sprite* _sprLoading;
public:
	LoadingScene();
	LoadingScene(int, int);
	~LoadingScene();

	void Init();
	void Update();
	void Render();
	void Destroy();

	void LoadingCircle();
};

#endif // !LOADING_SCENE_H

