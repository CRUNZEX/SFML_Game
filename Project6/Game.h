#pragma once
#include "Player.h"
#include "Ball.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Game
{
private:
	sf::RenderWindow* window;

	Player* player;
	ball* Ball;

	void initWindow();
	void initPlayer();
	void initBall();

public:
	Game();
	virtual ~Game();

	void run();

	void update();
	void render();

	void renderPlayer();
	void updatePlayer();
	void updateCollision();

	void renderBall();
	void updateBall();
};

