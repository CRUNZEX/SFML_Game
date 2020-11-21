#include "GoalBack.h"

void GoalBack::initTexture()
{
	if (!this->textureBack.loadFromFile("Pictures/goal_back.png"))
		printf("ERROR::goal_back not be load");
}

void GoalBack::initGoalBack()
{
	//left
	this->goal_backL.setTexture(this->textureBack);
	this->goal_backL.setPosition(100, 500);
	this->goal_backL.setScale(-1.5f, 1.5f);

	//right
	this->goal_backR.setTexture(this->textureBack);
	this->goal_backR.setPosition(1200, 500);
	this->goal_backR.setScale(1.5f, 1.5f);
}

GoalBack::GoalBack()
{
	this->initTexture();
	this->initGoalBack();
}

GoalBack::~GoalBack()
{
}

void GoalBack::render(sf::RenderTarget& target)
{
	target.draw(this->goal_backL);
	target.draw(this->goal_backR);
}
