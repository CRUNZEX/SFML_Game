#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#include "BGWeather.h"
#include "BGCheer.h"
#include "BGField.h"

#include "Goal.h"

class Wallpaper
{
private:
	BGWeather* BGweather;
	BGCheer* BGcheer;
	BGField* BGfield;
	Goal* goal;

	sf::Texture texture;
	sf::Texture bgTexture;

	//Core
	void initWallpaper();
	void initBGcheer();
	void initBGfield();

	void initGoal();

	void initGameState();

public:
	Wallpaper();
	virtual ~Wallpaper();

	//function
	void render(sf::RenderTarget & target);
};

