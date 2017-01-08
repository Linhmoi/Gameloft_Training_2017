#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Player.h"
#include "Enemy.h"
#include "UIElement.h"
#include "Public.h"
#include <vector>

#define TOP_BOUND -200
#define BOTTOM_BOUND 200
#define LEFT_BOUND 200
#define PLAYER_W 100
#define PLAYER_H 50
#define ENEMY_W 80
#define ENEMY_H 40
#define EXPLOSION_W 80
#define EXPLOSION_H 80
#define STAR_EFFECT_W 80
#define STAR_EFFECT_H 80
#define HEART_W 80
#define HEART_H 80
#define ENEMY_SPRITE_PATH "Resources/SpaceShipPack/A2.png"
#define PLAYER_SPRITE_PATH "Resources/mc.png"
#define HEART_SPRITE_PATH "Resources/heart.png"

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
	UIElement* _txtPause;
	Sprite* _background;
	Sprite* _secondBG;
	int _level;
	int _nEnemies;
	bool _isGameOver;
	bool _isWin;
	bool _isPause;
	int _waitTime;
	int _delay;

public:
	GameController();
	~GameController();

	#pragma region Get and Set methods
	static GameController* getInstance();
	int getLevel();
	int NumberOfEnemies();
	bool IsWin();
	bool IsGameOver();
	#pragma endregion

	void SpawnEnemy(int, int);
	void WinGame();
	void GameOver();
	void PauseGame();
	void ScrollBackground();
	void PlayNextLevel();
	void ReturnToMenu();
	void ExitGame(int, int);
	void RestartLevel(int, int);
	void DestroyByTime();
	void DestroyOnContact();
	void Awake(int, int);
	void Reset(int, int);
};

#endif // !GAME_CONTROLLER_H

