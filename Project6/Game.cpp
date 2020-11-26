#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

	//Wallpaper
	this->wallpaper = new Wallpaper();
	
	//Player
	this->player = new Player();
	this->player2 = new Player2();
	
	//Ball
	this->Ball = new ball();
	
	//Goal
	this->goal = new Goal();
	this->goalfront = new GoalFront();
	this->goalback = new GoalBack();
}
void Game::initGUI()
{
	//Player 1
	//HP
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	//MP
	this->playerMpBar.setSize(sf::Vector2f(250.f, 10.f));
	this->playerMpBar.setFillColor(sf::Color::Blue);
	this->playerMpBar.setPosition(sf::Vector2f(20.f, 50.f));

	this->playerMpBarBack = this->playerMpBar;
	this->playerMpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	//Player 2
	//HP
	this->player2HpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->player2HpBar.setFillColor(sf::Color::Red);
	this->player2HpBar.setPosition(sf::Vector2f(960.f, 20.f));

	this->player2HpBarBack = this->player2HpBar;
	this->player2HpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	//MP
	this->player2MpBar.setSize(sf::Vector2f(250.f, 10.f));
	this->player2MpBar.setFillColor(sf::Color::Blue);
	this->player2MpBar.setPosition(sf::Vector2f(1010.f, 50.f));

	this->player2MpBarBack = this->player2MpBar;
	this->player2MpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}
void Game::initHP()
{
}
Game::Game()
{
	this->initWindow();
	this->initGUI();
}
Game::~Game() 
{
	delete this->window;

	delete this->player;
	delete this->player2;
	delete this->Ball;

	//delete this->goal;
	delete this->goalfront;
	delete this->goalback;
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

	this->updateGUI();
	/*this->action();*/
	this->updateCollision();
}

void Game::render()
{
	this->window->clear();

	//Wallpaper
	this->wallpaper->render(*this->window);
	
	//Player
	this->player->render(*this->window);
	this->player2->render(*this->window);

	//Ball
	this->Ball->renderBall(*this->window);
	
	//Goal
	//this->goal->render(*this->window);
	//this->goalfront->render(*this->window);
	//this->goalback->render(*this->window);

	this->renderGUI();
	
	this->window->display();
}

void Game::updateGUI()
{
	float hpPercent = static_cast<float>(this->player->HPget()) / this->player->HPgetMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

	float hpPercent2 = static_cast<float>(this->player2->HPget()) / this->player2->HPgetMax();
	this->player2HpBar.setSize(sf::Vector2f(300.f * hpPercent2, this->player2HpBar.getSize().y));
}

