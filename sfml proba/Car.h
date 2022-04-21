#pragma once
#include<SFML/Graphics.hpp>
#include"joc.h"
#include"enemies.h"
class Car
{
	sf::Sprite s;
	sf::Texture t;
public:
	Car();
	void border();
	void movement(float& x,float& y);
	void drawcar(sf::RenderWindow& w,joc& j);
	float getpositiony()
	{
		return s.getPosition().y;
	}
	float getpositionx()
	{
		return s.getPosition().x;
	}
	void deletecar(joc& j);
};

