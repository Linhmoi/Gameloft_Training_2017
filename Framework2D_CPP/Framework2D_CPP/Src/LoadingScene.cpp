#include "LoadingScene.h"

LoadingScene::LoadingScene()
{
	this->_sprLoading = new Sprite();
	this->_txtLoading = new UIElement();
	this->_index = 1;
}

LoadingScene::LoadingScene(int w, int h) : Scene(w, h)
{
	this->_sprLoading = new Sprite();
	this->_txtLoading = new UIElement();
	this->_index = 1;
}

LoadingScene::~LoadingScene()
{
	
}

void LoadingScene::Init()
{
	this->_sprLoading->LoadTextureFromFile("Resources/Loading.png");
	this->_txtLoading->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);

	this->_txtLoading->setColor(BTN_TEXT_COLOR);
	this->_txtLoading->setText("Loading");

	this->_txtLoading->LoadTextureFromFont(UIElement::TextType::Solid);

	SDL_Log("spr Width: %d", this->_sprLoading->getWidth());
	this->_sprLoading->setPosition(((this->_screenW / 2) - (LOADING_SPRITE_W / 2)), ((this->_screenH / 2) - (LOADING_SPRITE_H / 2)));
	this->_txtLoading->setPosition((this->_screenW / 2) - (BTN_TEXT_W / 2), (this->_screenH / 2) - (BTN_TEXT_H / 2) - 50);
}

void LoadingScene::Update()
{

}

void LoadingScene::Render()
{
	this->_txtLoading->Render(BTN_TEXT_W, BTN_TEXT_H);
	this->_sprLoading->RenderAnimation(0, 13, 160, 160, 20, LOADING_SPRITE_W, LOADING_SPRITE_H, 1);
}

void LoadingScene::Destroy()
{
	delete this->_sprLoading;
	delete this->_txtLoading;
}