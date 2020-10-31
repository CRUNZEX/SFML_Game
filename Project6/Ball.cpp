#include "Ball.h"

void ball::initVariable()
{
}

void ball::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/ball.png"))
		printf("ERROR::Picture ball can't be load!");
}

void ball::initsSpite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.5f, 0.5f);
}

void ball::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.9f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

ball::ball()
{
	this->initVariable();
	this->initTexture();
	this->initsSpite();
	this->initPhysics();

	this->movementSpeed = 5.f;
}

ball::~ball()
{
}

const sf::FloatRect ball::getGlobalBoundsBall() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f ball::getPositionBall() const
{
	return this->sprite.getPosition();
}

void ball::setPositionBall(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void ball::resetVelocityYBall()
{
	this->velocity.y = 0.f;
}

void ball::updateBall()
{
	this->updateMovementBall();
	this->updatePhysicsBall();
}

void ball::renderBall(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void ball::updatePhysicsBall()
{
	//gravity
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//decceleration
	this->velocity *= this->drag;

	//limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void ball::updateMovementBall()
{
}
