#include "BGCheer.h"

void BGCheer::initTexture()
{
	if (!this->texture0.loadFromFile("Pictures/cheer_0.png"))
		printf("ERROR::BGcheer_0 not be load");
	if (!this->texture1.loadFromFile("Pictures/cheer_1.png"))
		printf("ERROR::BGcheer_1 not be load");
	if (!this->texture2.loadFromFile("Pictures/cheer_2.png"))
		printf("ERROR::BGcheer_2 not be load");
	if (!this->texture3.loadFromFile("Pictures/cheer_3.png"))
		printf("ERROR::BGcheer_3 not be load");
	if (!this->texture4.loadFromFile("Pictures/cheer_4.png"))
		printf("ERROR::BGcheer_4 not be load");
	if (!this->texture5.loadFromFile("Pictures/cheer_5.png"))
		printf("ERROR::BGcheer_5 not be load");
	if (!this->texture6.loadFromFile("Pictures/cheer_6.png"))
		printf("ERROR::BGcheer_6 not be load");
	if (!this->texture7.loadFromFile("Pictures/cheer_7.png"))
		printf("ERROR::BGcheer_7 not be load");
}

void BGCheer::initBG()
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
	case 5:
		this->bg.setTexture(this->texture5);
		break;
	case 6:
		this->bg.setTexture(this->texture6);
		break;
	case 7:
		this->bg.setTexture(this->texture7);
		break;

	default:
		break;
	}

	this->bg.setScale(2.67f, 2.67f);
	this->bg.setPosition(0, 185);
}

void BGCheer::initRandom()
{
	srand(time(NULL));
	if (this->randomDraw == false)
	{
		this->numPic = rand() % 8;
		printf("numPic : %d", this->numPic);
		this->randomDraw = true;
	}
}

BGCheer::BGCheer()
{
	this->initRandom();
	this->initTexture();
	this->initBG();
}

BGCheer::~BGCheer()
{
}
