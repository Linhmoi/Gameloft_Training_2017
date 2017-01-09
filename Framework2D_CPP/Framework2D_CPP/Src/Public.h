#pragma once
#ifndef PUBLIC_H
#define PUBLIC_H

#include "Framework.h"

#define GAME_TITLE_COLOR	{ 243, 158, 18}
#define BTN_TEXT_COLOR		{255, 255, 255}
#define BTN_TEXT_HOVER_COLOR {192, 192, 192};
#define GAME_TITLE_FONT "Resources/Fonts/DeathStar.otf"
#define BTN_TEXT_FONT "Resources/Fonts/Canarsie_Slab_JL.ttf"
#define GAME_TITLE_FONT_SIZE 50
#define BTN_TEXT_FONT_SIZE 30
#define SCORE_TEXT_FONT_SIZE 15
#define GAME_TITLE_W 400
#define GAME_TITLE_H 200
#define BTN_TEXT_W 150
#define BTN_TEXT_H 30
#define MARGIN_TOP 50 //use in menu scene
#define MARGIN_BOTTOM 100 //use in menu scene
#define OFFSET 25 //offset between 2 uielement in menu scene
#define BG_SPRITE_PATH "Resources/Background/SpaceBackground-1.jpg"
#define BG2_SPRITE_PATH "Resources/Background/SpaceBackground-9.jpg"
#define BG3_SPRITE_PATH "Resources/Background/SpaceBackground-8.jpg"

#define BEAM_WIDTH 15
#define BEAM_HEIGHT 25
#define MISSILE_WIDTH 15
#define MISSILE_HEIGHT 25
#define TORPEDO_WIDTH 20
#define TORPEDO_HEIGHT 30
#define BEAM_SPRITE_PATH "Resources/beams_50.png"
#define TORPEDO_SPRITE_PATH "Resources/beams_30.png"
#define MISSILE_SPRITE_PATH "Resources/missile.png"

enum WeaponType
{
	LaserBeam,
	Missiles,
	Torpedoes
};

bool CompareColor(Color a, Color b);
void WaitForSeconds(Uint32);
#endif // !PUBLIC_H

