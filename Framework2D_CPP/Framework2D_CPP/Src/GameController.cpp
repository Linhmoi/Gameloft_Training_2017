#include "GameController.h"

GameController* GameController::_instance;

GameController::GameController()
{
	this->_background = new Sprite();
	this->_secondBG = new Sprite();
	this->_player = new Player();
	this->_score = new UIElement();
	this->_txtWinGame = new UIElement();
	this->_txtGameOver = new UIElement();
	this->_isWin = false;
	this->_isGameOver = false;
	this->_level = 1;
}

GameController::~GameController()
{
}

GameController* GameController::getInstance()
{
	if (!_instance)
	{
		_instance = new GameController();
	}
	return _instance;
}

int GameController::getLevel()
{
	return this->_level;
}

int GameController::NumberOfEnemies()
{
	return this->_nEnemies;
}

void GameController::SpawnEnemy()
{
	for (int i = 0; i < this->_nEnemies - 1; i++)
	{
		
	}
}
