#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
#include "GameText.h"
#include "GameHigh.h"
#include "GameHowto.h"

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<string>
#include<sstream>
#include<utility>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stdio.h>

#define GAMETIME 59
using namespace std;

class Game
{
private:
	Mainmenu* mainmenu;
	Textbox* textbox;
	GameText* gametext;
	GameEnd* gameend;
	GameHigh* gamehigh;
	GameHowTo* gamehowto;
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
	bool right = false;

	//High Score
	FILE* fp;
	char temp[255];
	int score[7];
	string name[7];
	vector<pair<int, string>>userScore;
	bool highscore = false;


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
	void updateGUIHigh();
	void updateGUIhowto();

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