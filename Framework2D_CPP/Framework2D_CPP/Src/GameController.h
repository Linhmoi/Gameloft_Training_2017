#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Player.h"
#include "Enemy.h"
#include "UIElement.h"
#include <vector>

#define TOP_BOUND -200;
#define BOTTOM_BOUND 200;
#define LEFT_BOUND 200;

class GameController
{
private:
	static GameController* _instance;
	std::vector<Enemy*> _listEnemy;
	std::vector<Weapon*> _listWeapon;
	std::vector<Sprite*> _explosion;
	std::vector<Sprite*> _starEffect;
	Player* _player;
	Sprite* _hearts[3];
	UIElement* _score;
	UIElement* _txtWinGame;
	UIElement* _txtGameOver;
	Sprite* _background;
	Sprite* _secondBG;
	int _level;
	int _nEnemies;
	bool _isGameOver;
	bool _isWin;
	int _waitTime;
	int _delay;

public:
	GameController();
	~GameController();

	#pragma region Get and Set methods
	static GameController* getInstance();
	int getLevel();
	int NumberOfEnemies();
	#pragma endregion

	void SpawnEnemy();
	void WinGame();
	void GameOver();
	void ScrollBackground();
	void PlayNextLevel();
	void ReturnToMenu();
	void ExitGame();
	void RestartLevel();
	void DestroyByTime();
	void DestroyOnContact();
};

#endif // !GAME_CONTROLLER_H

