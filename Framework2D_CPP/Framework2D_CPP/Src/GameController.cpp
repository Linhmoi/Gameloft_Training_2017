#include "GameController.h"
using namespace std;

GameController* GameController::_instance;

GameController::GameController()
{
	this->_background = new Sprite();
	this->_secondBG = new Sprite();
	this->_player = new Player();
	this->_score = new UIElement();
	this->_txtWinGame = new UIElement();
	this->_txtGameOver = new UIElement();
	this->_txtPause = new UIElement();
	this->_isWin = false;
	this->_isGameOver = false;
	this->_level = 1;
	this->_nEnemies = 10;
	this->_waitTime = 3;
	this->_delay = 1;

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i] = new Sprite();
	}
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

bool GameController::IsWin()
{
	return this->_isWin;
}

bool GameController::IsGameOver()
{
	return this->_isGameOver;
}

void GameController::Awake(int screenW, int screenH)
{
	this->_player->LoadTextureFromFile(PLAYER_SPRITE_PATH);
	this->_background->LoadTextureFromFile(BG3_SPRITE_PATH);
	this->_secondBG->LoadTextureFromFile(BG3_SPRITE_PATH);
	this->_txtGameOver->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_txtWinGame->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_score->LoadFont(BTN_TEXT_FONT, SCORE_TEXT_FONT_SIZE);
	this->_txtPause->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);

	this->_txtGameOver->setColor(BTN_TEXT_COLOR);
	this->_txtWinGame->setColor(BTN_TEXT_COLOR);
	this->_score->setColor(BTN_TEXT_COLOR);
	this->_txtPause->setColor(BTN_TEXT_COLOR);

	this->_txtGameOver->setText("Game Over!\nPress Esc to exit or R to restart");
	this->_txtWinGame->setText("You win!\nPress Esc to exit or Enter to continue or R to restart");
	this->_score->setText("000000");
	this->_txtPause->setText("Paused! Press U to resume");

	this->_txtGameOver->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtWinGame->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_score->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtPause->LoadTextureFromFont(UIElement::TextType::Solid);

	int centerX = (screenW / 2) - (BTN_TEXT_W / 2);
	int centerY = (screenH / 2) - (BTN_TEXT_H / 2);
	this->_txtGameOver->setPosition(centerX, centerY);
	this->_txtWinGame->setPosition(centerX, centerY);
	this->_score->setPosition(screenW - BTN_TEXT_W, 0);
	this->_player->setPosition(centerX, screenH - PLAYER_H - 50);

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i]->LoadTextureFromFile(HEART_SPRITE_PATH);
		if (i != 0)
		{
			this->_hearts[i]->setPosition(this->_hearts[i - 1]->getPosition().x + 90, 0);
		}
		else
		{
			this->_hearts[i]->setPosition(0, 0);
		}
	}
}

void GameController::SpawnEnemy(int screenW, int screenH)
{
	int rangeX = screenW + 1 - (ENEMY_W / 2);
	int rangeY = (screenH - TOP_BOUND + 1) - TOP_BOUND - (ENEMY_H / 2);
	int index = this->_listEnemy.size;

	if (this->_listEnemy.size < this->_nEnemies)
	{
		this->_listEnemy.push_back(new Enemy());
		this->_listEnemy[index]->setPosition(rand() % rangeX, rand() % rangeY);
		this->_listEnemy[index]->LoadTextureFromFile(ENEMY_SPRITE_PATH);
		this->_listEnemy[index]->Render(ENEMY_W, ENEMY_H);
	}
}

void GameController::WinGame()
{
	this->_isWin = true;
	this->_txtWinGame->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::GameOver()
{
	this->_isGameOver = true;
	this->_txtGameOver->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::PauseGame()
{
	this->_isPause = true;
	this->_txtPause->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::PlayNextLevel()
{
	this->_level++; //Increase level

}

void GameController::ExitGame(int screenW, int screenH)
{

}

void GameController::RestartLevel(int screenW, int screenH)
{
	this->_nEnemies = this->_level * 10;
	this->Awake(screenW, screenH);
}

//Summary: Reset scene to original state
void GameController::Reset(int screenW, int screenH)
{
	this->_explosion.clear();
	this->_starEffect.clear();
	this->_listEnemy.clear();
	this->_listWeapon.clear();
	this->_score->setText("000000");
	this->_isWin = false;
	this->_isPause = false;
	this->_isGameOver = false;

	int centerX = (screenW / 2) - (BTN_TEXT_W / 2);
	//int centerY = (screenH / 2) - (BTN_TEXT_H / 2);
	this->_player->setPosition(centerX, screenH - PLAYER_H - 50);
	

	for (int i = 0; i < 3; i++)
	{
		//this->_hearts[i]->LoadTextureFromFile(HEART_SPRITE_PATH);
		if (i != 0)
		{
			this->_hearts[i]->setPosition(this->_hearts[i - 1]->getPosition().x + 90, 0);
		}
		else
		{
			this->_hearts[i]->setPosition(0, 0);
		}
	}
}


