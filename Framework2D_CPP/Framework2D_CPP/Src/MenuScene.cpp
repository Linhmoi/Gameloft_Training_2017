#include "MenuScene.h"

MenuScene::MenuScene()
{
	this->_background = new Sprite;
	this->_secondBackground = new Sprite;
	this->_gameTitle = new UIElement;
	this->_btnPlay = new UIElement;
	this->_btnHelp = new UIElement;
	this->_btnAbout = new UIElement;
	this->_btnExit = new UIElement;
	this->_txtAbout = new UIElement;
	this->_txtHelp = new UIElement;
	this->_index = 2;
	this->_isAboutOpen = false;
	this->_isHelpOpen = false;
}

MenuScene::MenuScene(int w, int h) : Scene(w, h)
{
	this->_background = new Sprite;
	this->_secondBackground = new Sprite;
	this->_gameTitle = new UIElement;
	this->_btnPlay = new UIElement;
	this->_btnHelp = new UIElement;
	this->_btnAbout = new UIElement;
	this->_btnExit = new UIElement;
	this->_txtAbout = new UIElement;
	this->_txtHelp = new UIElement;
	this->_index = 2;
	this->_isAboutOpen = false;
	this->_isHelpOpen = false;
}

MenuScene::~MenuScene()
{
	this->Destroy();
}

void MenuScene::Init()
{
	this->_background->LoadTextureFromFile(BG_SPRITE_PATH);
	this->_secondBackground->LoadTextureFromFile(BG_SPRITE_PATH);
	this->_gameTitle->LoadFont(GAME_TITLE_FONT, GAME_TITLE_FONT_SIZE);
	this->_btnPlay->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnHelp->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnAbout->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_btnExit->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_txtAbout->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);
	this->_txtHelp->LoadFont(BTN_TEXT_FONT, BTN_TEXT_FONT_SIZE);

	this->_gameTitle->setColor(GAME_TITLE_COLOR);
	this->_btnPlay->setColor(BTN_TEXT_COLOR);
	this->_btnExit->setColor(BTN_TEXT_COLOR);
	this->_btnHelp->setColor(BTN_TEXT_COLOR);
	this->_btnAbout->setColor(BTN_TEXT_COLOR);
	this->_txtAbout->setColor(BTN_TEXT_COLOR);
	this->_txtHelp->setColor(BTN_TEXT_COLOR);

	this->_gameTitle->setText("Star Fighter");
	this->_btnPlay->setText("Play");
	this->_btnAbout->setText("About");
	this->_btnHelp->setText("Help");
	this->_btnExit->setText("Exit");
	this->_txtAbout->setText("Made by Shell");
	this->_txtHelp->setText("Tutorial for dummy");

	this->_gameTitle->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnPlay->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnAbout->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnHelp->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_btnExit->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtAbout->LoadTextureFromFont(UIElement::TextType::Solid);
	this->_txtHelp->LoadTextureFromFont(UIElement::TextType::Solid);

	int posX = (this->_screenW / 2) - (GAME_TITLE_W / 2);
	int posY = MARGIN_TOP;
	int centerX = (this->_screenW / 2) - (BTN_TEXT_W / 2);
	int centerY = (this->_screenH / 2) - (BTN_TEXT_H / 2);

	this->_gameTitle->setPosition(posX, posY);
	this->_btnPlay->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), posY + GAME_TITLE_H + OFFSET);
	this->_btnHelp->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnPlay->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_btnAbout->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnHelp->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_btnExit->setPosition(posX + (GAME_TITLE_W / 2) - (BTN_TEXT_W / 2), this->_btnAbout->getPosition().y + BTN_TEXT_H + OFFSET);
	this->_background->setPosition(0, 0);
	this->_secondBackground->setPosition(0, -this->_screenH);
	this->_txtAbout->setPosition(centerX, centerY);
	this->_txtHelp->setPosition(centerX, centerY);
	
}

void MenuScene::Update()
{
	this->ScrollBackground();
}

void MenuScene::Render()
{
	this->_background->Render(this->_screenW, this->_screenH);
	this->_secondBackground->Render(this->_screenW, this->_screenH);
	if (this->isFirstRun)
	{
		this->_secondBackground->Rotate(180);
	}

	if (!this->_isAboutOpen && !this->_isHelpOpen)
	{
		this->_gameTitle->Render(GAME_TITLE_W, GAME_TITLE_H);
		this->_btnPlay->Render(BTN_TEXT_W, BTN_TEXT_H);
		this->_btnHelp->Render(BTN_TEXT_W, BTN_TEXT_H);
		this->_btnAbout->Render(BTN_TEXT_W, BTN_TEXT_H);
		this->_btnExit->Render(BTN_TEXT_W, BTN_TEXT_H);
	}
	else
	{
		if (this->_isAboutOpen)
		{
			this->_txtAbout->Render(BTN_TEXT_W, BTN_TEXT_H);
		}
		else
		{
			this->_txtHelp->Render(BTN_TEXT_W, BTN_TEXT_H);
		}
	}
	
}

void MenuScene::Destroy()
{
	delete this->_background;
	delete this->_secondBackground;
	delete this->_gameTitle;
	delete this->_btnPlay;
	delete this->_btnAbout;
	delete this->_btnExit;
	delete this->_btnHelp;
	delete this->_btnExit;
	delete this->_txtAbout;
	delete this->_txtHelp;
}

