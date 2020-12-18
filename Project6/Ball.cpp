#include "Ball.h"

void ball::initVariable()
{
	this->player = new Player();
}

void ball::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/ball.png"))
		printf("ERROR::Picture ball can't be load!");
}

void ball::initsSpite()
{
	this->sprite.setRadius(20);
	this->sprite.setTexture(&this->texture);
	this->sprite.setScale(1.f, 1.f);
	this->sprite.setPosition(640, 300);
	this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2.f, this->sprite.getLocalBounds().height / 2.f);
}

void ball::initPhysics()
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 5.f;
	this->dragX = 0.955f;
	this->dragY = 0.9f;
	this->gravity = 1.5f;
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

void ball::resetVelocityXBall()
{
	this->velocity.x = 0.f;
}

void ball::resetVelocityYBall()
{
	this->velocity.y = 0.f;
}

void ball::move(const float dirX, const float dirY)
{
	this->sprite.rotate(this->velocity.x * 10.f);
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//collision
	if (this->collision == 1)
		this->velocity = -this->velocity;

	//acceletion
	this->velocity.x += dirX * this->acceleration;

	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void ball::updateBall()
{
	this->updateMovementBall();
	this->updatePhysicsBall();
}

void ball::renderBall(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->sprite.getPosition());
	target.draw(Circ);
}

void ball::updatePhysicsBall()
{
	//printf("x : %f	y : %f\n", this->velocity.x, this->velocity.y);

	//this->rotation = this->velocity.x;

	//printf("%d\n", this->rotation);
	//this->sprite.setRotation(this->rotation);

	//jumping
	if (this->jumping == true && this->gravityBool == false)
	{
		if (this->velocity.y < 0)
			this->jumpingUp = false;
		if (this->jumpingUp == true)
			this->velocity.y -= 1.f;
		else
		{
			//gravity
			this->velocity.y += 1.0 * this->gravity;
			if (std::abs(this->velocity.x) > this->velocityMaxY)
				this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		}
	}
	else
		this->velocity.y += (1.0 * this->gravity);

	if (this->gravityBool == true)
		this->velocity.y += (1.0 * this->gravity);

	//collision
	if (this->collision == 1)
		this->velocity.x = -(this->velocity.x + 2.f);

	//decceleration
	this->velocity.x *= this->dragX;
	this->velocity.y *= this->dragY;

	//limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void ball::updateMovementBall()
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
	//{
	//	this->move(-1.f, 0.f);
	//	/*this->velocity.y = -30.f;*/
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
	//{
	//	this->move(1.f, 0.f);
	//}
}
