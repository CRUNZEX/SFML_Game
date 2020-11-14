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

class Wallpaper
{
private:
	BGWeather* BGweather;
	BGCheer* BGcheer;
	BGField* BGfield;

	sf::Texture texture;

	//Core
	void initWallpaper();
	void initBGcheer();
	void initBGfield();

public:
	Wallpaper();
	virtual ~Wallpaper();

	//function
	void render(sf::RenderTarget & target);
};

