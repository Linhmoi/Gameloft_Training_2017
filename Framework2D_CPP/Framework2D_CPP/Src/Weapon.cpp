#include "Weapon.h"

Weapon::Weapon()
{
	this->_damage = 1;
	this->_velocity = 1;
}

Weapon::~Weapon()
{
}

int Weapon::getWeaponDamage()
{
	return this->_damage;
}

int Weapon::getWeaponVelocity()
{
	return this->_velocity;
}

void Weapon::setWeaponDamage(int damage)
{
	this->_damage = damage;
}

void Weapon::setWeaponVelocity(int velocity)
{
	this->_velocity = velocity;
}

//bool Weapon::CheckCollision(Ship* spr)
//{
//	//int shipHealth = spr->getHealth();
//
//	if (fwIsRectOverlap(&this->_rect, &spr->getRect()))
//	{
//		return true;
//	}
//
//	return false;
//}

bool Weapon::CheckCollision(Sprite* spr)
{
	//int shipHealth = spr->getHealth();

	if (fwIsRectOverlap(&this->_rect, &spr->getRect()))
	{
		return true;
	}

	return false;
}

//void Weapon::Spawn(int x, int y, int w, int h)
//{
//	//int screenW, screenH;
//	//fwGetDisplayMode(screenW, screenH);
//
//	this->Render(x, y, w, h);
//	this->MoveTo(this->_pos.x, 0 - this->_rect.h, 10);
//}
