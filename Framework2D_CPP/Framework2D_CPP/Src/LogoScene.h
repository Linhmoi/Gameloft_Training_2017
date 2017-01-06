#pragma once
#ifndef LOGO_SCENE_H
#define LOGO_SCENE_H

#include "Scene.h"
#include "Sprite.h"

#define LOGO_SIZE_W 500
#define LOGO_SIZE_H 300

class LogoScene : public Scene
{
private:
	Sprite* _logo;
	int _waitTime;

public:
	LogoScene();
	LogoScene(int, int);
	~LogoScene();

	#pragma region Get and Set methods
	int getWaitTime();
	void setWaitTime(int);
	#pragma endregion

	void Init();
	void Update();
	void Render();
	void Destroy();

	void OnMouseDown();
	void OnMouseOver();
	void OnKeyDown(int);

	void ShowLogo();
};

#endif // LOGO_SCENE_H

