#include "Item.h"

void Item::initTexture()
{
	this->itemTexture[0].loadFromFile("Pictures/dragon_fire.png");
}

void Item::initSprite()
{
	this->item[0].setTexture(this->itemTexture[0]);
	this->item[0].setScale(0.05f, 0.05f);
}

void Item::initRandom()
{
	srand(time(NULL));
	if (this->randomUse == false)
	{
		this->timeDrop = (rand() % (TIME_MAX - TIME_MIN)) + TIME_MIN;
		this->posX_random = (rand() % (posY_MAX - posY_MIN) + posY_MIN);
		printf("%f\n", this->posX_random);
		this->randomUse = true;
	}
}

void Item::initPhysic()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->accelerationJump = 3.f;
	this->drag = 0.9f;
	this->gravity = 1.5f;
	this->velocityMaxY = 1.f;
}

Item::Item()
{
	initTexture();
	initSprite();
	initRandom();
	initPhysic();

	this->movementSpeed = 5.f;
}

Item::~Item()
{
}

const sf::FloatRect Item::getGlobalBoundsItem1() const
{
	return this->item[0].getGlobalBounds();
}

const sf::Vector2f Item::getPositionItem1() const
{
	return this->item[0].getPosition();
}

void Item::setPositionItem1(const float x, const float y)
{
	this->item[0].setPosition(x, y);
}

void Item::moveItem1(const float dirX, const float dirY)
{
	this->item[0].move(this->movementSpeed * dirX, this->movementSpeed * dirY);

	//acceletion
	this->velocity.x += dirX * this->acceleration;

	//limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
}

void Item::updateMovement()
{
	/*posY += 4.f;*/
	/*this->item[0].setPosition(300.f, 300.f);*/
	this->item[0].setOrigin(this->item[0].getLocalBounds().width / 2.f, this->item[0].getLocalBounds().height / 2.f);
	this->item[0].rotate(10.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		this->moveItem1(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		this->moveItem1(1.f, 0.f);
	}
}

void Item::updatePhysic()
{
	this->velocity.y += (1.0 * this->gravity);
	//printf("%f\n", this->item[0].getPosition().y);

	//deacceletion
	this->velocity *= drag;

	//limit deacceletion
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;
	
	this->item[0].move(this->velocity);
} 

void Item::update()
{
	this->updateMovement();
	this->updatePhysic();
}

void Item::render(sf::RenderTarget& target)
{
	target.draw(this->item[0]);

	sf::CircleShape Circ;
	Circ.setFillColor(sf::Color::Red);
	Circ.setRadius(3.f);
	Circ.setPosition(this->item[0].getPosition());
	target.draw(Circ);
}



