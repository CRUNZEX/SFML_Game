#include "Player.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Player1.png"))
		printf("ERROR::Picture player can't be load!");
}

void Player::initSpite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(-1.f, 1.f);

	this->currentFrame = sf::IntRect(0, 0, 100, 100);

	this->sprite.setPosition(300, 690);

	this->sprite.setTextureRect(this->currentFrame);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->accelerationJump = 3.f;
	this->drag = 0.9f;
	this->gravity = 0.6f;
	this->velocityMaxY = 1.f;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSpite();
	this->initAnimation();
	this->initPhysics();

	this->movementSpeed = 5.f;
}

Player::~Player()
{

}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return animationSwitch;
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//acceleration
	this->velocity.x += dirX * this->acceleration;
	//this->velocity.y += dirY * this->accelerationJump;

	//limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
	/*if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		printf("%f", this->velocity.y);
	}*/
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->sprite);

	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->sprite.getPosition());

	target.draw(Circ);
}

void Player::updatePhysics()
{
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
			this->velocity.y += (1.0 * this->gravity);
			if (std::abs(this->velocity.x) > this->velocityMaxY)
				this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		}
	}
	else
		this->velocity.y += (1.0 * this->gravity);	//gravity

	if (this->gravityBool == true)
		this->velocity.y += (1.0 * this->gravity);

	//decceleration
	this->velocity *= (this->drag);

	//limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
	{
		this->velocity.y = 0.f;
	}

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	//Keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->gravityBool = true;
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->gravityBool = true;
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		this->animState = PLAYER_ANIMATION_STATES::KICK;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->jumping == false)
	{
		this->jumping = true;
		this->jumpingUp = true;
		this->gravityBool = true;
		this->velocity.y = -30.f;
	}
	/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, 1.f);
	}*/
}

void Player::updateAnimation()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 200.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT || this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 100.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 200.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::KICK)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFrame.top = 200.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 400.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else
		this->animationTimer.restart();
}
