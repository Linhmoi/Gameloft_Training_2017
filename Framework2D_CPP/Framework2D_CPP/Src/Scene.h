#pragma one
#ifndef SCENE_H
#define SCENE_H

#include "Framework.h"

class Scene
{
protected:
	int _screenW;
	int _screenH;
	bool isFirstRun;
	int _index;

public:
	Scene();
	Scene(int, int);
	virtual ~Scene();

	#pragma region Get and Set methods
	int getIndex();
	#pragma endregion

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	virtual void OnMouseDown();
	virtual void OnMouseOver();
	virtual void OnKeyDown(int);
};

#endif // !
