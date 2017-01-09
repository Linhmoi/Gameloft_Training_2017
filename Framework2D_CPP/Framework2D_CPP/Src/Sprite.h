#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "Framework.h"
#define RANGE 20

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
	Uint32 _startTime;
	bool isCollied;
	
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
	Uint32 getStartTime();
	bool CheckIsCollied();
	void setPosition(Point);
	void setPosition(int, int);
	void setRect(Rect);
	void setTexture(Texture*);
	void setWidth(int);
	void setHeight(int);
	void setTag(char*);
	void setAlpha(Uint8);
	void setIsRender(bool);
	void setIsCollied(bool);
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
	bool isOutOfScreen(int, int);
	bool CheckIsRender();
};

#endif

