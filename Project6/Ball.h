#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>
#include "Player.h"

class ball
{
private:
	Player* player;

	sf::CircleShape sprite;
	sf::Texture texture;

	//Physics
	float velocityMax;
	float velocityMin;
	float acceleration;
	float dragX;
	float dragY;
	float gravity;
	float velocityMaxY;

	//Core
	void initVariable();
	void initTexture();
	void initsSpite();
	void initPhysics();

	float movementSpeed;

public:
	ball();
	virtual ~ball();
	
	//physics
	sf::Vector2f velocity;
	int ballBounds = 0;
	int ballJump = 0;
	bool ballstart = false;

	//jumping
	bool jumping = false;
	bool jumpingUp = false;
	bool gravityBool = false;
	
	//collision
	int collision = 0;

	//accessors
	const sf::FloatRect getGlobalBoundsBall() const;
	const sf::Vector2f getPositionBall() const;

	//modifier
	void setPositionBall(const float x, const float y);
	void resetVelocityXBall();
	void resetVelocityYBall();

	void move(const float dirX, const float dirY);

	//functions
	void updateBall();
	void renderBall(sf::RenderTarget& target);

	
	void updatePhysicsBall();
	void updateMovementBall();
};

