#include "Player2.h"

void Player2::initVariables()
{
	this->animState = PLAYER2_ANIMATION_STATES::IDLE2;
}

void Player2::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Player1.png"))
		printf("ERROR:: Picture player can't be load");
}

void Player2::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(-1.f, 1.f);

	this->currentFrame = sf::IntRect(0, 0, 100, 100);

	this->sprite.setPosition(300, 960);

	this->sprite.setTextureRect(this->currentFrame);
}

void Player2::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player2::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->accelerationJump = 5.f;
	this->drag = 0.9;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

Player2::Player2()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->initPhysics();

	this->movementSpeed = 5.f;
}

Player2::~Player2()
{
}

const bool& Player2::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return animationSwitch;
}

const sf::FloatRect Player2::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player2::getPosition() const
{
	return this->sprite.getPosition();
}

void Player2::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player2::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player2::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player2::resetAnimetionTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player2::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//acceleration
	this->velocity.x += dirX * this->acceleration;
	this->velocity.y += dirY * this->accelerationJump;

	//limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
	if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
}

void Player2::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updatePhysics();
}

void Player2::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->sprite.getPosition());

	target.draw(Circ);
}

void Player2::updatePhysics()
{
	//gravity
	this->velocity.y += (1.0 * this->gravity);
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		this->jumping = 0;
	}

	//decceleration
	this->velocity *= (this->drag);

	//limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
	{
		this->velocity.y = 0.f;
		this->jumping = 0;
	}

	this->sprite.move(this->velocity);
}

void Player2::updateMovement()
{
	this->animState = PLAYER2_ANIMATION_STATES::IDLE2;
	
	//keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER2_ANIMATION_STATES::MOVING_LEFT2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER2_ANIMATION_STATES::MOVING_RIGHT2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		this->animState = PLAYER2_ANIMATION_STATES::KICK2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && this->jumping == 0)
	{
		this->move(0.f, -3.f);
		this->jumping = 1;
	}
}

void Player2::updateAnimation()
{
	if (this->animState == PLAYER2_ANIMATION_STATES::IDLE2)
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
	else if (this->animState == PLAYER2_ANIMATION_STATES::MOVING_RIGHT2 || this->animState == PLAYER2_ANIMATION_STATES::MOVING_LEFT2)
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
	else if (this->animState == PLAYER2_ANIMATION_STATES::KICK2)
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
