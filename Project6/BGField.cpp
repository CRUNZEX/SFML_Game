#include "BGField.h"

void BGField::initTexture()
{
	if (!this->texture0.loadFromFile("Pictures/football_field_0.png"))
		printf("ERROR::BGfield_0 not be load");
	if (!this->texture1.loadFromFile("Pictures/football_field_1.png"))
		printf("ERROR::BGfield_1 not be load");
	if (!this->texture2.loadFromFile("Pictures/football_field_2.png"))
		printf("ERROR::BGfield_2 not be load");
	if (!this->texture3.loadFromFile("Pictures/football_field_3.png"))
		printf("ERROR::BGfield_3 not be load");
	if (!this->texture4.loadFromFile("Pictures/football_field_4.png"))
		printf("ERROR::BGfield_4 not be load");
}

void BGField::initBG()
{
	switch (this->numPic)
	{
	case 0:
		this->bg.setTexture(this->texture0);
		break;
	case 1:
		this->bg.setTexture(this->texture1);
		break;
	case 2:
		this->bg.setTexture(this->texture2);
		break;
	case 3:
		this->bg.setTexture(this->texture3);
		break;
	case 4:
		this->bg.setTexture(this->texture4);
		break;

	default:
		break;
	}

	this->bg.setScale(2.67f, 2.67f);
	this->bg.setPosition(0, 460);
}

void BGField::initRandom()
{
	srand(time(NULL));
	if (this->randomDraw == false)
	{
		this->numPic = rand() % 5;
		printf("numPic : %d", this->numPic);
		this->randomDraw = true;
	}
}

BGField::BGField()
{
	this->initRandom();
	this->initTexture();
	this->initBG();
}

BGField::~BGField()
{
}
