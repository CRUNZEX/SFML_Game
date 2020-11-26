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

	//HP
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape playerMpBar;
	sf::RectangleShape playerMpBarBack;

	sf::RectangleShape player2HpBar;
	sf::RectangleShape player2HpBarBack;
	sf::RectangleShape player2MpBar;
	sf::RectangleShape player2MpBarBack;

	void initWindow();
	void initGUI();
	void initHP();

public:
	Game();
	virtual ~Game();

	sf::RenderWindow* window;
	
	void run();

	void update();
	void render();

	void updateGUI();
	void renderGUI();

	void updatePlayer();
	void updatePlayer2();
	
	void action();

	void updateBall();
	
	void updateCollision();
};