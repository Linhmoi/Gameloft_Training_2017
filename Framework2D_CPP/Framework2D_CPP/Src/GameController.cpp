#include "GameController.h"
using namespace std;

GameController* GameController::_instance;

GameController::GameController()
{
	this->_background = new Sprite();
	this->_secondBG = new Sprite();
	this->_player = new Player();
	this->_txtScore = new UIElement();
	this->_txtWinGame = new UIElement();
	this->_txtGameOver = new UIElement();
	this->_txtPause = new UIElement();
	this->_isWin = false;
	this->_isGameOver = false;
	this->_isPause = false;
	this->_level = 1;
	this->_nEnemies = 2;
	this->_waitTime = 3;
	this->_delay = 1;
	this->_effectDuration = 1;
	this->_isCollied = false;
	this->_nKilledEnemies = 0;
	this->_score = 0;

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i] = new Sprite();
	}
}

GameController::~GameController()
{
}

GameController* GameController::getInstance()
{
	if (!_instance)
	{
		_instance = new GameController();
	}
	return _instance;
}

int GameController::getLevel()
{
	return this->_level;
}

int GameController::NumberOfEnemies()
{
	return this->_nEnemies;
}

bool GameController::IsWin()
{
	return this->_isWin;
}

bool GameController::IsGameOver()
{
	return this->_isGameOver;
}

bool GameController::IsPause()
{
	return this->_isPause;
}

void GameController::Awake(int screenW, int screenH)
{
	this->_player->LoadTextureFromFile(PLAYER_SPRITE_PATH);
	this->_background->LoadTextureFromFile(BG3_SPRITE_PATH);
	this->_secondBG->LoadTextureFromFile(BG3_SPRITE_PATH);
	this->_txtGameOver->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_txtWinGame->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_txtScore->LoadFont(BTN_TEXT_FONT, SCORE_TEXT_FONT_SIZE);
	this->_txtPause->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);

	this->_txtGameOver->setColor(BTN_TEXT_COLOR);
	this->_txtWinGame->setColor(BTN_TEXT_COLOR);
	this->_txtScore->setColor(BTN_TEXT_COLOR);
	this->_txtPause->setColor(BTN_TEXT_COLOR);

	this->_txtGameOver->setText("Game Over!\nPress Esc to exit or R to restart");
	this->_txtWinGame->setText("You win!\nPress Esc to exit or Enter to continue or R to restart");
	this->_txtScore->setText("000000");
	this->_txtPause->setText("Paused! Press U to resume");

	this->_txtGameOver->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtWinGame->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtScore->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtPause->LoadTextureFromFont(UIElement::TextType::Solid);

	int centerX = (screenW / 2) - (BTN_TEXT_W / 2);
	int centerY = (screenH / 2) - (BTN_TEXT_H / 2);
	this->_txtGameOver->setPosition(centerX, centerY);
	this->_txtWinGame->setPosition(centerX, centerY);
	this->_txtPause->setPosition(centerX, centerY);
	this->_txtScore->setPosition(screenW - BTN_TEXT_W, 0);
	this->_player->setPosition(centerX, screenH - PLAYER_HEIGHT - 50);
	this->_background->setPosition(0, 0);
	this->_secondBG->setPosition(0, -screenH);

	for (int i = 0; i < 3; i++)
	{
		this->_hearts[i]->LoadTextureFromFile(HEART_SPRITE_PATH);
		if (i != 0)
		{
			this->_hearts[i]->setPosition(this->_hearts[i - 1]->getPosition().x + 55, 0);
		}
		else
		{
			this->_hearts[i]->setPosition(0, 0);
		}
	}
}

