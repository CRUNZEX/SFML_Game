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

	sf::Texture texture;

	void random();

	//Core
	void initTexture();
	void initWallpaper();

public:
	Wallpaper();
	virtual ~Wallpaper();

	//function
	void update();
	void render(sf::RenderTarget & target);
};

