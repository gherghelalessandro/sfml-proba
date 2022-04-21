#pragma once
#include"SFML/Graphics.hpp"
#include"joc.h"
#include<vector>
#include"Car.h"

class enemies
{
	sf::Sprite s;
	
	int nr;
	int poziti[4] = {330,440,550,660};
	std::vector<sf::Sprite>cars;
	float speed,timer=1000.0f,fallingspeed;
	sf::Texture t,t1,t2;
	
	
public:
	enemies(joc& j);
	void increasenr();
	void draw(sf::RenderWindow& w,joc& j);
	void fall(sf::Sprite& s,int i,joc& j);
	std::vector<sf::Sprite> returnvector();
	void increasefallingspeed(float nr);
};

