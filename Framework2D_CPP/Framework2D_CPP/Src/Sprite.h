#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "Framework.h"
#define RANGE 100

class Sprite
{
protected:
	Point _pos;
	Texture* _tex;
	Rect _rect;
	int _w, _h;
	char* _tag;
	bool isRender;
	Uint8 _alpha;
	
public:
	Sprite();
	Sprite(int, int);
	Sprite(Point);
	virtual ~Sprite();

	#pragma region Get and Set methods
	Point getPosition();
	Rect getRect();
	Texture* getTexture();
	int getWidth();
	int getHeight();
	char* getTag();
	Uint8 getAlpha();
	void setPosition(Point);
	void setPosition(int, int);
	void setRect(Rect);
	void setTexture(Texture*);
	void setWidth(int);
	void setHeight(int);
	void setTag(char*);
	void setAlpha(Uint8);
	#pragma endregion

	void LoadTextureFromFile(char*); //Load texture from file
	//void MoveTo(Point, float);
	//void MoveTo(int, int, float);
	void MoveTo(int, int, int);
	void MoveTo(Point, int);
	void SetBlendMode(BlendMode);
	void Render();
	void Render(int, int);
	void Render(int, int, int, int);
	void RenderAnimation(int, int, int, int, int, int, int, int);
	void RenderAnimation(int, int, int, int, int, int, int, int, int, int); //Render sprite sheet
	void Rotate(double angle);
	virtual bool CheckCollision(Sprite*);
	bool isOutOfScreen();
	bool CheckIsRender();
};

#endif

