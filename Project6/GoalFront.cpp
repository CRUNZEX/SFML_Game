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
	this->goal_frontL.setPosition(55, 440);
	this->goal_frontL.setScale(-2.f, 2.f);

	//right
	this->goal_frontR.setTexture(this->textureFront);
	this->goal_frontR.setPosition(1225, 440);
	this->goal_frontR.setScale(2.f, 2.f);
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

	this->hitboxL.setOutlineColor(sf::Color::White);
	this->hitboxL.setOutlineThickness(3);
	this->hitboxL.setFillColor(sf::Color::Transparent);
	this->hitboxL.setSize(sf::Vector2f(-20.f, 20.f));
	this->hitboxL.setPosition(this->goal_frontL.getPosition().x, this->goal_frontL.getPosition().y);
	target.draw(this->hitboxL);

	sf::CircleShape CircL;
	CircL.setFillColor(sf::Color::Red);
	CircL.setRadius(3.f);
	CircL.setPosition(this->goal_frontL.getPosition());
	target.draw(CircL);

	sf::CircleShape CircR;
	CircR.setFillColor(sf::Color::Red);
	CircR.setRadius(3.f);
	CircR.setPosition(this->goal_frontR.getPosition());
	target.draw(CircR);
}

const sf::FloatRect GoalFront::getCrossbarRBounds() const
{
	return this->hitboxR.getGlobalBounds();
}

const sf::FloatRect GoalFront::getCrossbarLBounds() const
{
	return this->hitboxL.getGlobalBounds();
}
