#pragma once
#ifndef SHIP_H
#define SHIP_H

#include "Sprite.h"
#include "Public.h"
#include "Torpedo.h"
#include "Beam.h"
#include "Missile.h"

class Ship : public Sprite
{
protected:
	int _velocity;
	int _health;
	//Weapon* _weaponControl;
	bool _isFire;
	int _fireRate;
	int _nextFire;
	WeaponType _type;

public:

	Ship();
	~Ship();

	#pragma region Get and Set methods
	int getVelocity();
	int getHealth();
	int getFireRate();
	int getNextFire();
	bool CheckIsFire();
	WeaponType getWeaponType();
	void setVelocity(int);
	void setHealth(int);
	void setFireRate(int);
	void setNextFire();
	#pragma endregion

	void MoveLeft();
	void MoveRight(int, int);
	void LoadWeapon();
	bool FireWeapon();
	bool CheckCollision(Ship*);
};

#endif

