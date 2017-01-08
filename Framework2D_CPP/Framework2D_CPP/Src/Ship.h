#pragma once
#ifndef SHIP_H
#define SHIP_H

#include "Sprite.h"
#include "Beam.h"
#include "Missile.h"
#include "Torpedo.h"

class Ship : public Sprite
{
protected:
	int _velocity;
	int _health;
	Weapon* _weaponControl;

public:
	enum WeaponType
	{
		Beams,
		Missiles,
		Torpedoes
	};

	Ship();
	~Ship();

	#pragma region Get and Set methods
	int getVelocity();
	int getHealth();
	void setVelocity(int);
	void setHealth(int);
	#pragma endregion

	void MoveLeft();
	void MoveRight(int, int);
	void LoadWeapon(WeaponType);
	void FireWeapon();
	bool CheckCollision(Ship*);
};

#endif

