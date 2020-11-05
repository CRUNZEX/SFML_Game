#include "Game.h"
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initPlayer()
{
	this->player = new Player();
}
void Game::initPlayer2()
{
	this->player2 = new Player2();
}
void Game::initBall()
{
	this->Ball = new ball();
}
Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initPlayer2();
	this->initBall();
}
Game::~Game() 
{
	delete this->window;
	delete this->player;
	delete this->player2;
	delete this->Ball;
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
void Game::update()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();

		if (e.Event::type == sf::Event::KeyReleased && (e.Event::key.code == sf::Keyboard::A || e.Event::key.code == sf::Keyboard::D || e.Event::key.code == sf::Keyboard::S || e.Event::key.code == sf::Keyboard::W))
			this->player->resetAnimationTimer();
	}
	this->updatePlayer();
	this->updatePlayer2();
	this->updateBall();
	this->updateCollision();
	
}

void Game::render()
{
	this->window->clear();
	this->renderPlayer();
	this->renderPlayer2();
	this->renderBall();
	this->window->display();
}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::renderPlayer2()
{
	this->player2->render(*this->window);
}

void Game::updatePlayer2()
{
	this->player2->update();
}

void Game::updateCollision()
{
	//collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height + 30 > this->window->getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, this->window->getSize().y - this->player->getGlobalBounds().height - 30);
		this->player->jumping = false;
		this->player->jumpingUp = false;
		this->player->gravityBool = false;
	}

	if (this->player2->getPosition().y + this->player2->getGlobalBounds().height + 30 > this->window->getSize().y)
	{
		this->player2->resetVelocityY();
		this->player2->setPosition(this->player2->getPosition().x, this->window->getSize().y - this->player2->getGlobalBounds().height - 30);
		this->player2->jumping2 = false;
		this->player2->jumpingUp2 = false;
		this->player2->gravityBool2 = false;
	}

	if (this->Ball->getPositionBall().y + this->Ball->getGlobalBoundsBall().height + 35 > this->window->getSize().y)
	{
		this->Ball->resetVelocityYBall();
		this->Ball->setPositionBall(this->Ball->getPositionBall().x, this->window->getSize().y - this->Ball->getGlobalBoundsBall().height - 35);
	}

	//collision right of screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width > this->window->getSize().x + 100)
	{
		this->player->resetVelocityX();
		this->player->setPosition( this->window->getSize().x - this->player->getGlobalBounds().width + 100, this->player->getPosition().y);
	}

	if (this->player2->getPosition().x + this->player2->getGlobalBounds().width > this->window->getSize().x)
	{
		this->player2->resetVelocityX();
		this->player2->setPosition(this->window->getSize().x - this->player2->getGlobalBounds().width, this->player2->getPosition().y);
	}

	//collision left of screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width < 200)
	{
		this->player->resetVelocityX();
		this->player->setPosition( 100, this->player->getPosition().y);
	}
	if (this->player2->getPosition().x + this->player2->getGlobalBounds().width < 100)
	{
		this->player2->resetVelocityX();
		this->player2->setPosition( 0, this->player2->getPosition().y);
	}

	//collision

}

void Game::renderBall()
{
	this->Ball->renderBall(*this->window);
}

void Game::updateBall()
{
	this->Ball->updateBall();
}
