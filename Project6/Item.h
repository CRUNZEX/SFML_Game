#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <time.h>
#include <Windows.h>

#define ITEM_TYPE 2
#define TIME_MIN 1
#define TIME_MAX 5
#define posY_MIN 100
#define posY_MAX 1180

class Item
{
private:
	//Sprite
	sf::Sprite item[ITEM_TYPE];
	sf::Texture itemTexture[ITEM_TYPE];

	sf::Clock timeItem;

	//Random
	bool randomUse = false;

	//Physic
	float velocityMax;
	float velocityMin;
	float acceleration;
	float accelerationJump;
	float drag;
	float gravity;
	float velocityMaxY;

	float movementSpeed;

	//Core
	void initTexture();
	void initSprite();
	void initRandom();
	void initPhysic();

public:
	Item();
	virtual ~Item();

	//Item
	float timeDrop;
	float posX_random;

	//Function
	sf::Vector2f velocity;
	
	//Sprite Function
	const sf::FloatRect getGlobalBoundsItem1() const;
	const sf::Vector2f getPositionItem1() const;
	void setPositionItem1(const float x, const float y);
	
	//Modifier
	void moveItem1(const float dirX, const float dirY);

	void updateMovement();
	void updatePhysic();

	void update();
	void render(sf::RenderTarget& target);
};

