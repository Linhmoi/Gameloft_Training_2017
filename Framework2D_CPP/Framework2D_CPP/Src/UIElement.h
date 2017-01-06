#pragma once
#ifndef UIELEMENT_H
#define UILEEMENT_H

#include "Sprite.h"

class UIElement : public Sprite
{
private:
	Font* _font;
	char* _text;
	Color _color;
	Color _shadedColor;

public:
	enum TextType
	{
		Solid,
		Blended,
		Shaded
	};
	UIElement();
	~UIElement();

	#pragma region Get and Set methods
	Font* getFont();
	char* getText();
	Color getColor();
	Color getShadedColor();
	void setFont(Font*);
	void setText(char*);
	void setColor(Color);
	void setColor(Uint8, Uint8, Uint8);
	void setShadedColor(Color);
	void setShadedColor(Uint8, Uint8, Uint8);
	#pragma endregion

	void LoadFont(char*, int);
	void LoadTextureFromFont(TextType);
	bool CheckCollision(Sprite* src);
};

#endif // 

