#include "Framework.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "Sprite.h"
#include "UIElement.h"
#include "Ship.h"
#include "Weapon.h"
#include "Player.h"
#include "MenuScene.h"
#include "LogoScene.h"
#include "LoadingScene.h"
#include "GameScene.h"
#include <iostream>
#include <time.h>
using namespace std;

#define DEF_WIDTH		800
#define DEF_HEIGHT		600
#define DEF_FPS			60
#define PLAYER_SIZE_X	100
#define PLAYER_SIZE_Y	150
#define TEXT_COLOR {243, 155, 18}
#define GAME_TITLE_FONT "Resources/Fonts/DeathStar.otf"


Texture*	gTex1 = NULL;
Rect		gRectTex1;
int gX = 0, gY = 0;

Texture* bg = NULL;
Rect bgRect;
int bgX = 0, bgY = -DEF_HEIGHT;

Texture*	gTex2 = NULL;
Rect		gRectTex2;
Rect		desRect;
int x = DEF_WIDTH / 2;
int y = DEF_HEIGHT - 150;

TTF_Font* mainFont = NULL;
Texture* textTex = NULL;

Texture* beam = NULL;
Rect beamRect;
Point beamPos;

bool isFire = false;
int lastFire = 0;

int originY;

Player sprite;
Sprite spr;
UIElement btn;
MenuScene* menu = new MenuScene(DEF_WIDTH, DEF_HEIGHT);
LogoScene* logo = new LogoScene(DEF_WIDTH, DEF_HEIGHT);
LoadingScene* loading = new LoadingScene(DEF_WIDTH, DEF_HEIGHT);
GameScene* game = new GameScene(DEF_WIDTH, DEF_HEIGHT);

void ScrollBackground(int &firstBgY, int &secondBgY);
void MoveRight(int velocity, int &curPosX);
void MoveLeft(int velocity, int &curPosX);
void MoveDown(int velocity, int &curPosY);
void Animated(Rect &src, Texture* &tex, int frame, int numSprite);
void GenerateBeam(int spawnPosX, int spawnPosY);
void MoveUp(int velocity, int &curPosY);
void CheckFire();

bool Init()
{
	game->Init();
	//logo->Init();
	//loading->Init();
	//menu->Init();
	//spr.LoadTextureFromFile("Resources/mc.png");
	//spr.setPosition(0, 500);
	return true;
}

void Update(float dt)
{
	game->Update();
	//logo->Update();
	//loading->Update();
	//menu->Update();
	//spr.MoveTo(200, 200, 1);
	//SDL_Log("dt = %.03f", dt);
	//cout << "isFire: " << isFire << endl;
	/*ScrollBackground(gY, bgY);*/
}

void Render()
{
	game->Render();
	//logo->Render();
	//loading->Render();
	//menu->Render();
	//spr.Render(50, 50);
	/*bgRect.x = bgX;
	bgRect.y = bgY;
	bgRect.w = DEF_WIDTH;
	bgRect.h = DEF_HEIGHT;

	Rect desGTex;
	desGTex.x = gX;
	desGTex.y = gY;
	desGTex.w = DEF_WIDTH;
	desGTex.h = DEF_HEIGHT;
	fwRenderTexture(gTex1, &gRectTex1, &desGTex);

	fwRenderTexture(bg, NULL, &bgRect);
	
	desRect.x = x;
	desRect.y = y;
	desRect.w = 80;
	desRect.h = 120;

	fwRenderTexture(gTex2, &gRectTex2, &desRect);
	sprite.Render(100, 150);*/
	//spr.Render(DEF_WIDTH - 100, DEF_HEIGHT - 75, 100, 150);

	//if (!sprite.CheckIsRender())
	//{
	//	SDL_Log("IsRender = false");
	//	sprite.Render(100, 150);
	//}
	//else
	//{
	//	SDL_Log("IsRender = true");
	//}

	/*if (!spr.CheckIsRender())
	{
		SDL_Log("spr IsRender = false");
		spr.Render(DEF_WIDTH - 100, DEF_HEIGHT - 75, 100, 150);
	}
	else
	{
		SDL_Log("spr IsRender = true");
	}*/
	//sprite.RenderAnimation(2, 4, 145, 150, 240, 100, 100, 80, 120, 2);
	//SDL_Log("lal lal a");

	/*btn.Render(300, 100);


	if (isFire == true)
	{
		GenerateBeam(x, y);
	}*/

}

