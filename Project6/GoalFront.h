#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<stdio.h>

class GoalFront
{
private:
	sf::Texture textureFront;

	//Hitbox
	sf::RectangleShape hitboxL;
	sf::RectangleShape hitboxR;

	//Core
	void initTexture();
	void initGoalFront();

public:
	GoalFront();
	virtual ~GoalFront();

	sf::Sprite goal_frontR;
	sf::Sprite goal_frontL;

	void render(sf::RenderTarget& target);
	
	//Hitbox
	const sf::FloatRect getCrossbarRBounds() const;
	const sf::FloatRect getCrossbarLBounds() const;
};

