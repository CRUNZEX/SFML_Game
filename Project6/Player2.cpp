#include "Player2.h"

void Player2::initVariables()
{
	this->animState = PLAYER2_ANIMATION_STATES::IDLE2;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player2::initTexture()
{
	if (!this->texture.loadFromFile("Pictures/Player2.png"))
		printf("ERROR:: Picture player can't be load");
}

void Player2::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.f, 1.f);

	this->currentFrame = sf::IntRect(0, 0, 100, 100);

	this->sprite.setPosition(900, 690);

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
	this->accelerationJump = 3.f;
	this->drag = 0.9f;
	this->gravity = 0.6f;
	this->velocityMaxY = 1.f;
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

const int& Player2::HPget() const
{
	return this->hp;
}

const int& Player2::HPgetMax() const
{
	return this->hpMax;
}

void Player2::HPset(const int hp)
{
	this->hp = hp;
}

void Player2::HPlose(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

bool Player2::die()
{
	if (this->hp == 0)
		return true;
	else
		return false;
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

const sf::FloatRect Player2::getHitboxHeadBounds() const
{
	return this->hitboxHead.getGlobalBounds();
}

const sf::FloatRect Player2::getHitboxLBounds() const
{
	return this->hitboxL.getGlobalBounds();
}

const sf::FloatRect Player2::getHitboxRBounds() const
{
	return this->hitboxR.getGlobalBounds();
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
	/*this->velocity.y += dirY * this->accelerationJump;*/

	//limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
	/*if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}*/
}

void Player2::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updatePhysics();
}

void Player2::render(sf::RenderTarget& target)
{
	this->hitboxR.setOutlineColor(sf::Color::White);
	this->hitboxR.setOutlineThickness(3);
	this->hitboxR.setFillColor(sf::Color::Transparent);
	this->hitboxR.setSize(sf::Vector2f(-30.f, 70.f));
	this->hitboxR.setPosition(this->sprite.getPosition().x + 85, this->sprite.getPosition().y + 20);
	target.draw(this->hitboxR);

	this->hitboxL.setFillColor(sf::Color::White);
	this->hitboxL.setOutlineThickness(3);
	this->hitboxL.setFillColor(sf::Color::Transparent);
	this->hitboxL.setSize(sf::Vector2f(30.f, 70.f));
	this->hitboxL.setPosition(this->sprite.getPosition().x + 15, this->sprite.getPosition().y + 20);
	target.draw(this->hitboxL);

	this->hitboxHead.setOutlineColor(sf::Color::White);
	this->hitboxHead.setOutlineThickness(3);
	this->hitboxHead.setFillColor(sf::Color::Transparent);
	this->hitboxHead.setSize(sf::Vector2f(70.f, 10.f));
	this->hitboxHead.setPosition(this->sprite.getPosition().x + 15, this->getPosition().y);
	target.draw(this->hitboxHead);

	target.draw(this->sprite);

	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->sprite.getPosition());
	target.draw(Circ);

	sf::CircleShape CircHitboxL;
	CircHitboxL.setFillColor(sf::Color::Magenta);
	CircHitboxL.setRadius(3.f);
	CircHitboxL.setPosition(this->hitboxL.getPosition());
	target.draw(CircHitboxL);

	sf::CircleShape CircHitboxR;
	CircHitboxR.setFillColor(sf::Color::Magenta);
	CircHitboxR.setRadius(3.f);
	CircHitboxR.setPosition(this->hitboxR.getPosition());
	target.draw(CircHitboxR);
}

void Player2::updatePhysics()
{
	//jumping
	if (this->jumping2 == true && this->gravityBool2 == false)
	{
		if (this->velocity.y < 0)
			this->jumpingUp2 = false;
		if (this->jumpingUp2 == true)
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

	if (this->gravityBool2 == true)
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

void Player2::updateJump()
{

}

void Player2::updateMovement()
{
	this->animState = PLAYER2_ANIMATION_STATES::IDLE2;
	
	//keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		this->keyJ = true;
		this->gravityBool2 = true;
		this->animState = PLAYER2_ANIMATION_STATES::MOVING_LEFT2;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && this->dashTime <= 10)
		{
			this->move(-5.f, 0.f);
			this->dash = true;
		
			this->dashTime++;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		this->keyL = true;
		this->gravityBool2 = true;
		this->animState = PLAYER2_ANIMATION_STATES::MOVING_RIGHT2;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && this->dashTime <= 10)
		{
			this->move(5.f, 0.f);
			this->dash = true;

			this->dashTime++;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
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

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		this->keyJ = false;
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		this->keyL = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		this->animState = PLAYER2_ANIMATION_STATES::KICK2;
		this->kick = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		this->animState = PLAYER2_ANIMATION_STATES::PUNCH2;
		this->punch = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		this->kick = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		this->punch = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && this->jumping2 == false)
	{
		this->jumping2 = true;
		this->jumpingUp2 = true;
		this->gravityBool2 = true;

		this->velocity.y = -30.f;
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
	else if (this->animState == PLAYER2_ANIMATION_STATES::PUNCH2)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.05f)
		{
			this->currentFrame.top = 300.f;
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