void GameController::SpawnEnemy(int screenW, int screenH)
{
	int rangeX = screenW + 1 - (ENEMY_WIDTH); // random X from 0 to screenW - <enemy_sprite_width>
	int rangeY = (0 - TOP_BOUND + 1);
	int index = this->_listEnemy.size();

	if (this->_listEnemy.size() < this->_nEnemies)
	{
		this->_listEnemy.push_back(new Enemy());
		this->_listEnemy[index]->setPosition((rand() % rangeX), (rand() % rangeY) + TOP_BOUND);
		this->_listEnemy[index]->LoadTextureFromFile(ENEMY_SPRITE_PATH);
		//this->_listEnemy[index]->Render(ENEMY_W, ENEMY_H);
	}
}

void GameController::SpawnBullet()
{
	switch (this->_player->getWeaponType())
	{
	case WeaponType::LaserBeam:
		this->_listWeapon.push_back(new Beam());
		this->_listWeapon.back()->LoadTextureFromFile(BEAM_SPRITE_PATH);
		break;
	case WeaponType::Missiles:
		this->_listWeapon.push_back(new Missile());
		this->_listWeapon.back()->LoadTextureFromFile(MISSILE_SPRITE_PATH);
		break;
	case WeaponType::Torpedoes:
		this->_listWeapon.push_back(new Torpedo());
		this->_listWeapon.back()->LoadTextureFromFile(TORPEDO_SPRITE_PATH);
		break;
	}

	Point playerPos = this->_player->getPosition();
	this->_listWeapon.back()->setPosition(playerPos.x + (PLAYER_WIDTH / 2), playerPos.y - 20);
}

