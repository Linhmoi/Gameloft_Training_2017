#include "LogoScene.h"

LogoScene::LogoScene()
{
	this->_logo = new Sprite();
	this->_waitTime = 5;
}

LogoScene::LogoScene(int w, int h) : Scene(w, h)
{
	this->_logo = new Sprite();
	this->_index = 0;
	this->_waitTime = 5;
}

LogoScene::~LogoScene()
{
	this->Destroy();
}

int LogoScene::getWaitTime()
{
	return this->_waitTime;
}

void LogoScene::setWaitTime(int waitTime)
{
	this->_waitTime = waitTime;
}

void LogoScene::Init()
{
	this->_logo->LoadTextureFromFile("Resources/logo.png");
	this->_logo->setAlpha(0);

	int posX = (this->_screenW / 2) - (LOGO_SIZE_W / 2);
	int posY = (this->_screenH / 2) - (LOGO_SIZE_H / 2);
	this->_logo->setPosition(posX, posY);
	this->_logo->SetBlendMode(BlendMode::SDL_BLENDMODE_BLEND);
}

void LogoScene::Update()
{
	SDL_Log("ticks: %d", SDL_GetTicks());
	if (SDL_GetTicks() < this->_waitTime * 1000)
	{
		SDL_Log("start show");
		this->ShowLogo();
	}
	//SDL_TimerID timer = SDL_AddTimer((1 * 1000), this->ShowLogo, "after 1 second");
}

void LogoScene::Render()
{
	this->_logo->Render(LOGO_SIZE_W, LOGO_SIZE_H);
	SDL_Delay(150);
}

void LogoScene::Destroy()
{
	delete this->_logo;
}

void LogoScene::ShowLogo()
{
	Uint8 alpha = this->_logo->getAlpha();

	if (alpha >= 15 || alpha <= 255)
	{
		SDL_Log("increase alpha");
		if (alpha + 5 > 255)
		{
			alpha = 255;
		}
		else
		{
			alpha += 15;
		}
		this->_logo->setAlpha(alpha);
	}
	SDL_Log("Cur alpha: %d", this->_logo->getAlpha());
}

void LogoScene::OnKeyDown(int key)
{

}

void LogoScene::OnMouseDown()
{

}

void LogoScene::OnMouseOver()
{

}
