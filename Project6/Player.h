#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

#include"Collider.h"
#include"Platform.h"

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, KICK, PUNCH};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//Hitbox
	sf::RectangleShape hitboxL;
	sf::RectangleShape hitboxR;
	sf::RectangleShape hitboxHead;

	//Animation
	short animState;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;
	bool animationSwitch;

	//Physics
	float velocityMax;
	float velocityMin;
	float acceleration;
	float accelerationJump;
	float drag;
	float gravity;
	float velocityMaxY;

	//HP
	int hpMax;
	int hp;

	//Core
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();

	float movementSpeed;

	sf::RectangleShape body;

public:
	Player();
	virtual ~Player();
	
	//physics
	sf::Vector2f velocity;
	bool kick = false;
	bool punch = false;

	bool dash = false;
	bool dashPress = false;
	bool dashDo = false;
	int dashTime = 0;

	bool collisionPlayer = false;

	//jump
	void jump();
	void jumpBreak();
	bool jumping = false;
	bool jumpingUp = false;
	bool gravityBool = false;

	//HP
	const int& HPget() const;
	const int& HPgetMax() const;

	void HPset(const int hp);
	void HPlose(const int value);
	bool die();

	//accessors
	const bool& getAnimSwitch();
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	//Hitbox
	const sf::FloatRect getHitboxHeadBounds() const;
	const sf::FloatRect getHitboxLBounds() const;
	const sf::FloatRect getHitboxRBounds() const;

	//modifier
	void setPosition(const float x, const float y);
	void resetVelocityX();
	void resetVelocityY();

	void resetAnimationTimer();
	void move(const float dirX, const float dirY);
	
	//functions
	void update();
	void render(sf::RenderTarget & target);

	void updatePhysics();
	void updateMovement();
	void updateAnimation();


	Collider GetCollider() { return Collider(body); }
};

