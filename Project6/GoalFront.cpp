#include "GoalFront.h"

void GoalFront::initTexture()
{
	if (!this->textureFront.loadFromFile("Pictures/goal_front.png"))
		printf("ERROR::goal_front not be load");
}

void GoalFront::initGoalFront()
{
	//left
	this->goal_frontL.setTexture(this->textureFront);
	this->goal_frontL.setPosition(100, 500);
	this->goal_frontL.setScale(-1.5f, 1.5f);

	//right
	this->goal_frontR.setTexture(this->textureFront);
	this->goal_frontR.setPosition(1200, 500);
	this->goal_frontR.setScale(1.5f, 1.5f);
}

GoalFront::GoalFront()
{
	this->initTexture();
	this->initGoalFront();
}

GoalFront::~GoalFront()
{
}

void GoalFront::render(sf::RenderTarget& target)
{
	target.draw(this->goal_frontL);
	target.draw(this->goal_frontR);
}
