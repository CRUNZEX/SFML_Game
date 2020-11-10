#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class ball
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
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

