#pragma once
#include<SFML/Graphics.hpp>
#include"Menu.h"

class Optiuni
{
	
	sf::Text t[4];
	bool bifat[4] = { false,false,false,false };
	int pos = 200;

public:
	int index = 1;
	bool activ = false;

	Optiuni(sf::Font& f);
	void setactiv();
	void drawoptions(sf::RenderWindow& w);
	void changecolor(int movement);
	
};

