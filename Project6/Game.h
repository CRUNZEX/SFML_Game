#pragma once
#include "Player.h"
#include "Player2.h"
#include "Ball.h"
#include "Wallpaper.h"
#include "Goal.h"
#include "GoalFront.h"
#include "GoalBack.h"
#include "Mainmenu.h"
#include "Textbox.h"
#include "GameEnd.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<string>
#include<sstream>
#include<utility>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stdio.h>

#define GAMETIME 10
using namespace std;

class Game
{
private:
	Mainmenu* mainmenu;
	Textbox* textbox;
	GameEnd* gameend;
	Wallpaper* wallpaper;
	
	Player* player;
	Player2* player2;
	
	ball* Ball;
	
	Goal* goal;
	GoalFront* goalfront;
	GoalBack* goalback;

	//Mouse
	sf::Vector2i mousePosition_Window;
	sf::Vector2f mousePosition_View;

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

	//Ability
	sf::Clock abilityTimeCheck_Player1;
	sf::Clock abilityTimeCheck_Player2;
	bool abilityBoolPlayer1;
	bool abilityBoolPlayer2;

	//Menu State
	int gameState = 0;

	//High Score
	FILE* fp;


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

	void mousePosition();

	void updateGUI();
	void renderGUI();

	void updateGUImain();
	void updateGUItextbox();
	void updateGUIend();

	void showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font);

	void updateText();
	void renderText();

	void updatePlayer();
	void updatePlayer2();

	void action();
	void ability();

	void updateBall();
	
	void updateCollision();
};