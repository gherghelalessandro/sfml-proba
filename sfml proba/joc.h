#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
class joc
{
	sf::Sprite s,s1;
	sf::Text score,pausetext;
	int i = 0;
	float j = 0.0f,j1=0.0f,speed=0.01f;
	sf::Texture t;
	

public:
	bool pause=false,active=false,gameover=false,hardmode=false;
	
	joc(sf::Font& f);
	void drawthegame(sf::RenderWindow& w);
	void drawtheroad();
	int getthescore();
	void gettheshti();
	void increaseroadspeed(float nr);
	void zeroscore();

};

