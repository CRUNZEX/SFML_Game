#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<stdio.h>

class Goal
{
private:
	sf::Texture texture_back;
	sf::Texture texture_front;

	//core
	void initTexture();
	void initGoal();

public:
	Goal();
	virtual ~Goal();

	sf::Sprite goal_backR;
	sf::Sprite goal_frontR;

	sf::Sprite goal_backL;
	sf::Sprite goal_frontL;

	void render(sf::RenderTarget& target);
};

