#include "Wallpaper.h"

void Wallpaper::random()
{
	srand(time(NULL));
	printf("%d", rand());
}

void Wallpaper::initTexture()
{

}

void Wallpaper::initWallpaper()
{
	this->BGweather = new BGWeather;
}

Wallpaper::Wallpaper()
{
	this->initWallpaper();
}

Wallpaper::~Wallpaper()
{

}

void Wallpaper::update()
{

}

void Wallpaper::render(sf::RenderTarget& target)
{
	target.draw(this->BGweather->bg);
}
