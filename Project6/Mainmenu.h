#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define MAX_NUMBER 5

class Mainmenu
{
private:
	//Font
	sf::Font Font;

	//Text
	sf::Text menu[MAX_NUMBER];
	
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
	Mainmenu(float width, float height);
	virtual ~Mainmenu();

	void update(float width, float height);

	void render(sf::RenderWindow& target);

	const sf::FloatRect	botton1() const;
	const sf::FloatRect botton2() const;
	const sf::FloatRect botton3() const;
	const sf::FloatRect botton4() const;
};

