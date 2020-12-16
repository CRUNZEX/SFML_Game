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
	this->hitboxL.setSize(sf::Vector2f(-80.f, 10.f));
	this->hitboxL.setPosition(this->goal_frontL.getPosition().x - 25, this->goal_frontL.getPosition().y + 10);
	target.draw(this->hitboxL);

	this->hitboxR.setOutlineColor(sf::Color::White);
	this->hitboxR.setOutlineThickness(3);
	this->hitboxR.setFillColor(sf::Color::Transparent);
	this->hitboxR.setSize(sf::Vector2f(80.f, 10.f));
	this->hitboxR.setPosition(this->goal_frontR.getPosition().x + 25, this->goal_frontR.getPosition().y + 10);
	target.draw(this->hitboxR);

	this->crossbarL.setOutlineColor(sf::Color::White);
	this->crossbarL.setOutlineThickness(3);
	this->crossbarL.setFillColor(sf::Color::Transparent);
	this->crossbarL.setSize(sf::Vector2f(-40.f, 10.f));
	this->crossbarL.setRotation(-50);
	this->crossbarL.setPosition(this->goal_frontL.getPosition().x - 15, this->goal_frontL.getPosition().y + 10);
	target.draw(this->crossbarL);

	this->crossbarR.setOutlineColor(sf::Color::White);
	this->crossbarR.setOutlineThickness(3);
	this->crossbarR.setFillColor(sf::Color::Transparent);
	this->crossbarR.setSize(sf::Vector2f(40.f, 10.f));
	this->crossbarR.setRotation(50);
	this->crossbarR.setPosition(this->goal_frontR.getPosition().x + 15, this->goal_frontR.getPosition().y + 10);
	target.draw(this->crossbarR);

	sf::CircleShape CircL;
	CircL.setFillColor(sf::Color::Red);
	CircL.setRadius(3.f);
	CircL.setPosition(this->goal_frontL.getPosition());
	//target.draw(CircL);

	sf::CircleShape CircR;
	CircR.setFillColor(sf::Color::Red);
	CircR.setRadius(3.f);
	CircR.setPosition(this->goal_frontR.getPosition());
	//target.draw(CircR);
}

const sf::FloatRect GoalFront::getCrossbarRBounds() const
{
	return this->crossbarR.getGlobalBounds();
}

const sf::FloatRect GoalFront::getCrossbarLBounds() const
{
	return this->crossbarL.getGlobalBounds();
}

const sf::FloatRect GoalFront::getHitboxRBounds() const
{
	return this->hitboxR.getGlobalBounds();
}

const sf::FloatRect GoalFront::getHitboxLBounds() const
{
	return this->hitboxL.getGlobalBounds();
}
