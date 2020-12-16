#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include<string>
#include<sstream>
#include<iostream>
#include<stdio.h>

using namespace std;

#define MAX_NUMBER 8

class GameEnd
{
private:
	//Font
	sf::Font Font;


	//Texture
	sf::Texture bgTexture;
	sf::Texture scoreTexture;
	sf::Texture goalTexture;

	//Sprite
	sf::Sprite bgSprite;
	sf::Sprite scoreSprite;
	sf::Sprite goalSprite;

	//Core
	void initText();
	void initMenu();
	void initBotton(float width, float height);
	void initWin();

public:
	GameEnd(float width, float height);
	virtual ~GameEnd();

	void update(float width, float height);

	void render(sf::RenderWindow& target);

	//Text
	sf::Text menu[MAX_NUMBER];

	//Score
	int scorePlayer1 = 0;
	int scorePlayer2 = 0;

	const sf::FloatRect	botton1() const;
	const sf::FloatRect botton2() const;
	const sf::FloatRect botton3() const;
	const sf::FloatRect botton4() const;
};