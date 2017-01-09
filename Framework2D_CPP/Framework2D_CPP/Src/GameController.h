#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Player.h"
#include "Enemy.h"
#include "UIElement.h"
#include "Public.h"
#include "Beam.h"
#include "Missile.h"
#include "Torpedo.h"
#include <vector>

#define TOP_BOUND -100
#define BOTTOM_BOUND 200
#define LEFT_BOUND 200
#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 50
#define ENEMY_WIDTH 80
#define ENEMY_HEIGHT 40
#define EXPLOSION_W 80
#define EXPLOSION_H 80
#define STAR_EFFECT_W 80
#define STAR_EFFECT_H 80
#define HEART_W 50
#define HEART_H 50
#define SCORE_W 100
#define SCORE_H 40
#define ENEMY_SPRITE_PATH "Resources/SpaceShipsPack/A2.png"
#define PLAYER_SPRITE_PATH "Resources/mc.png"
#define HEART_SPRITE_PATH "Resources/heart.png"
#define EXPLOSION_SPRITE_PATH "Resources/lvxdmali.png"

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
	UIElement* _txtScore;
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
	int _effectDuration;
	bool _isCollied;
	int _nKilledEnemies;
	int _score;

public:
	GameController();
	~GameController();

	#pragma region Get and Set methods
	static GameController* getInstance();
	int getLevel();
	int NumberOfEnemies();
	bool IsWin();
	bool IsGameOver();
	bool IsPause();
	#pragma endregion

	void Awake(int, int); // Init GameController
	void Reset(int, int); // Reset to original

	void SpawnEnemy(int, int);
	void SpawnEffect(int, int);
	void SpawnBullet();

	void MoveBullet(int, int);
	void MoveEnemy(int, int);

	void WinGame();
	void GameOver();
	void PauseGame();
	void ScrollBackground(int, int);
	void PlayNextLevel(int, int);
	void ReturnToMenu();
	void ExitGame(int, int);
	void RestartLevel(int, int);

	void DetectCollision(); // Destroy On Collision

	void DestroyByTime(); // Destroy effect and explosion after _affectDuration seconds
	void DestroyCollisionObjects(); // Destroy object that collied with other
	void DestroyWhenOutOfScreen(int, int);

	void Swap(Ship*, Ship*); // Swap element position in listEnemy
	void Swap(Weapon*, Weapon*); // Swap element position in listWeapon

	void RenderPlayer();
	void RenderEnemy();
	void RenderEffect(int, int);
	void RenderExplosion();
	void RenderBullet();
	void RenderUI();
	void RenderBackground(bool, int, int);

	void OnKeyDown(int, int, int);
};

#endif // !GAME_CONTROLLER_H