void GameController::WinGame()
{
	this->_isWin = true;
	this->_txtWinGame->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::GameOver()
{
	this->_isGameOver = true;
	this->_txtGameOver->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::PauseGame()
{
	this->_isPause = true;
	this->_txtPause->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void GameController::PlayNextLevel(int screenW, int screenH)
{
	this->_level++; //Increase level
	this->_nEnemies = this->_level * 10;
	this->Reset(screenW, screenH);
}

void GameController::ExitGame(int screenW, int screenH)
{

}

void GameController::RestartLevel(int screenW, int screenH)
{
	this->_nEnemies = this->_level * 10;
	this->Reset(screenW, screenH);
}

//Summary: Reset scene to original state
void GameController::Reset(int screenW, int screenH)
{
	this->_explosion.clear();
	this->_starEffect.clear();
	this->_listEnemy.clear();
	this->_listWeapon.clear();
	this->_txtScore->setText("000000");
	this->_isWin = false;
	this->_isPause = false;
	this->_isGameOver = false;

	int centerX = (screenW / 2) - (BTN_TEXT_W / 2);
	//int centerY = (screenH / 2) - (BTN_TEXT_H / 2);
	this->_player->setPosition(centerX, screenH - PLAYER_H - 50);
	

	for (int i = 0; i < 3; i++)
	{
		//this->_hearts[i]->LoadTextureFromFile(HEART_SPRITE_PATH);
		if (i != 0)
		{
			this->_hearts[i]->setPosition(this->_hearts[i - 1]->getPosition().x + 90, 0);
		}
		else
		{
			this->_hearts[i]->setPosition(0, 0);
		}
	}
}

void GameController::ScrollBackground(int screenW, int screenH)
{
	this->_background->MoveTo(0, screenH, 1);
	this->_secondBG->MoveTo(0, screenH, 1);

	if (this->_background->getPosition().y >= screenH)
	{
		this->_background->setPosition(0, -screenH);
	}

	if (this->_secondBG->getPosition().y >= screenH)
	{
		this->_secondBG->setPosition(0, -screenH);
	}
}

void GameController::ReturnToMenu()
{
	//return to menu when press button
}

void GameController::DetectCollision()
{
	for (int i = 0; i < this->_listWeapon.size(); i++)
	{
		//SDL_Log("weapon [%d] rect x: %d; rect y: %d; rect w: %d; rect h: %d", i, this->_listWeapon.at(i)->getRect().x, this->_listWeapon.at(i)->getRect().y, this->_listWeapon.at(i)->getRect().w, this->_listWeapon.at(i)->getRect().h);
		for (int j = 0; j < this->_listEnemy.size(); j++)
		{
			//("enemy[%d] rect x: %d; rect y: %d; rect w: %d; rect h: %d", j, this->_listEnemy.at(i)->getRect().x, this->_listEnemy.at(i)->getRect().y, this->_listEnemy.at(i)->getRect().w, this->_listEnemy.at(i)->getRect().h);
			//if(this->_listWeapon.at(i)->CheckCollision(_listEnemy.at(j)));
			if(fwIsRectOverlap(&this->_listEnemy.at(j)->getRect(), &this->_listWeapon.at(i)->getRect()))
			{
				//SDL_Log("Collision");
				this->_explosion.push_back(new Sprite());
				this->_explosion.back()->LoadTextureFromFile(EXPLOSION_SPRITE_PATH);
				this->_explosion.back()->setPosition(this->_listEnemy.at(j)->getPosition());
				int shipHealth = this->_listEnemy.at(j)->getHealth();
				shipHealth -= this->_listWeapon.at(i)->getWeaponDamage();
				

				if (shipHealth <= 0)
				{
					//this->_listEnemy.erase(this->_listEnemy.begin() + j);
					this->_listEnemy.at(j)->setIsCollied(true);
				}
				this->_listWeapon.at(i)->setIsCollied(true);
				this->_score += 30;
				this->_txtScore->setText(std::to_string(this->_score));
				this->_txtScore->LoadTextureFromFont(UIElement::TextType::Solid);
			}
		}
	}
}

void GameController::DestroyByTime()
{
	for (int i = 0; i < this->_explosion.size(); i++)
	{
		if (SDL_GetTicks() >= (this->_explosion.at(i)->getStartTime() + this->_effectDuration))
		{
			this->_explosion.erase(this->_explosion.begin() + i);
		}
	}

	for (int i = 0; i < this->_starEffect.size(); i++)
	{
		if (SDL_GetTicks() >= (this->_starEffect.at(i)->getStartTime() + this->_effectDuration))
		{
			this->_starEffect.erase(this->_starEffect.begin() + i);
		}
	}
}

void GameController::Swap(Ship* a, Ship* b)
{
	Ship temp = *a;
	*a = *b;
	*b = temp;
}

void GameController::Swap(Weapon* a, Weapon* b)
{
	Weapon temp = *a;
	*a = *b;
	*b = temp;
}

void GameController::RenderPlayer()
{
	this->_player->Render(PLAYER_WIDTH, PLAYER_HEIGHT);
}

void GameController::RenderEnemy()
{
	for (int i = 0; i < this->_listEnemy.size(); i++)
	{
		this->_listEnemy.at(i)->Render(ENEMY_WIDTH, ENEMY_WIDTH);
	}
}

void GameController::RenderEffect(int screenW, int screenH)
{
	int rangeX = screenW + 1 - (STAR_EFFECT_W / 2);
	int rangeY = screenH + 1 - (STAR_EFFECT_H / 2);
	this->_starEffect.push_back(new Sprite);
	this->_starEffect.back()->LoadTextureFromFile("");
	this->_starEffect.back()->setPosition(rand() % rangeX, rand() % rangeY);

	this->_starEffect.back()->RenderAnimation(0, 10, 50, 0, 0, 0, 0, 0);
}

void GameController::RenderExplosion()
{
	for (int i = 0; i < this->_explosion.size(); i++)
	{
		this->_explosion.at(i)->RenderAnimation(0, 20, 100,100, 100, 50, 50, 2);
	}
}

void GameController::RenderBackground(bool isFirstRun, int screenW, int screenH)
{
	this->_background->Render(screenW, screenH);
	this->_secondBG->Render(screenW, screenH);
	if (isFirstRun)
	{
		this->_secondBG->Rotate(180);
	}
}

void GameController::RenderUI()
{
	if (!this->_isWin && !this->_isGameOver)
	{
		this->_txtScore->Render(BTN_TEXT_W, BTN_TEXT_H);
		for (int i = 0; i < 3; i++)
		{
			if (this->_hearts[i]->CheckIsRender())
			{
				this->_hearts[i]->Render(HEART_W, HEART_H);
			}
		}
	}
	else
	{
		if (this->_isWin)
		{
			this->_txtWinGame->Render(BTN_TEXT_W, BTN_TEXT_H);
		}
		else
		{
			this->_txtGameOver->Render(BTN_TEXT_W, BTN_TEXT_H);
		}
	}

	if (this->_isPause)
	{
		this->_txtPause->Render(BTN_TEXT_W, BTN_TEXT_H);
	}
}

void GameController::RenderBullet()
{
	for (int i = 0; i < this->_listWeapon.size(); i++)
	{
		this->_listWeapon.at(i)->Render(BEAM_WIDTH, BEAM_HEIGHT);
	}
}

void GameController::OnKeyDown(int key, int screenW, int screenH)
{
	switch (key)
	{
	case SDLK_a: // Move left
		this->_player->MoveLeft();
		break;
	case SDLK_d: // Move right
		this->_player->MoveRight(screenW, screenH);
		break;
	case SDLK_w: // Fire weapon
		/*SDL_Log("W pressed");*/
		if (this->_player->FireWeapon())
		{
			/*SDL_Log("Fire");*/
			this->SpawnBullet();
		}
		break;
	case SDLK_x: // Switch weapon
		this->_player->LoadWeapon();
		break;
	case SDLK_u: // Unpause
		this->_isPause = false;
		break;
	case SDLK_KP_ENTER: // Play next
		this->PlayNextLevel(screenW, screenH);
		break;
	case SDLK_ESCAPE: // Exit game
		break;
	}
}

void GameController::MoveBullet(int screenW, int screenH)
{
	for (int i = 0; i < _listWeapon.size(); i++)
	{
		this->_listWeapon.at(i)->MoveTo(this->_listWeapon.at(i)->getPosition().x , -BEAM_HEIGHT, this->_listWeapon.at(i)->getWeaponVelocity());
	}
}

void GameController::MoveEnemy(int screenW, int screenH)
{
	int rangeX = (rand() % (screenW + screenW + 1)) - screenW;
	SDL_Log("rangeX: %d", rangeX);
	if (rangeX < 0)
	{
		rangeX = 0;
	}

	for (int i = 0; i < _listEnemy.size(); i++)
	{
		this->_listEnemy.at(i)->MoveTo(rangeX, screenH + RANGE, this->_listEnemy.at(i)->getVelocity());
	}
}

void GameController::DestroyWhenOutOfScreen(int screenW, int screenH)
{
	//SDL_Log("Before, bullet size: %d", _listWeapon.size());
	//SDL_Log("Before, enemy size: %d", _listEnemy.size());

	for (int i = 0; i < this->_listEnemy.size(); i++)
	{
		if (this->_listEnemy.at(i)->isOutOfScreen(screenW, screenH))
		{
			this->_listEnemy.erase(this->_listEnemy.begin() + i);
		}
	}

	for (int j = 0; j < this->_listWeapon.size(); j++)
	{
		if (this->_listWeapon.at(j)->isOutOfScreen(screenW, screenH))
		{
			this->_listWeapon.erase(this->_listWeapon.begin() + j);
		}
	}
}

void GameController::DestroyCollisionObjects()
{
	for (int i = 0; i < this->_listWeapon.size(); i++)
	{
		if (this->_listWeapon.at(i)->CheckIsCollied())
		{
			this->_listWeapon.erase(this->_listWeapon.begin() + i);
		}
		//this->_listWeapon.erase(this->_listEnemy.begin() + i);
	}

	for (int j = 0; j < this->_listEnemy.size(); j++)
	{
		if (this->_listEnemy.at(j)->CheckIsCollied())
		{
			this->_listEnemy.erase(this->_listEnemy.begin() + j);
		}
	}
}


