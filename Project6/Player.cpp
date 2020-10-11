#include "Player.h"


void Player::initVariables()
{
	this->moving = false;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Rab.png"))
	{
		printf("EROOR::Rab.png");
	}
}

void Player::initSpite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(.5f, .5f);

	this->currentFrame = sf::IntRect(0, 0, 200, 238);

	this->sprite.setTextureRect(this->currentFrame);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSpite();
	this->initAnimation();

	this->movementSpeed = 100.f;
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->sprite);
}

void Player::updateMovement()
{
	this->moving = false;

	//Keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(1.f, 0.f);
		this->moving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, 1.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -1.f);
		this->moving = true;
	}
}

void Player::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		if (this->moving == false) // idle animation
		{
			this->currentFrame.left += 200.f;
			if (this->currentFrame.left >= 800.f)
				this->currentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}
