#include "GameScene.h"

GameScene::GameScene()
{
	this->_player = new Player();
	this->_background = new Sprite();
	this->_secondBG = new Sprite();
	this->_index = 3;
	this->_txtWinGame = new UIElement();
	this->_txtGameOver = new UIElement();
	//this->_explosion = new Sprite();
	//this->_starEffect = new Sprite();
	this->_isGameOver = false;
	this->_isWin = false;
	this->_score = new UIElement();
	this->_level = 1;

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i] = new Sprite();
	}
}

GameScene::GameScene(int w, int h) : Scene(w, h)
{
	this->_player = new Player();
	this->_background = new Sprite();
	this->_secondBG = new Sprite();
	this->_index = 3;
	this->_txtWinGame = new UIElement();
	this->_txtGameOver = new UIElement();
	//this->_explosion = new Sprite();
	//this->_starEffect = new Sprite();
	this->_isGameOver = false;
	this->_isWin = false;
	this->_score = new UIElement();
	this->_level = 1;

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i] = new Sprite();
	}
}

GameScene::~GameScene()
{

}

void GameScene::Init()
{

}

void GameScene::Update()
{

}

void GameScene::Render()
{

}

void GameScene::Destroy()
{

}

int GameScene::getLevel()
{
	return this->_level;
}

void GameScene::OnMouseDown()
{

}

void GameScene::OnMouseOver()
{

}

void GameScene::OnKeyDown(int key)
{

}