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
	bool animationSwitch;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

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
	
	//accessors
	const bool& getAnimSwitch();
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	//modifier
	void setPosition(const float x, const float y);
	void resetVelocityY();

	void resetAnimationTimer();
	void move(const float dirX, const float dirY);
	
	//functions
	void update();
	void render(sf::RenderTarget & target);

	void updatePhysics();
	void updateMovement();
	void updateAnimation();
};

