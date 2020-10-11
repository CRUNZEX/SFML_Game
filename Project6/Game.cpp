#include "Game.h"
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initPlayer()
{
	this->player = new Player();
}
Game::Game()
{
	this->initWindow();
	this->initPlayer();
}
Game::~Game() 
{
	delete this->window;
	delete this->player;
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
	}
	this->updatePlayer();
	
}

void Game::render()
{
	this->window->clear();
	this->player->render(*this->window);
	this->window->display();

	this->renderPlayer();

}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::updatePlayer()
{
	this->player->update();
}
