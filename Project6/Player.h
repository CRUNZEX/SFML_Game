#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, KICK};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//Animation
	short animState;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;

	//Core
	void initVariables();
	void initTexture();
	void initSpite();
	void initAnimation();
	void initPhysics();

	float movementSpeed;

public:
	Player();
	virtual ~Player();
	
	void move(const float dirX, const float dirY);
	
	void update();
	void render(sf::RenderTarget & target);

	void updatePhysics();
	void updateMovement();
	void updateAnimation();
};

