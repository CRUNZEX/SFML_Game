#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//Animation
	sf::IntRect currentFrame;
	sf::Clock animationTimer;

	//Movement
	bool moving;

	//Core
	void initVariables();
	void initTexture();
	void initSpite();
	void initAnimation();

	float movementSpeed;

public:
	Player();
	virtual ~Player();
	
	void move(const float dirX, const float dirY);
	
	void update();
	void render(sf::RenderTarget & target);

	void updateMovement();
	void updateAnimation();
};