void OnKeyDown(int key)
{
	game->OnKeyDown(key);
	//menu->OnKeyDown(key);
	//switch (key)
	//{
	//case SDLK_a: SDL_Log("Key A is Down");
	//	/*sprite.MoveLeft();*/
	//	break;
	//case SDLK_d: SDL_Log("Key D is Down");
	//	/*sprite.MoveRight();*/
	//	break;
	//	case SDLK_SPACE:
	//		/*CheckFire();*/
	//		SDL_Log("Key Space is Down");
	//	break;
	//case SDLK_UP: SDL_Log("Key UP is Down");
	//	break;
	//}
}

void Terminate()
{
	//delete logo;
	//delete menu;
	//delete loading;
	fwDestroyTexture(gTex1);
	fwDestroyTexture(gTex2);
	fwTerminate();
}

void OnKeyUp(int key)
{
	switch (key)
	{
	case SDLK_a:
		SDL_Log("Key A is Up");
		break;
	case SDLK_d:
		SDL_Log("Key D is Up");
		break;
	case SDLK_LEFT: SDL_Log("Key LEFT is Up");
		break;
	case SDLK_UP: SDL_Log("Key UP is Up");
		break;
	}
}

void OnMouseDown()
{
	//menu->OnMouseDown();
	/*int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Log("mouse x: %d", x);
	SDL_Log("mouse y: %d", y);
	SDL_Log("btn pos x: %d", btn.getPosition().x);
	SDL_Log("btn pos y: %d", btn.getPosition().y);
	SDL_Log("btn width: %d", btn.getWidth());
	SDL_Log("btn height: %d", btn.getHeight());

	if (x >= btn.getPosition().x && x <= (btn.getPosition().x + btn.getRect().w) && y >= btn.getPosition().y && y <= (btn.getPosition().y + btn.getRect().h))
	{
		SDL_Log("mouse pressed");
	}*/
}

void OnMouseOver()
{
	//menu->OnMouseOver();
}

void ScrollBackground(int &firstBgY, int &secondBgY)
{
	int originY1 = firstBgY;
	int originY2 = secondBgY;
	int velocity = 2;
	
	MoveDown(velocity, firstBgY);
	MoveDown(velocity, secondBgY);
	/*SDL_Log("gY: %d", firstBgY);
	SDL_Log("bgY: %d", secondBgY);*/
	if (firstBgY >= DEF_HEIGHT)
	{
		firstBgY = -DEF_HEIGHT;
	}

	if (secondBgY >= DEF_HEIGHT)
	{
		secondBgY = -DEF_HEIGHT;
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	fwInit(DEF_WIDTH, DEF_HEIGHT);
	fwSetFPS(DEF_FPS);
	fwRegisterUpdateCallback(Update);
	fwRegisgerRenderCallback(Render);
	fwRegisterOnKeyDownCallback(OnKeyDown);
	fwRegisterOnKeyUpCallback(OnKeyUp);
	fwRegisterOnMouseDownCallback(OnMouseDown);
	fwRegisterOnMouseMotionCallback(OnMouseOver);

	if (Init())
	{
		fwLoop();
	}	

	Terminate();	

	return 0;
}

void MoveLeft(int velocity, int &curPosX)
{
	curPosX -= velocity;

	if (curPosX == 80)
	{
		x += velocity;
	}
}

void MoveRight(int velocity, int &curPosX)
{
	curPosX += velocity;

	if (curPosX == DEF_WIDTH - 80)
	{
		curPosX -= velocity;
	}
}

void MoveDown(int velocity, int &curPosY)
{
	curPosY += velocity;
}

void MoveUp(int velocity, int &curPosY)
{
	curPosY -= velocity;
}

void GenerateBeam(int spawnPosX, int spawnPosY)
{
	Rect destRect;
	destRect.x = spawnPosX + (spawnPosX/2);
	destRect.y = spawnPosX - 150;
	destRect.w = beamRect.w;
	destRect.h = beamRect.h;
	fwRenderTexture(beam, &beamRect, &destRect);
}

void CheckFire()
{
	int fireRate = 0.5;

	if (SDL_GetTicks() > lastFire)
	{
		isFire = true;
		lastFire = SDL_GetTicks() * fireRate;
		return;
	}

	isFire = false;
}

void Animated(Rect &src, Texture* &tex, int startFrame, int numFrames)
{
	Uint32 tick = SDL_GetTicks();
	int frame = (tick / 150) % numFrames + startFrame;
	//int sprite = 2;

	for (int i = startFrame; i < numFrames; ++i)
	{
		src = { frame * 150, 0, 150, 240 };
		Rect dest = { x, y, 80, 120 };
		fwRenderTexture(tex, &src, &dest);
	}
}