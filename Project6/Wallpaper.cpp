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

void Wallpaper::initGoal()
{
	this->goal = new Goal();
}

void Wallpaper::initGameState()
{
	this->bgTexture.loadFromFile("Pictures/GameEnd.png");
}

Wallpaper::Wallpaper()
{
	this->initBGfield();
	this->initWallpaper();
	this->initBGcheer();

	this->initGoal();
}

Wallpaper::~Wallpaper()
{

}

void Wallpaper::render(sf::RenderTarget& target)
{
	target.draw(this->BGfield->bg);
	target.draw(this->BGweather->bg);
	target.draw(this->BGcheer->bg);

	//target.draw(this->goal->goal_backR);
	//target.draw(this->goal->goal_frontR);
}