void Game::renderGUI()
{
	//Player1
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

	this->window->draw(this->playerMpBarBack);
	this->window->draw(this->playerMpBar);

	//Player2
	this->window->draw(this->player2HpBarBack);
	this->window->draw(this->player2HpBar);

	this->window->draw(this->player2MpBarBack);
	this->window->draw(this->player2MpBar);
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updatePlayer2()
{
	this->player2->update();
}

void Game::action()
{
	if (this->player->getGlobalBounds().intersects(this->player2->getGlobalBounds()) && this->player->kick == true)
	{
		printf("Kick\n");
		this->player->kick = false;
		this->player2->HPlose(1);
	}
	if (this->player2->getGlobalBounds().intersects(this->player->getGlobalBounds()) && this->player2->kick == true)
	{
		printf("Kick\n");
		this->player2->kick = false;
		this->player->HPlose(1);
	}
}

void Game::updateBall()
{
	this->Ball->updateBall();
}

void Game::updateCollision()
{
	//collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height + 75 > this->window->getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, this->window->getSize().y - this->player->getGlobalBounds().height - 75);
		/*this->player->jumping = false;
		this->player->jumpingUp = false;
		this->player->gravityBool = false;*/

		this->player->jumpBreak();
	}

	if (this->player2->getPosition().y + this->player2->getGlobalBounds().height + 75 > this->window->getSize().y)
	{
		this->player2->resetVelocityY();
		this->player2->setPosition(this->player2->getPosition().x, this->window->getSize().y - this->player2->getGlobalBounds().height - 75);
		this->player2->jumping2 = false;
		this->player2->jumpingUp2 = false;
		this->player2->gravityBool2 = false;
	}

	if (this->Ball->getPositionBall().y + this->Ball->getGlobalBoundsBall().height + 80 > this->window->getSize().y)
	{
		if (this->Ball->ballBounds < 5 && this->Ball->ballBounds >= 0)
		{
			this->Ball->ballBounds++;
			this->Ball->velocity.y *= -1.2f;
			this->Ball->velocity.x *= 1.2f;
			if (this->Ball->ballBounds == 4)
				this->Ball->ballstart = true;
		}
		/*else
			this->Ball->ballBounds = 0;*/
		this->Ball->setPositionBall(this->Ball->getPositionBall().x, this->window->getSize().y - this->Ball->getGlobalBoundsBall().height - 80);

		//printf("Bounds : %d\n", this->Ball->ballBounds);
		
		//this->Ball->resetVelocityYBall();
		//this->Ball->setPositionBall(this->Ball->getPositionBall().x, this->window->getSize().y - this->Ball->getGlobalBoundsBall().height - 35);
	}

	//collision right of screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width > this->window->getSize().x + 100)
	{
		this->player->resetVelocityX();
		this->player->setPosition(this->window->getSize().x - this->player->getGlobalBounds().width + 100, this->player->getPosition().y);
	}
	if (this->player2->getPosition().x + this->player2->getGlobalBounds().width > this->window->getSize().x)
	{
		this->player2->resetVelocityX();
		this->player2->setPosition(this->window->getSize().x - this->player2->getGlobalBounds().width, this->player2->getPosition().y);
	}
	if (this->Ball->getPositionBall().x + this->Ball->getGlobalBoundsBall().width > this->window->getSize().x)
	{
		this->Ball->velocity.x = -this->Ball->velocity.x;
		this->Ball->setPositionBall(this->window->getSize().x - this->Ball->getGlobalBoundsBall().width, this->Ball->getPositionBall().y);
	}

	//collision left of screen
	if (this->player->getPosition().x + this->player->getGlobalBounds().width < 200)
	{
		this->player->resetVelocityX();
		this->player->setPosition(100, this->player->getPosition().y);
	}
	if (this->player2->getPosition().x + this->player2->getGlobalBounds().width < 100)
	{
		this->player2->resetVelocityX();
		this->player2->setPosition(0, this->player2->getPosition().y);
	}
	if (this->Ball->getPositionBall().x + this->Ball->getGlobalBoundsBall().width < 50)
	{
		this->Ball->velocity.x = -this->Ball->velocity.x;
		this->Ball->setPositionBall(0, this->Ball->getPositionBall().y);
	}

	//collision

	//Player1
	//if (this->Ball->getGlobalBoundsBall().intersects(this->player->getGlobalBounds()))
	//{
	//	printf("X :: Player : %f     Ball : %f\n", this->player->getPosition().x, this->Ball->getPositionBall().x);
	//	if ((this->player->getPosition().x - 40.f <= this->Ball->getPositionBall().x || this->player->getPosition().x >= this->Ball->getPositionBall().x + 80.f) && this->player->kick == false)
	//	{
	//		//printf("Collsion Left\n");
	//		if (this->player->dash == false)
	//			this->Ball->velocity.x = (this->player->velocity.x <= 0) ? this->player->velocity.x - 10.f : this->player->velocity.x + 10.f;
	//		else
	//		{
	//			this->Ball->ballBounds = 0;
	//			this->Ball->velocity.y = -50.f;
	//			this->Ball->velocity.x = (this->player->velocity.x <= 0) ? this->player->velocity.x * 30.f : this->player->velocity.x * 30.f;
	//			
	//		}
	//	}
	//	//else if (this->player->getPosition().x >= this->Ball->getPositionBall().x + 120.f && this->player->kick == false)
	//	//{
	//	//	//printf("Collsion Right");
	//	//	this->Ball->move(-3.f, 0.f);
	//	//}
	//}

	if (this->Ball->getGlobalBoundsBall().intersects(this->player->getHitboxLBounds()))
	{
		if (this->player->dash == false)
			this->Ball->velocity.x = (this->player->velocity.x <= 0) ? this->player->velocity.x - 10.f : this->player->velocity.x + 10.f;
		else
		{
			this->Ball->ballBounds = 0;
			this->Ball->velocity.y = -50.f;
			this->Ball->velocity.x = this->player->velocity.x * 20.f;
		}
	}
	else if (this->Ball->getGlobalBoundsBall().intersects(this->player->getHitboxRBounds()))
	{
		if (this->player->dash == false)
			this->Ball->velocity.x = (this->player->velocity.x <= 0) ? this->player->velocity.x - 10.f : this->player->velocity.x + 10.f;
		else
		{
			this->Ball->ballBounds = 0;
			this->Ball->velocity.y = -50.f;
			this->Ball->velocity.x = this->player->velocity.x * 20.f;
		}
	}

	//Player2
	//if (this->player2->getGlobalBounds().intersects(this->Ball->getGlobalBoundsBall()))
	//{
	//	//printf("Player : %f     Ball : %f\n", this->player2->getPosition().x, this->Ball->getPositionBall().x);

	//	if (this->player2->getPosition().x > this->Ball->getPositionBall().x + 20.f)
	//		this->Ball->move(-3.f, 0.f);
	//	else if (this->player2->getPosition().x < this->Ball->getPositionBall().x - 90.f)
	//		this->Ball->move(3.f, 0.f);
	//}

}

