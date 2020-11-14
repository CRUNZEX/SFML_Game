#include "BGWeather.h"

void BGWeather::initTexture()
{
	if (!this->texture0.loadFromFile("Pictures/weather_0.png"))
		printf("ERROR::BGweater_0 not be load");
	if (!this->texture1.loadFromFile("Pictures/weather_1.png"))
		printf("ERROR::BGweater_1 not be load");
	if (!this->texture2.loadFromFile("Pictures/weather_2.png"))
		printf("ERROR::BGweater_2 not be load");
	if (!this->texture3.loadFromFile("Pictures/weather_3.png"))
		printf("ERROR::BGweater_3 not be load");
	if (!this->texture4.loadFromFile("Pictures/weather_4.png"))
		printf("ERROR::BGweater_4 not be load");
	if (!this->texture5.loadFromFile("Pictures/weather_5.png"))
		printf("ERROR::BGweater_5 not be load");
	if (!this->texture6.loadFromFile("Pictures/weather_6.png"))
		printf("ERROR::BGweater_6 not be load");
	if (!this->texture7.loadFromFile("Pictures/weather_7.png"))
		printf("ERROR::BGweater_7 not be load");
}

void BGWeather::initBG()
{
	switch (this->numPic)
	{
	case 0:
		this->bg.setTexture(this->texture0);
		break;
	case 1:
		this->bg.setTexture(this->texture1);
		break;
	case 2:
		this->bg.setTexture(this->texture2);
		break;
	case 3:
		this->bg.setTexture(this->texture3);
		break;
	case 4:
		this->bg.setTexture(this->texture4);
		break;
	case 5:
		this->bg.setTexture(this->texture5);
		break;
	case 6:
		this->bg.setTexture(this->texture6);
		break;
	case 7:
		this->bg.setTexture(this->texture7);
		break;

	default:
		break;
	}

	/*if (this->numPic == 0)
		this->bg.setTexture(this->texture);
	else if (this->numPic == 1)
		this->bg.setTexture(this->texture2);*/

	this->bg.setScale(2.67f, 2.67f);
	this->bg.setPosition(0, 0);
}

void BGWeather::initRandom()
{
	srand(time(NULL));
	if (this->randomDraw == false)
	{
		this->numPic = rand() % 8;
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
