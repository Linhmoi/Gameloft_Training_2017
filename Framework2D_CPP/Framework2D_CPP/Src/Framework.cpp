#include "Framework.h"

SDL_Window*		gWindow		= NULL;
SDL_Renderer*	gRenderer	= NULL;
Uint32			gFPS		= 0;
Uint32			gFrameTime	= 0;
Uint32			gDeltaTime	= 0;

void (*gFnUpdate)(float)	= NULL;
void (*gFnRender)()			= NULL;
void (*gFnKeyDown)(int)		= NULL;
void (*gFnKeyUp)(int)		= NULL;
void (*gFnMouseDown)()		= NULL;
void (*gFnMouseMotion)()	= NULL;

bool fwInit(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL Init failed - %d", SDL_GetError());
		return false;
	}

	gWindow = SDL_CreateWindow("Framework 2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (gWindow == NULL)
	{
		SDL_Log("SDL create window failed - %d", SDL_GetError());
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		SDL_Log("SDL create renderer failed - %d", SDL_GetError());
		return false;
	}

	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags)
	{	
		SDL_Log("IMG_Init: %s\n", IMG_GetError());
		return false;
	}

	if (TTF_Init() == -1)
	{
		SDL_Log("TTF_Init: %s\n", TTF_GetError());
	}

	return true;
}

void fwSetFPS(int fps)
{
	gFPS = fps;
	gFrameTime = 1000 / gFPS;
	gDeltaTime = gFrameTime;
}

void fwLoop()
{
	bool isRunning = true;
	SDL_Event e;

	while (isRunning)
	{
		Uint32 startTime = SDL_GetTicks();

		while (SDL_PollEvent(&e) != 0)
        {
			switch (e.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				gFnKeyDown(e.key.keysym.sym);
				break;
			case SDL_KEYUP:
				gFnKeyUp(e.key.keysym.sym);
				break;
			case SDL_MOUSEBUTTONDOWN:
				gFnMouseDown();
				break;
			case SDL_MOUSEMOTION:
				gFnMouseMotion();
				break;
			}
        }

		if (gFnUpdate != NULL)
		{
			gFnUpdate(gDeltaTime / 1000.0f);
		}
			
		
		if (gFnRender != NULL)
		{
			SDL_RenderClear(gRenderer);
			gFnRender();
			SDL_RenderPresent(gRenderer);
		}
				
		gDeltaTime = SDL_GetTicks() - startTime;
		int sleepTime = gFrameTime - gDeltaTime;

		if (sleepTime > 0)
		{
			SDL_Delay(sleepTime);
			gDeltaTime += sleepTime;
		}
	}
}

void fwRegisterUpdateCallback(void(*fnUpdate)(float dt))
{
	gFnUpdate = fnUpdate;
}

void fwRegisgerRenderCallback(void(*fnRender)())
{
	gFnRender = fnRender;
}

void fwRegisterOnKeyDownCallback(void(*fnKeyDown)(int key))
{
	gFnKeyDown = fnKeyDown;
}

void fwRegisterOnKeyUpCallback(void(*fnKeyUp)(int key))
{
	gFnKeyUp = fnKeyUp;
}

void fwRegisterOnMouseDownCallback(void(*fnMouseDown)())
{
	gFnMouseDown = fnMouseDown;
}

void fwRegisterOnMouseMotionCallback(void(*fnMouseMotion)())
{
	gFnMouseMotion = fnMouseMotion;
}

bool fwLoadTexture(const char* file, Texture*& tex, int& width, int& height)
{
	tex = IMG_LoadTexture(gRenderer, file);
	if (tex == NULL)
	{
		SDL_Log("Texture load failed - File: %s", file);
		return false;
	}

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	return true;
}

void fwDestroyTexture(Texture* tex)
{
	SDL_DestroyTexture(tex);
}

void fwRenderTexture(Texture* tex, Rect* src, Rect* des)
{
	SDL_RenderCopy(gRenderer, tex, src, des);
}

void fwRotateTexture(Texture* tex, Rect* src, Rect* des, double angle)
{
	SDL_RenderCopyEx(gRenderer, tex, src, des, angle, NULL, SDL_FLIP_HORIZONTAL);
}

void fwCreateTextureFromSurface(Texture* &tex, Surface* surface)
{
	tex = SDL_CreateTextureFromSurface(gRenderer, surface);
	SDL_FreeSurface(surface);
}

void fwTerminate()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool fwIsRectOverlap(const Rect* r1, const Rect* r2)
{
	SDL_Log("r1->x: %d; r1->y: %d; r1->w: %d; r1->h: %d", r1->x, r1->y, r1->w, r1->h);
	SDL_Log("r2->x: %d; r2->y: %d; r2->w: %d; r2->h: %d", r2->x, r2->y, r2->w, r2->h);
	return r1->x < (r2->x + r2->w) && (r1->x + r1->w) > r2->x &&
			r1->y < (r2->y + r2->h) && (r1->y + r1->h) > r2->y;
}

void fwUpdateRenderer()
{
	SDL_RenderPresent(gRenderer);
}

void fwCloseFont(Font* font)
{
	TTF_CloseFont(font);
	//font = NULL;
}

bool fwGetDisplayMode(int &w, int &h)
{
	SDL_DisplayMode dm;

	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
	{
		SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
		return false;
	}

	w = dm.w;
	h = dm.h;

	return true;
}