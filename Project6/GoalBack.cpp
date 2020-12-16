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
	this->goal_backL.setPosition(55, 450);
	this->goal_backL.setScale(-2.f, 2.f);

	//right
	this->goal_backR.setTexture(this->textureBack);
	this->goal_backR.setPosition(1225, 450);
	this->goal_backR.setScale(2.f, 2.f);
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

	this->goalL.setOutlineColor(sf::Color::Green);
	this->goalL.setOutlineThickness(3);
	this->goalL.setFillColor(sf::Color::Transparent);
	this->goalL.setSize(sf::Vector2f(-40.f, 120.f));
	this->goalL.setPosition(this->goal_backL.getPosition().x - 50, this->goal_backL.getPosition().y + 60);
	//target.draw(this->goalL);

	this->goalR.setOutlineColor(sf::Color::Green);
	this->goalR.setOutlineThickness(3);
	this->goalR.setFillColor(sf::Color::Transparent);
	this->goalR.setSize(sf::Vector2f(40.f, 120.f));
	this->goalR.setPosition(this->goal_backR.getPosition().x + 50, this->goal_backR.getPosition().y + 60);
	//target.draw(this->goalR);
}

const sf::FloatRect GoalBack::goalLBounds() const
{
	return this->goalL.getGlobalBounds();
}

const sf::FloatRect GoalBack::goalRBounds() const
{
	return this->goalR.getGlobalBounds();
}
