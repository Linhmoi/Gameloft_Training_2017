#include "Sprite.h"
#include <math.h>

Sprite::Sprite()
{
	this->_tex = NULL;
	this->_pos.x = 0;
	this->_pos.y = 0;
	this->_w = 0;
	this->_h = 0;
	this->isRender = false;
	this->_alpha = 255;
	this->_tag = "image";
}

Sprite::Sprite(int x, int y)
{
	this->_tex = NULL;
	this->_pos.x = x;
	this->_pos.y = y;
	this->_w = 0;
	this->_h = 0;
	this->isRender = false;
	this->_alpha = 255;
	this->_tag = "image";
}

Sprite::Sprite(Point pos)
{
	this->_pos = pos;
	this->_tex = NULL;
	this->_w = 0;
	this->_h = 0;
	this->isRender = false;
	this->_alpha = 255;
	this->_tag = "image";
}

Sprite::~Sprite()
{
	fwDestroyTexture(_tex);
}

Point Sprite::getPosition()
{
	return this->_pos;
}

Rect Sprite::getRect()
{
	return this->_rect;
}

Texture* Sprite::getTexture()
{
	return this->_tex;
}

int Sprite::getHeight()
{
	return this->_h;
}

int Sprite::getWidth()
{
	return this->_w;
}

char* Sprite::getTag()
{
	return this->_tag;
}

Uint8 Sprite::getAlpha()
{
	return this->_alpha;
}

void Sprite::setPosition(Point pos)
{
	this->_pos = pos;
}

void Sprite::setPosition(int x, int y)
{
	this->_pos.x = x;
	this->_pos.y = y;
}

void Sprite::setHeight(int height)
{
	this->_h = height;
}

void Sprite::setWidth(int width)
{
	this->_w = width;
}

void Sprite::setTexture(Texture* _tex)
{
	this->_tex = _tex;
}

void Sprite::setRect(Rect _rect)
{
	this->_rect = _rect;
}

void Sprite::setTag(char* tag)
{
	this->_tag = tag;
}

void Sprite::setAlpha(Uint8 alpha)
{
	this->_alpha = alpha;
	SDL_SetTextureAlphaMod(this->_tex, this->_alpha);
}

void Sprite::LoadTextureFromFile(char* path)
{
	fwLoadTexture(path, this->_tex, this->_w, this->_h);
}

void Sprite::SetBlendMode(BlendMode mode)
{
	SDL_SetTextureBlendMode(this->_tex, mode);
}

void Sprite::Render()
{
	this->_rect.x = this->_pos.x;
	this->_rect.y = this->_pos.y;
	this->_rect.h = this->_h;
	this->_rect.w = this->_w;

	fwRenderTexture(this->_tex, NULL, &this->_rect);
	this->isRender = true;
}

void Sprite::Render(int w, int h)
{
	Rect src;
	src.x = 0;
	src.y = 0;
	src.h = this->_h;
	src.w = this->_w;

	this->_rect.x = this->_pos.x;
	this->_rect.y = this->_pos.y;
	this->_rect.h = h;
	this->_rect.w = w;
	SDL_Log("Draw");
	fwRenderTexture(this->_tex, &src, &this->_rect);
	this->isRender = true;
}

void Sprite::Render(int x, int y, int w, int h)
{
	Rect src;
	src.x = 0;
	src.y = 0;
	src.h = this->_h;
	src.w = this->_w;

	this->_pos.x = x;
	this->_pos.y = y;

	this->_rect.x = this->_pos.x;
	this->_rect.y = this->_pos.y;
	this->_rect.h = h;
	this->_rect.w = w;

	fwRenderTexture(this->_tex, &src, &this->_rect);
	this->isRender = true;
}


