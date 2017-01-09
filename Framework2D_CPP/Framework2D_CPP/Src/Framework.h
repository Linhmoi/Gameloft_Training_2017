#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_audio.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

typedef SDL_Texture			Texture;
typedef SDL_Rect			Rect;
typedef SDL_Point			Point;
typedef TTF_Font			Font;
typedef Mix_Chunk			Sound;
typedef Mix_Music			Music;
typedef SDL_Surface			Surface;
typedef SDL_Color			Color;
typedef SDL_BlendMode		BlendMode;

bool fwInit(int widht, int height);
void fwSetFPS(int fps);
void fwLoop();

void fwRegisterUpdateCallback(void(*fnUpdate)(float dt));
void fwRegisgerRenderCallback(void(*fnRender)());
void fwRegisterOnKeyDownCallback(void(*fnKeyDown)(int key));
void fwRegisterOnKeyUpCallback(void(*fnKeyUp)(int key));
void fwRegisterOnMouseDownCallback(void(*fnMouseDown)());
void fwRegisterOnMouseMotionCallback(void(*fnMouseMotion)());

bool fwLoadTexture(const char* file, Texture*& tex, int& width, int& height);
void fwDestroyTexture(Texture* tex);
void fwRenderTexture(Texture* tex, Rect* src, Rect* des);
void fwRotateTexture(Texture* tex, Rect* src, Rect* des, double angle);
void fwCreateTextureFromSurface(Texture* &tex, Surface* surface);
void fwSetTextureColor();
void fwUpdateRenderer();

void fwCloseFont(Font* font);
bool fwGetDisplayMode(int &w, int &h);

void fwTerminate();

bool fwIsRectOverlap(const Rect* r1, const Rect* r2);

