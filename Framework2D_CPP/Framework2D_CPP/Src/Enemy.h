#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy : public Ship
{
private:
	int _point;
public:
	Enemy();
	~Enemy();
};

#endif