//Summary: Render a spritesheet
//startFrame: the position of the first frame you want to render.
//nFrames: the number of frames you want to render.
//speed: rendering speed.
//offset: pixel offset between 2 frame.
//frameW: frame's width
//frameH: frame's height
//w: width
//h: height
//x: position x
//y: position y
void Sprite::RenderAnimation(int startFrame, int nFrames, int offset,int frameW, int frameH,int x = 0, int y = 0, int w = 50, int h = 50, int speed = 1)
{
	Uint32 tick = SDL_GetTicks();
	int realSpeed = 100 * speed;
	int frame = (tick / realSpeed) % nFrames + startFrame;

	this->_pos.x = x;
	this->_pos.y = y;

	for (int i = startFrame; i < nFrames; ++i)
	{
		Rect src = { frame * offset, 0, frameW, frameH };
		this->_rect = { this->_pos.x, this->_pos.y, w, h };
		fwRenderTexture(this->_tex, &src, &this->_rect);
	}
	this->isRender = true;
}

void Sprite::RenderAnimation(int startFrame, int nFrames, int offset, int frameW, int frameH, int w = 50, int h = 50, int speed = 1)
{
	Uint32 tick = SDL_GetTicks();
	int realSpeed = 100 * speed;
	int frame = (tick / realSpeed) % nFrames + startFrame;

	for (int i = startFrame; i < nFrames; ++i)
	{
		Rect src = { frame * offset, 0, frameW, frameH };
		this->_rect = { this->_pos.x, this->_pos.y, w, h };
		fwRenderTexture(this->_tex, &src, &this->_rect);
	}
	this->isRender = true;
}

void Sprite::Rotate(double angle)
{
	Rect src;
	src.x = 0;
	src.y = 0;
	src.h = this->_h;
	src.w = this->_w;

	this->_rect.x = this->_pos.x;
	this->_rect.y = this->_pos.y;

	fwRotateTexture(this->_tex, &src, &this->_rect, angle);
}

void Sprite::MoveTo(Point dest, int velocity = 1)
{
	if (dest.x > this->_pos.x)
	{
		this->_pos.x += velocity;
	}
	if (dest.x < this->_pos.x)
	{
		this->_pos.x -= velocity;
	}
	if (dest.y > this->_pos.y)
	{
		this->_pos.y += velocity;
	}
	if (dest.y < this->_pos.y)
	{
		this->_pos.y -= velocity;
	}
}

void Sprite::MoveTo(int destX, int destY, int velocity = 1)
{
	if (destX > this->_pos.x)
	{
		this->_pos.x += velocity;
	}
	if (destX < this->_pos.x)
	{
		this->_pos.x -= velocity;
	}
	if (destY > this->_pos.y)
	{
		this->_pos.y += velocity;
	}
	if (destY < this->_pos.y)
	{
		this->_pos.y -= velocity;
	}
}

//Summary: move to new position in an amount of time.
//void Sprite::MoveTo(Point pos, float time = 1)
//{
//	Uint32 tick = SDL_GetTicks();
//	float milisec = time * 1000;
//	float deltaX = (float)(pos.x - this->_pos.x);
//	float deltaY = (float)(pos.y - this->_pos.y);
//	float distance = sqrtf(powf(deltaX, 2) + pow(deltaY, 2)); // calculate distance between 2 position
//	float velocity = distance / milisec; // calculate velocity
//
//	while (SDL_GetTicks() < tick + milisec)
//	{
//		if (pos.x > this->_pos.x)
//		{
//			this->_pos.x += velocity;
//		}
//		if (pos.x < this->_pos.x)
//		{
//			this->_pos.x -= velocity;
//		}
//		if (pos.y > this->_pos.y)
//		{
//			this->_pos.y += velocity;
//		}
//		if (pos.y < this->_pos.y)
//		{
//			this->_pos.y += velocity;
//		}
//	}
//}

//Check collision between 2 sprite
bool Sprite::CheckCollision(Sprite* spr)
{
	return false;
}

bool Sprite::isOutOfScreen()
{
	int screenW, screenH;
	fwGetDisplayMode(screenW, screenH);

	if (this->_pos.x <= 0 - this->_rect.h - RANGE || this->_pos.x >= screenH + this->_rect.h + RANGE)
	{
		return true;
	}

	if (this->_pos.y <= 0 - this->_rect.w - RANGE || this->_pos.y >= screenW + this->_rect.w + RANGE)
	{
		return true;
	}

	return false;
}

bool Sprite::CheckIsRender()
{
	if (this->isRender)
	{
		return true;
	}
	return false;
}

