#include "Goal.h"

void Goal::initTexture()
{
	if (!this->texture_back.loadFromFile("Pictures/goal_back.png"))
		printf("ERROR::goal_back not be load");
	if (!this->texture_front.loadFromFile("Pictures/goal_front.png"))
		printf("ERROR::goal_front not be load");
}

void Goal::initGoal()
{
	//right
	this->goal_backR.setTexture(this->texture_back);
	this->goal_backR.setPosition(1200, 500);
	this->goal_backR.setScale(1.5f, 1.5f);

	this->goal_frontR.setTexture(this->texture_front);
	this->goal_frontR.setPosition(1200, 490);
	this->goal_frontR.setScale(1.5f, 1.5f);

	//left
	this->goal_backL.setTexture(this->texture_back);
	this->goal_backL.setPosition(100, 500);
	this->goal_backL.setScale(-1.5f, 1.5f);

	this->goal_frontL.setTexture(this->texture_front);
	this->goal_frontL.setPosition(100, 490);
	this->goal_frontL.setScale(-1.5f, 1.5f);
}

Goal::Goal()
{
	this->initTexture();
	this->initGoal();
}

Goal::~Goal()
{
}

void Goal::render(sf::RenderTarget& target)
{
	target.draw(this->goal_backR);
	target.draw(this->goal_frontR);

	target.draw(this->goal_backL);
	target.draw(this->goal_frontL);
}
