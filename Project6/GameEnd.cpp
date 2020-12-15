#include "GameEnd.h"

void GameEnd::initText()
{
	this->Font.loadFromFile("File/font.ttf");
}

void GameEnd::initMenu()
{
	this->bgTexture.loadFromFile("Pictures/GameEnd.png");
	this->bgSprite.setTexture(this->bgTexture);
}

void GameEnd::initBotton(float width, float height)
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
	this->menu[0].setString("New Match");
	this->menu[0].setPosition(sf::Vector2f(width / 2 - 210.f , height - 120.f));

	//this->menu[1].setString("High Score");
	//this->menu[1].setPosition(sf::Vector2f(100.f, 350.f));

	//this->menu[2].setString("How to Play");
	//this->menu[2].setPosition(sf::Vector2f(100.f, 400.f));

	//this->menu[3].setString("Exit");
	//this->menu[3].setPosition(sf::Vector2f(100.f, 450.f));

	//this->menu[4].setString("63010226 Chanon Temkamolsin");
	//this->menu[4].setPosition(sf::Vector2f(10.f, height - 50.f));
}

GameEnd::GameEnd(float width, float height)
{
	this->initText();
	this->initMenu();
	this->initBotton(width, height);
}

GameEnd::~GameEnd()
{
}

void GameEnd::update(float width, float height)
{
}

void GameEnd::render(sf::RenderWindow& target)
{
	target.draw(this->bgSprite);

	for (int num = 0; num < MAX_NUMBER; num++)
		target.draw(this->menu[num]);
}

const sf::FloatRect GameEnd::botton1() const
{
	return this->menu[0].getGlobalBounds();
}

const sf::FloatRect GameEnd::botton2() const
{
	return this->menu[1].getGlobalBounds();
}

const sf::FloatRect GameEnd::botton3() const
{
	return this->menu[2].getGlobalBounds();
}

const sf::FloatRect GameEnd::botton4() const
{
	return this->menu[3].getGlobalBounds();
}
