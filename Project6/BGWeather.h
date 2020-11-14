#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>
#include<time.h>
#include<Windows.h>

class BGWeather
{
private:
	sf::Texture texture;

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
	
	void update();
	void render(sf::RenderTarget& target);
};

