#pragma one
#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "Framework.h"
#include "Scene.h"
#include "UIElement.h"
#include "Public.h"

class MenuScene : public Scene
{
private:
	Sprite* _background;
	Sprite* _secondBackground;
	UIElement* _gameTitle;
	UIElement* _btnPlay;
	UIElement* _btnAbout;
	UIElement* _btnHelp;
	UIElement* _btnExit;

public:
	MenuScene();
	MenuScene(int, int);
	~MenuScene();

	void Init();
	void Update();
	void Render();
	void Destroy();

	void OnMouseOver();
	void OnMouseDown();
	void OnKeyDown(int key);
	void ScrollBackground();
};

#endif // !MENU_SCENE_H
