#include "GameEnd.h"

void GameEnd::initText()
{
	this->Font.loadFromFile("File/font.ttf");
}

void GameEnd::initMenu()
{
	this->bgTexture.loadFromFile("Pictures/GameText.png");
	this->bgSprite.setTexture(this->bgTexture);
}

void GameEnd::initBotton(float width, float height)
{
	//Font Style
	for (int num = 0; num < MAX_NUMBER; num++)
	{
		this->menu[num].setFont(this->Font);
		this->menu[num].setCharacterSize(80);
		this->menu[num].setOutlineColor(sf::Color::Black);
		this->menu[num].setOutlineThickness(3);
	}

	//Text
	this->menu[0].setString("New Match");
	this->menu[0].setFillColor(sf::Color::White);
	this->menu[0].setPosition(sf::Vector2f(width / 2 - 210.f , height - 150.f));

	//score Player1
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setPosition(sf::Vector2f(200.f, height - 200.f));

	//score Player2
	this->menu[2].setFillColor(sf::Color::White);
	this->menu[2].setPosition(sf::Vector2f(width - 250.f, height - 200.f));

	this->menu[3].setString("Draw");
	this->menu[3].setFillColor(sf::Color::Yellow);
	this->menu[3].setPosition(sf::Vector2f(520.f, 100.f));

	//Player 1 
	this->menu[4].setString("Win!");
	this->menu[4].setFillColor(sf::Color::Cyan);
	this->menu[4].setPosition(sf::Vector2f(150.f, 100.f));

	this->menu[5].setString("Lose");
	this->menu[5].setFillColor(sf::Color::Red);
	this->menu[5].setPosition(sf::Vector2f(150.f, 100.f));

	//Player 2
	this->menu[6].setString("Win!");
	this->menu[6].setFillColor(sf::Color::Cyan);
	this->menu[6].setPosition(sf::Vector2f(width - 300.f, 100.f));

	this->menu[7].setString("Lose");
	this->menu[7].setFillColor(sf::Color::Red);
	this->menu[7].setPosition(sf::Vector2f(width - 300.f, 100.f));
}

void GameEnd::initWin()
{
		
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

	for (int num = 0; num < 3; num++)
		target.draw(this->menu[num]);

	if (this->scorePlayer1 < this->scorePlayer2)
	{
		target.draw(this->menu[5]);
		target.draw(this->menu[6]);
	}
	else if (this->scorePlayer1 > this->scorePlayer2)
	{
		target.draw(this->menu[4]);
		target.draw(this->menu[7]);
	}
	else
		target.draw(this->menu[3]);

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
