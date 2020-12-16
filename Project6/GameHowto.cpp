#include "GameHowto.h"

void GameHowTo::initText()
{
	this->Font.loadFromFile("File/font.ttf");
}

void GameHowTo::initMenu()
{
	this->bgTexture.loadFromFile("Pictures/howto.png");
	this->bgSprite.setTexture(this->bgTexture);

	//Player 1
	this->texturePlayer1.loadFromFile("Pictures/Cha01.png");
	this->Player1.setTexture(this->texturePlayer1);
	this->Player1.setScale(-2.f, 2.f);
	this->Player1.setPosition(450, 300);

	//Player 2
	this->texturePlayer2.loadFromFile("Pictures/Cha02.png");
	this->Player2.setTexture(this->texturePlayer2);
	this->Player2.setScale(2.f, 2.f);
	this->Player2.setPosition(800, 300);
}

void GameHowTo::initBotton(float width, float height)
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
	this->menu[0].setString("Back");
	this->menu[0].setPosition(sf::Vector2f(width - 200.f, height - 100.f));

	//this->menu[1].setString("High Score");
	//this->menu[1].setPosition(sf::Vector2f(100.f, 350.f));

	//this->menu[2].setString("How to Play");
	//this->menu[2].setPosition(sf::Vector2f(100.f, 400.f));

	//this->menu[3].setString("Exit");
	//this->menu[3].setPosition(sf::Vector2f(100.f, 450.f));

	//this->menu[4].setString("63010226 Chanon Temkamolsin");
	//this->menu[4].setPosition(sf::Vector2f(10.f, height - 50.f));
}

GameHowTo::GameHowTo(float width, float height)
{
	this->initText();
	this->initMenu();
	this->initBotton(width, height);
}

GameHowTo::~GameHowTo()
{
}

void GameHowTo::update(float width, float height)
{
}

void GameHowTo::render(sf::RenderWindow& target)
{
	target.draw(this->bgSprite);
	//target.draw(this->Player1);
	//target.draw(this->Player2);

	for (int num = 0; num < MAX_NUMBER; num++)
		target.draw(this->menu[num]);
}

const sf::FloatRect GameHowTo::botton1() const
{
	return this->menu[0].getGlobalBounds();
}

const sf::FloatRect GameHowTo::botton2() const
{
	return this->menu[1].getGlobalBounds();
}

const sf::FloatRect GameHowTo::botton3() const
{
	return this->menu[2].getGlobalBounds();
}

const sf::FloatRect GameHowTo::botton4() const
{
	return this->menu[3].getGlobalBounds();
}
