#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<stdio.h>

class GoalBack
{
private:
	sf::Texture textureBack;

	sf::RectangleShape goalR;
	sf::RectangleShape goalL;

	//Core
	void initTexture();
	void initGoalBack();

public:
	GoalBack();
	virtual ~GoalBack();

	sf::Sprite goal_backR;
	sf::Sprite goal_backL;

	void render(sf::RenderTarget& target);

	//hitbox
	const sf::FloatRect goalLBounds() const;
	const sf::FloatRect goalRBounds() const;
};

