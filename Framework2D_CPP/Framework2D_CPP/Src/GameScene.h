#pragma once
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "UIElement.h"
#include <iostream>
#include <vector>

class GameScene : public Scene
{
private:
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

public:
	GameScene();
	GameScene(int, int);
	~GameScene();

	#pragma region Get and Set methods
	int getLevel();
	int NumberOfEnemies();
	#pragma endregion

	void Init();
	void Update();
	void Render();
	void Destroy();

	void SpawnEnemy();
	void WinGame();
	void GameOver();
	void ScrollBackground();
	void LoadNextLevel();
	void ReturnToMenu();
	void ExitGame();
	void RestartLevel();
	void DestroyByTime();
	void DestroyOnContact();

	void OnMouseDown();
	void OnMouseOver();
	void OnKeyDown(int);
};

#endif // !GAME_SCENE_H
