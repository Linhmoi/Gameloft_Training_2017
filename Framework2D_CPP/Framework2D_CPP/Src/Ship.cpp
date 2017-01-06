#include "Ship.h"

Ship::Ship()
{
	this->_health = 1;
	this->_velocity = 10;
	this->_weaponControl = new Beam;
}

Ship::~Ship()
{
	delete this->_weaponControl;
}

int Ship::getHealth()
{
	return this->_health;
}

int Ship::getVelocity()
{
	return this->_velocity;
}

void Ship::setHealth(int health)
{
	this->_health = health;
}

void Ship::setVelocity(int velocity)
{
	this->_velocity = velocity;
}

void Ship::LoadWeapon(Ship::WeaponType type)
{
	delete this->_weaponControl;
	//this->_weaponControl = new Beam;
	switch (type)
	{
	case Ship::WeaponType::Beams:
		this->_weaponControl = new Beam;
		break;
	case Ship::WeaponType::Missiles:
		this->_weaponControl = new Missile;
		break;
	case Ship::WeaponType::Torpedoes:
		this->_weaponControl = new Torpedo;
		break;
	}
}

void Ship::FireWeapon()
{
	this->_weaponControl->Render(this->_rect.w / 2, this->_rect.h - 50, 50, 80);
}

void Ship::MoveLeft()
{
	SDL_Log("Pos before move left: %d", this->_pos.x);
	this->_pos.x -= this->_velocity;
	SDL_Log("Pos after move left: %d", this->_pos.x);
	if (this->_pos.x == 0 + this->_rect.w)
	{
		this->_pos.x += this->_velocity;
	}
}

void Ship::MoveRight()
{
	int screenW, screenH;
	fwGetDisplayMode(screenW, screenH);

	this->_pos.x += this->_velocity;

	if (this->_pos.x == screenW - this->_rect.w)
	{
		this->_pos.x -= this->_velocity;
	}
}