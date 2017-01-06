#include "Player.h"



Player::Player()
{
	this->_velocity = 15;
	this->_health = 3;
	this->_tag = "Player";
}


Player::~Player()
{
}

bool Player::CheckCollision(Ship* ship)
{
	int shipHealth = ship->getHealth();

	if (SDL_HasIntersection(&this->_rect, &ship->getRect()))
	{
		if (ship->getTag() == "Enemy")
		{
			this->_health--;
			shipHealth--;
			ship->setHealth(shipHealth);
		}

		if (shipHealth <= 0)
		{
			delete ship;
		}

		return true;
	}
	return false;
}
