#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

#include"Collider.h"
#include"Platform.h"

enum PLAYER2_ANIMATION_STATES { IDLE2 = 0, MOVING_LEFT2, MOVING_RIGHT2, JUMPING2, FALLING2, KICK2 };

class Player2
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
	float accelerationJump;
	float drag;
	float gravity;
	float velocityMaxY;
	int jumping = 0;

	//Core
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();

	float movementSpeed;


public:
	Player2();
	virtual ~Player2();

	//accessors
	const bool& getAnimSwitch();
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	//modifier
	void setPosition(const float x, const float y);
	void resetVelocityX();
	void resetVelocityY();

	void resetAnimetionTimer();
	void move(const float dirX, const float dirY);

	//functions
	void update();
	void render(sf::RenderTarget& target);

	void updatePhysics();
	void updateMovement();
	void updateAnimation();
};

