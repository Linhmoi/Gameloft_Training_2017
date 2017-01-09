#include "Ship.h"

Ship::Ship()
{
	this->_health = 1;
	this->_velocity = 1;
	this->_type = WeaponType::LaserBeam;
	this->_fireRate = 1;
	this->_nextFire = 0;
	this->_isFire = false;
	//this->_weaponControl = new Beam;
}

Ship::~Ship()
{
	//delete this->_weaponControl;
}

int Ship::getHealth()
{
	return this->_health;
}

int Ship::getVelocity()
{
	return this->_velocity;
}

int Ship::getFireRate()
{
	return this->_fireRate;
}
//
//Weapon* Ship::getWeapon()
//{
//	return this->_weaponControl;
//}

bool Ship::CheckIsFire()
{
	return this->_isFire;
}

WeaponType Ship::getWeaponType()
{
	return this->_type;
}

void Ship::setHealth(int health)
{
	this->_health = health;
}

void Ship::setVelocity(int velocity)
{
	this->_velocity = velocity;
}

void Ship::setFireRate(int fireRate)
{
	this->_fireRate = fireRate;
}

void Ship::LoadWeapon()
{
	if (this->_type == WeaponType::LaserBeam)
	{
		this->_type = WeaponType::Missiles;
		this->_fireRate = 2;
	}
	else
	{
		if (this->_type == WeaponType::Missiles)
		{
			this->_type = WeaponType::Torpedoes;
			this->_fireRate = 3;
		}
		else
		{
			this->_type = WeaponType::LaserBeam;
			this->_fireRate = 1;
		}
	}
}

bool Ship::FireWeapon()
{
	if (SDL_GetTicks() > this->_nextFire)
	{
		this->_nextFire = SDL_GetTicks() + (this->_fireRate * 500);
		this->_isFire = true;
	}
	return this->_isFire;
	//this->_weaponControl->Render(this->_rect.w / 2, this->_rect.h - 50, 50, 80);
	//this->_weaponControl->setPosition(spawnPosX, spawnPosY);
}

void Ship::MoveLeft()
{
	/*SDL_Log("Pos before move left: %d", this->_pos.x);*/
	this->_pos.x -= this->_velocity;
	/*SDL_Log("Pos after move left: %d", this->_pos.x);*/
	if (this->_pos.x <= 0) 
	{
		this->_pos.x += this->_velocity;
	}
}

void Ship::MoveRight(int screenW, int screenH)
{
	this->_pos.x += this->_velocity;

	if (this->_pos.x == screenW - this->_rect.w)
	{
		this->_pos.x -= this->_velocity;
	}
}