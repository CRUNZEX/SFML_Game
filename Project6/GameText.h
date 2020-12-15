#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define MAX_NUMBER 5

class GameText
{
private:
	//Font
	sf::Font Font;

	//Player
	sf::Texture texturePlayer1;
	sf::Texture texturePlayer2;
	sf::Sprite Player1;
	sf::Sprite Player2;

	//Texture
	sf::Texture bgTexture;
	sf::Texture scoreTexture;
	sf::Texture goalTexture;

	//Sprite
	sf::Sprite bgSprite;
	sf::Sprite scoreSprite;
	sf::Sprite goalSprite;

	//Core
	void initText();
	void initMenu();
	void initBotton(float width, float height);

public:
	GameText(float width, float height);
	virtual ~GameText();

	void update(float width, float height);

	void render(sf::RenderWindow& target);

	//Text
	sf::Text menu[MAX_NUMBER];

	const sf::FloatRect	botton1() const;
	const sf::FloatRect botton2() const;
	const sf::FloatRect botton3() const;
	const sf::FloatRect botton4() const;
};