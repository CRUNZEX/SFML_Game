#pragma once
#include "Player.h"
#include "Player2.h"
#include "Ball.h"
#include "Wallpaper.h"
#include "Goal.h"
#include "GoalFront.h"
#include "GoalBack.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

class Game
{
private:
	Wallpaper* wallpaper;
	
	Player* player;
	Player2* player2;
	
	ball* Ball;
	
	Goal* goal;
	GoalFront* goalfront;
	GoalBack* goalback;

	void initWindow();

public:
	Game();
	virtual ~Game();

	sf::RenderWindow* window;
	
	void run();

	void update();
	void render();

	void updatePlayer();
	void updatePlayer2();
	
	void updateBall();
	
	void updateCollision();
};