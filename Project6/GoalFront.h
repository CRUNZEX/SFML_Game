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
	sf::RectangleShape crossbarL;
	sf::RectangleShape hitboxR;
	sf::RectangleShape crossbarR;

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

	const sf::FloatRect getHitboxRBounds() const;
	const sf::FloatRect getHitboxLBounds() const;
};

