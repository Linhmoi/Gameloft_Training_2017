#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include "Sprite.h"

class Weapon : public Sprite
{
protected:
	int _damage;
	int _velocity;

public:
	Weapon();
	~Weapon();

	#pragma region Get and Set methods
	int getWeaponDamage();
	int getWeaponVelocity();
	void setWeaponDamage(int);
	void setWeaponVelocity(int);
	#pragma endregion

	void Spawn(int, int, int, int);
	bool CheckCollision(Sprite*);
};

#endif

