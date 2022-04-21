#include "joc.h"

joc::joc(sf::Font& f)
{
	t.loadFromFile("fonts\\road_0.png");
	s.setTexture(t);
	s1.setTexture(t);
	s1.setScale(0.5f, 1);
	s.setScale(sf::Vector2f(0.5f, 1));
	s.setOrigin(0, 120);
	s1.setOrigin(0, 300);
	score.setFont(f);
	score.setCharacterSize(20);
	score.setPosition(0, 100);
	pausetext.setFont(f);
	pausetext.setString("Pause");
	pausetext.setPosition(100, 200);
	pausetext.setCharacterSize(20);
	speed = 0;
	
}

void joc::drawthegame(sf::RenderWindow& w)
{
	
	if (active == true)
	{
		std::stringstream ss;
		ss << "Points:\n" << i;
		if (pause == false &&gameover == false)
		{
			if (j > 1000.0f)
			{
				j = 0.0f;
				i++;
			}

			drawtheroad();
			j += 1.0f;
		}
		score.setString(ss.str());
		w.draw(s1);
		w.draw(s);
		w.draw(score);

		if (pause == true)
		{
			w.draw(pausetext);
		}
	}
	
}

void joc::drawtheroad()
{
	j1 += speed;
	s.setPosition(260, j1);
	s1.setPosition(260,j1);
	if (j1 > 100)
	{
		j1 = 0;
	}
	
}

int joc::getthescore()
{
	return i;
}

void joc::increaseroadspeed(float nr)
{
	speed+= nr;
}

void joc::zeroscore()
{
	i = 0;
}


