#pragma once
#include "Player.h"
#include "Player2.h"
#include "Ball.h"
#include "Wallpaper.h"
#include "Goal.h"
#include "GoalFront.h"
#include "GoalBack.h"
#include "Mainmenu.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<sstream>
#include<stdio.h>

class Game
{
private:
	Mainmenu* mainmenu;
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
	
	//clock
	sf::Font Font;
	sf::Text Time;
	sf::Text score1;
	sf::Text score2;

	//ability
	int ballBoundsPlayer1 = 0;
	int ballBoundsPlayer2 = 0;

	//Score
	int scorePlayer1 = 0;
	int scorePlayer2 = 0;

	//Time
	int timeCount = 0;
	sf::Clock timeClock;

	//Dash
	sf::Clock dashClock;

	//ABility
	sf::Clock abilityTimeCheck_Player1;
	sf::Clock abilityTimeCheck_Player2;
	bool abilityBoolPlayer1;
	bool abilityBoolPlayer2;

	void initWindow();
	void initGUI();
	void initHP();
	void initText();

public:
	Game();
	virtual ~Game();

	sf::RenderWindow* window;
	
	void run();

	void update();
	void render();

	void updateGUI();
	void renderGUI();

	void updateText();
	void renderText();

	void updatePlayer();
	void updatePlayer2();

	void action();
	void ability();

	void updateBall();
	
	void updateCollision();
};