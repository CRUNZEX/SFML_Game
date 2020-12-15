#include "Mainmenu.h"

void Mainmenu::initText()
{
	this->Font.loadFromFile("File/font.ttf");
}

void Mainmenu::initMenu()
{
	this->bgTexture.loadFromFile("Pictures/bgMenu.png");
	this->bgSprite.setTexture(this->bgTexture);
}

void Mainmenu::initBotton(float width, float height)
{
	//Font Style
	for (int num = 0; num < MAX_NUMBER; num++)
	{
		this->menu[num].setFont(this->Font);
		(num == 0) ? this->menu[0].setCharacterSize(80) : this->menu[num].setCharacterSize(40);
		this->menu[num].setFillColor(sf::Color::White);
		this->menu[num].setOutlineColor(sf::Color::Black);
		this->menu[num].setOutlineThickness(3);
	}

	//Text
	this->menu[0].setString("Play");
	this->menu[0].setPosition(sf::Vector2f(100.f, 250.f));

	this->menu[1].setString("High Score");
	this->menu[1].setPosition(sf::Vector2f(100.f, 350.f));

	this->menu[2].setString("How to Play");
	this->menu[2].setPosition(sf::Vector2f(100.f, 400.f));

	this->menu[3].setString("Exit");
	this->menu[3].setPosition(sf::Vector2f(100.f, 450.f));

	this->menu[4].setString("63010226 Chanon Temkamolsin");
	this->menu[4].setPosition(sf::Vector2f(10.f, height - 50.f));
}

Mainmenu::Mainmenu(float width, float height)
{
	this->initText();
	this->initMenu();
	this->initBotton(width, height);
}

Mainmenu::~Mainmenu()
{
}

void Mainmenu::update(float width, float height)
{
}

void Mainmenu::render(sf::RenderWindow& target)
{
	target.draw(this->bgSprite);

	for (int num = 0; num < MAX_NUMBER; num++)
		target.draw(this->menu[num]);
}

const sf::FloatRect Mainmenu::botton1() const
{
	return this->menu[0].getGlobalBounds();
}

const sf::FloatRect Mainmenu::botton2() const
{
	return this->menu[1].getGlobalBounds();
}

const sf::FloatRect Mainmenu::botton3() const
{
	return this->menu[2].getGlobalBounds();
}

const sf::FloatRect Mainmenu::botton4() const
{
	return this->menu[3].getGlobalBounds();
}
