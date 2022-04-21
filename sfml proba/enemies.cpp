#include "enemies.h"

enemies::enemies(joc& j)
{
	t.loadFromFile("fonts\\car1.png");
	t1.loadFromFile("fonts\\limo.png");
	t2.loadFromFile("fonts\\truck.png");
	s.setTexture(t);
	nr = 1;
	speed = 0.0f;
	fallingspeed = 0.01f;
	if (j.hardmode == true)
	{
		fallingspeed = 0.1f;
		nr = 3;
	}
}


void enemies::increasenr()
{
	nr++;
}

void enemies::draw(sf::RenderWindow& w,joc& j)
{
	
	if (j.active == true&&j.gameover==false&&j.pause==false)
	{
		if (cars.size() <= nr)
		{
			int last=0;
			speed+=0.40f;
			if (speed > timer)
			{
				speed = 0;
				int nr1 = rand() % 3 + 1, nr2 = rand()%3+1;
				if (nr1 == 1)
				{
					s.setTexture(t);
					s.setScale(0.3f, 0.3f);
				}
				else if (nr1 == 2)
				{
					s.setTexture(t1);
					s.setScale(0.3f, 0.3f);
				}
				else if (nr1 == 3)
				{
					s.setTexture(t2);
					s.setScale(0.3f, 0.3f);
				}

				if (last != poziti[nr2])
				{
					s.setPosition(poziti[nr2], 0);
				}
				last = poziti[nr2];
				cars.push_back(s);
			}
			
		}
		for (int i = 0; i <cars.size(); i++)
		{
			fall(cars[i], i,j);
			w.draw(cars[i]);
		}
		
	}
	else if (j.active == false)
	{
		cars.erase(cars.begin(), cars.end());
		nr=1;
		speed = 0.0f;
		fallingspeed = 0.1f;
	}
	
}

void enemies::fall(sf::Sprite& s,int i,joc& j)
{
	if (j.active == true&&j.gameover==false)
	{
		s.move(0, fallingspeed);
		if (s.getPosition().y > 640)
		{
			this->cars.erase(this->cars.begin() + i);
		}
	}
	
}

std::vector<sf::Sprite> enemies::returnvector()
{
	return cars;
}


void enemies::increasefallingspeed(float nr)
{
	fallingspeed += nr;
}
