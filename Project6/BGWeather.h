#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>
#include<time.h>
#include<Windows.h>

class BGWeather
{
private:
	sf::Texture texture0;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;
	sf::Texture texture6;
	sf::Texture texture7;

	bool randomDraw = false;
	int numPic = 0;

	//Core
	void initTexture();
	void initBG();
	void initRandom();

public:
	BGWeather();
	virtual ~BGWeather();

	sf::Sprite bg;

};

