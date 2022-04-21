#pragma once
#include<SFML/Graphics.hpp>



class Menu
{
	sf::Text t[4];
	
public:
	bool activ = true;
	static int pos ;
	int index=1;
	Menu(sf::Font& f);
	void start();
	void ChangeColor(int movement);
	void drawmenu(sf::RenderWindow& w);
	void controls(bool& keypress);
};

