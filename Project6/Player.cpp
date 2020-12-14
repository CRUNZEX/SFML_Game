#include "Player.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Player1.png"))
		printf("ERROR::Picture player can't be load!");
}

void Player::initSprite()
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
	this->initSprite();
	this->initAnimation();
	this->initPhysics();

	this->movementSpeed = 5.f;
}

Player::~Player()
{

}

void Player::jump()
{
	this->jumping = true;
	this->jumpingUp = true;
	this->gravityBool = true;
}

void Player::jumpBreak()
{
	this->jumping = false;
	this->jumpingUp = false;
	this->gravityBool = false;
}

const int& Player::HPget() const
{
	return this->hp;
}

const int& Player::HPgetMax() const
{
	return this->hpMax;
}

void Player::HPset(const int hp)
{
	this->hp = hp;
}

void Player::HPlose(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

bool Player::die()
{
	if (this->hp == 0)
		return true;
	else
		return false;
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

const sf::FloatRect Player::getHitboxLBounds() const
{
	return this->hitboxL.getGlobalBounds();
}

const sf::FloatRect Player::getHitboxHeadBounds() const
{
	return this->hitboxHead.getGlobalBounds();
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

const sf::FloatRect Player::getHitboxRBounds() const
{
	return this->hitboxR.getGlobalBounds();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget & target)
{
	
	this->hitboxR.setOutlineColor(sf::Color::White);
	this->hitboxR.setOutlineThickness(3);
	this->hitboxR.setFillColor(sf::Color::Transparent);
	this->hitboxR.setSize(sf::Vector2f(-30.f, 70.f));
	this->hitboxR.setPosition(this->sprite.getPosition().x - 15, this->sprite.getPosition().y + 20);
	target.draw(this->hitboxR);

	this->hitboxL.setOutlineColor(sf::Color::White);
	this->hitboxL.setOutlineThickness(3);
	this->hitboxL.setFillColor(sf::Color::Transparent);
	this->hitboxL.setSize(sf::Vector2f(30.f, 70.f));
	this->hitboxL.setPosition(this->sprite.getPosition().x - 85, this->sprite.getPosition().y + 20);
	target.draw(this->hitboxL);

	this->hitboxHead.setOutlineColor(sf::Color::White);
	this->hitboxHead.setOutlineThickness(3);
	this->hitboxHead.setFillColor(sf::Color::Transparent);
	this->hitboxHead.setSize(sf::Vector2f(70.f, 10.f));
	this->hitboxHead.setPosition(this->sprite.getPosition().x - 85, this->sprite.getPosition().y);
	target.draw(this->hitboxHead);


	target.draw(this->sprite);
	
	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->sprite.getPosition());
	target.draw(Circ);
}

void Player::updatePhysics()
{
	//printf("V = %f\n", this->velocity.x);
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
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && this->dashTime <= 10)
		{
			this->move(-5.f, 0.f);
			this->dash = true;

			this->dashTime++;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			this->move(-0.5f, 0.f);

			this->dashTime = 0;
			this->dash = false;
		}
		else
		{
			this->dash = false;
			this->move(-0.5f, 0.f);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->gravityBool = true;
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && this->dashTime <= 10)
		{
			this->move(5.f, 0.f);
			this->dash = true;

			this->dashTime++;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			this->move(0.5f, 0.f);
	
			this->dashTime = 0;
			this->dash = false;
		}
		else
		{
			this->dash = false;
			this->move(0.5f, 0.f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		this->animState = PLAYER_ANIMATION_STATES::KICK;
		this->kick = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->animState = PLAYER_ANIMATION_STATES::PUNCH;
		this->punch = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		this->kick = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->punch = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->jumping == false)
	{
		/*this->jumping = true;
		this->jumpingUp = true;
		this->gravityBool = true;*/
		
		this->jump();

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
	else if (this->animState == PLAYER_ANIMATION_STATES::PUNCH)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFrame.top =
				300.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 200.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else
		this->animationTimer.restart();
}