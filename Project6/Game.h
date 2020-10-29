#pragma once
#include "Player.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Game
{
private:
	sf::RenderWindow* window;

	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	void run();

	void update();
	void render();

	void renderPlayer();
	void updatePlayer();
	void updateCollision();
};

