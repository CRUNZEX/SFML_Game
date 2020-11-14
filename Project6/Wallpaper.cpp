#include "Wallpaper.h"

void Wallpaper::initWallpaper()
{
	this->BGweather = new BGWeather;
}

void Wallpaper::initBGcheer()
{
	this->BGcheer = new BGCheer;
}

void Wallpaper::initBGfield()
{
	this->BGfield = new BGField;
}

Wallpaper::Wallpaper()
{
	this->initBGfield();
	this->initWallpaper();
	this->initBGcheer();
}

Wallpaper::~Wallpaper()
{

}

void Wallpaper::render(sf::RenderTarget& target)
{
	target.draw(this->BGfield->bg);
	target.draw(this->BGweather->bg);
	target.draw(this->BGcheer->bg);
}