void MenuScene::ScrollBackground()
{
	this->_background->MoveTo(0, this->_screenH, 1);
	this->_secondBackground->MoveTo(0, this->_screenH, 1);

	if (this->_background->getPosition().y >= this->_screenH)
	{
		this->_background->setPosition(0, -this->_screenH);
	}

	if (this->_secondBackground->getPosition().y >= this->_screenH)
	{
		this->_secondBackground->setPosition(0, -this->_screenH);
	}
}

void MenuScene::OnMouseDown()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (x >= this->_btnPlay->getPosition().x && x <= (this->_btnPlay->getPosition().x + BTN_TEXT_W) && y >= this->_btnPlay->getPosition().y && y <= (this->_btnPlay->getPosition().y + BTN_TEXT_H))
	{
		//load GameScene
	}

	if (x >= this->_btnAbout->getPosition().x && x <= (this->_btnAbout->getPosition().x + BTN_TEXT_W) && y >= this->_btnAbout->getPosition().y && y <= (this->_btnAbout->getPosition().y + BTN_TEXT_H))
	{
		//Show _txtAbout
		this->HideMenu();
		this->_txtAbout->setIsRender(true);
		this->_isAboutOpen = true;
	}

	if (x >= this->_btnHelp->getPosition().x && x <= (this->_btnHelp->getPosition().x + BTN_TEXT_W) && y >= this->_btnHelp->getPosition().y && y <= (this->_btnHelp->getPosition().y + BTN_TEXT_H))
	{
		//Show _txtHelp
		this->HideMenu();
		this->_txtHelp->setIsRender(true);
		this->_isHelpOpen = true;
	}

	if (x >= this->_btnExit->getPosition().x && x <= (this->_btnExit->getPosition().x + BTN_TEXT_W) && y >= this->_btnExit->getPosition().y && y <= (this->_btnExit->getPosition().y + BTN_TEXT_H))
	{
		//Exit game
	}
}

void MenuScene::OnMouseOver()
{
	bool isInside = false;
	int x, y;
	SDL_GetMouseState(&x, &y);

	Color normal = BTN_TEXT_COLOR;
	Color hover = BTN_TEXT_HOVER_COLOR;

	if (x >= this->_btnPlay->getPosition().x && x <= (this->_btnPlay->getPosition().x + BTN_TEXT_W) && y >= this->_btnPlay->getPosition().y && y <= (this->_btnPlay->getPosition().y + BTN_TEXT_H))
	{
		isInside = true;
		this->_btnPlay->setColor(hover);
		this->_btnPlay->LoadTextureFromFont(UIElement::TextType::Solid);
	}

	if (x >= this->_btnAbout->getPosition().x && x <= (this->_btnAbout->getPosition().x + BTN_TEXT_W) && y >= this->_btnAbout->getPosition().y && y <= (this->_btnAbout->getPosition().y + BTN_TEXT_H))
	{
		isInside = true;
		this->_btnAbout->setColor(hover);
		this->_btnAbout->LoadTextureFromFont(UIElement::TextType::Solid);
	}

	if (x >= this->_btnHelp->getPosition().x && x <= (this->_btnHelp->getPosition().x + BTN_TEXT_W) && y >= this->_btnHelp->getPosition().y && y <= (this->_btnHelp->getPosition().y + BTN_TEXT_H))
	{
		isInside = true;
		this->_btnHelp->setColor(hover);
		this->_btnHelp->LoadTextureFromFont(UIElement::TextType::Solid);
	}

	if (x >= this->_btnExit->getPosition().x && x <= (this->_btnExit->getPosition().x + BTN_TEXT_W) && y >= this->_btnExit->getPosition().y && y <= (this->_btnExit->getPosition().y + BTN_TEXT_H))
	{
		isInside = true;
		this->_btnExit->setColor(hover);
		this->_btnExit->LoadTextureFromFont(UIElement::TextType::Solid);
	}

	if (!isInside)
	{
		this->_btnPlay->setColor(BTN_TEXT_COLOR);
		this->_btnExit->setColor(BTN_TEXT_COLOR);
		this->_btnHelp->setColor(BTN_TEXT_COLOR);
		this->_btnAbout->setColor(BTN_TEXT_COLOR);

		this->_btnPlay->LoadTextureFromFont(UIElement::TextType::Solid);
		this->_btnAbout->LoadTextureFromFont(UIElement::TextType::Solid);
		this->_btnHelp->LoadTextureFromFont(UIElement::TextType::Solid);
		this->_btnExit->LoadTextureFromFont(UIElement::TextType::Solid);
	}
}

void MenuScene::OnKeyDown(int key)
{
	switch (key)
	{
	case SDLK_ESCAPE:
		break;
	case SDLK_r:
		this->_isAboutOpen = false;
		this->_isHelpOpen = false;
		this->ShowMenu();
		break;
	}
}

void MenuScene::AboutPanel()
{
	this->_txtAbout->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void MenuScene::HelpPanel()
{
	this->_txtHelp->Render(BTN_TEXT_W, BTN_TEXT_H);
}

void MenuScene::HideMenu()
{
	this->_btnPlay->setIsRender(false);
	this->_btnAbout->setIsRender(false);
	this->_btnExit->setIsRender(false);
	this->_btnHelp->setIsRender(false);
	this->_gameTitle->setIsRender(false);
}

void MenuScene::ShowMenu()
{
	this->_btnPlay->setIsRender(true);
	this->_btnAbout->setIsRender(true);
	this->_btnExit->setIsRender(true);
	this->_btnHelp->setIsRender(true);
	this->_gameTitle->setIsRender(true);
	this->_txtAbout->setIsRender(false);
	this->_txtHelp->setIsRender(false);
}