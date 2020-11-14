#pragma once
#include "Player.h"
#include "Player2.h"
#include "Ball.h"
#include "Wallpaper.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class Game
{
private:
	sf::RenderWindow* window;

	Player* player;
	Player2* player2;
	ball* Ball;
	Wallpaper* wallpaper;

	void initWallpaper();
	void initWindow();
	void initPlayer();
	void initPlayer2();
	void initBall();

public:
	Game();
	virtual ~Game();

	void run();

	void update();
	void render();

	void renderWallpaper();
	void updateWallpaper();

	void renderPlayer();
	void updatePlayer();
	
	void renderPlayer2();
	void updatePlayer2();
	
	void updateCollision();

	void renderBall();
	void updateBall();
};

