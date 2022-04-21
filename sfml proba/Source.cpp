#include<iostream>
#include"Optiuni.h"
#include"Menu.h"
#include"joc.h"
#include"Car.h"
#include"enemies.h"
#include"SFML/Audio.hpp"

using namespace sf;

void controls(Menu& m,Optiuni& op,joc& j,Car& c,bool& keypress);
void functii(Menu& m,Optiuni& op,joc& j);
void death(Car& c, enemies& e,joc& j);
void increase(joc& j, enemies& e);

int main()
{
	
	sf::Font f;
	sf::RenderWindow window(sf::VideoMode(800, 700), "Crazy Cars", sf::Style::Titlebar | sf::Style::Close);
	Event e;
	f.loadFromFile("fonts\\arial.ttf");
	Text t;
	t.setFont(f);
	t.setString("Game Over\nPress r to reset\nPress esc to exit");
	t.setCharacterSize(75);
	t.setPosition(100, 200);

	Menu m(f);
	Optiuni op(f);
	joc j(f);
	Car c;
	enemies en(j);
	int i = 1;
	bool keypress = true;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
				case sf::Event::Closed:
					window.close();
				
				break;	
			}
			controls(m, op,j,c,keypress);
			death(c, en, j);
			increase(j, en);
		}
		
		window.clear();
		
		m.drawmenu(window);
		op.drawoptions(window);
		j.drawthegame(window);
		c.drawcar(window, j);
		en.draw(window, j);
		if (j.gameover == true)
		{
			window.draw(t);
		}
		
		window.display();
	}
	return 0;
}

void controls(Menu &m,Optiuni& op,joc& j,Car& c,bool& keypress)
{
	float dx=0, dy = 0;
	if (m.activ == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			keypress = true;
			m.index--;
			m.ChangeColor(-1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			keypress = true;
			m.index++;
			m.ChangeColor(1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&keypress==true)
		{
			functii(m, op,j);
			keypress = false;
		}
	}
	else if (op.activ == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			keypress = true;
			op.index--;
			op.changecolor(-1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			keypress = true;
			op.index++;
			op.changecolor(1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&keypress==true)
		{
			functii(m, op,j);
			
			keypress = false;
		}
	}
	else if (j.active == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			dx -= 10.1f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			dx += 10.1f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			dy -= 10.1f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			dy += 10.1f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			j.pause = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			j.pause = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			j.zeroscore();
			j.active = false;
			m.activ = true;
			
		}
		c.movement(dx, dy);
		
	}
	else if (j.active == false&&j.gameover==true)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			j.gameover = false;
			j.zeroscore();
			j.active = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			exit(0);
		}
	}
	
}

void functii(Menu& m, Optiuni& op,joc& j)
{
	if (m.activ == true)
	{
		switch (m.index)
		{
		case 1:
			j.active = true;
			break;
		case 2:
			op.activ = true;
			break;
		case 3:
			exit(0);
		}
		m.activ = false;
	}
	else if (op.activ == true)
	{
		switch (op.index)
		{
		case 1:
			j.hardmode = true;
			break;
		case 2:
			break;
		case 3:
			m.activ = true;
			op.activ = false;
			break;
		}
		
	}
}

void death(Car& c, enemies& e,joc& j)
{
	std::vector<sf::Sprite> s = e.returnvector();
	for (int i = 0; i < s.size(); i++)
	{
		if (c.getpositiony()>(s[i].getPosition().y-150)&&c.getpositiony()<=(s[i].getPosition().y +150) && c.getpositionx() > (s[i].getPosition().x - 50) && c.getpositionx() <= s[i].getPosition().x + 50)
		{
			j.active = false;
			j.gameover = true;
			

		}
	}
}

void increase(joc& j, enemies& e)
{
	if (j.getthescore() % 50==0)
	{
		e.increasefallingspeed(0.01f);
		j.increaseroadspeed(0.01f);
		cout<<j.
	}
	if (j.getthescore() % 1000 == 0)
	{
		e.increasenr();
	}
}
