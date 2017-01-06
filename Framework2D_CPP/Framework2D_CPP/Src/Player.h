#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Framework.h"
#include "Ship.h"

class Player : public Ship
{
private:
	int _score;
public:
	Player();
	~Player();

	bool CheckCollision(Ship*);
};

#endif

