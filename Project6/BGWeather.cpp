#include "BGWeather.h"

void BGWeather::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/weather_0.png") && this->randomDraw == 0)
		printf("ERROR::BGweater not be load");
	else if (!this->texture.loadFromFile("Pictures/weather_1.png") && this->randomDraw == 1)
		printf("ERROR::BGweater not be load");
}

void BGWeather::initBG()
{
	this->bg.setTexture(this->texture);
	this->bg.setScale(2.67f, 2.67f);
}

void BGWeather::initRandom()
{
	srand(time(NULL));
	if (this->randomDraw == false)
	{
		this->numPic = rand() % 2;
		printf("numPic : %d", this->numPic);
		this->randomDraw = true;
	}

}

BGWeather::BGWeather()
{
	this->initRandom();
	this->initTexture();
	this->initBG();
}

BGWeather::~BGWeather()
{

}

void BGWeather::update()
{
}
