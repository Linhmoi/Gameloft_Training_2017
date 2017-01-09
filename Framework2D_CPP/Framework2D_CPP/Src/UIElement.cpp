#include "UIElement.h"



UIElement::UIElement()
{
	_text = "";
	_color = { 0, 0, 0 };
	_shadedColor = { 0 , 0, 0 };
}

UIElement::~UIElement()
{
	fwDestroyTexture(this->_tex);
	fwCloseFont(this->_font);
}

Font* UIElement::getFont()
{
	return this->_font;
}

std::string UIElement::getText()
{
	return this->_text;
}

Color UIElement::getColor()
{
	return this->_color;
}

Color UIElement::getShadedColor()
{
	return this->_shadedColor;
}

void UIElement::setFont(Font* font)
{
	this->_font = font;
}

void UIElement::setText(std::string text)
{
	this->_text = text;
}

void UIElement::setColor(Color color)
{
	this->_color = color;
}

void UIElement::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	this->_color = { r, g, b };
}

void UIElement::setShadedColor(Color color)
{
	this->_color = color;
}

void UIElement::setShadedColor(Uint8 r, Uint8 g, Uint8 b)
{
	this->_color = { r, g, b };
}

void UIElement::LoadFont(char* path, int size)
{
	this->_font = TTF_OpenFont(path, size);
}

void UIElement::LoadTextureFromFont(UIElement::TextType type)
{
	Surface* surface = NULL;
	switch (type)
	{
	case TextType::Blended:
		surface = TTF_RenderText_Blended(this->_font, this->_text.c_str(), this->_color);
		SDL_Log("Blended");
		break;
	case TextType::Shaded:
		surface = TTF_RenderText_Shaded(this->_font, this->_text.c_str(), this->_color, this->_shadedColor);
		SDL_Log("Shaded");
		break;
	default:
		surface = TTF_RenderText_Solid(this->_font, this->_text.c_str(), this->_color);
		SDL_Log("Solid");
		break;
	}

	fwCreateTextureFromSurface(this->_tex, surface);
	SDL_Log("After switch");
	TTF_SizeText(this->_font, this->_text.c_str(), &this->_w, &this->_h);
	SDL_Log("After set size");
}

bool UIElement::CheckCollision(Sprite* spr)
{
	return false;
}