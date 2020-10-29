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
void Game::initBall()
{
	this->Ball = new ball();
}
Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initBall();
}
Game::~Game() 
{
	delete this->window;
	delete this->player;
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
	this->updateBall();
	this->updateCollision();
	
}

void Game::render()
{
	this->window->clear();
	this->renderPlayer();
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

void Game::updateCollision()
{
	//collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, this->window->getSize().y - this->player->getGlobalBounds().height);
	}

	if (this->Ball->getPositionBall().y + this->Ball->getGlobalBoundsBall().height > this->window->getSize().y)
	{
		this->Ball->resetVelocityYBall();
		this->Ball->setPositionBall(this->Ball->getPositionBall().x, this->window->getSize().y - this->Ball->getGlobalBoundsBall().height);
	}
}

void Game::renderBall()
{
	this->Ball->renderBall(*this->window);
}

void Game::updateBall()
{
	this->Ball->updateBall();
}
