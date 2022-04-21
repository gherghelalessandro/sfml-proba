#include "Menu.h"


int Menu::pos = 200;

Menu::Menu(sf::Font& f)
{
	
	f.loadFromFile("fonts\\arial.ttf");
	this->t[0].setString("Crazy Race");
	this->t[1].setString("Play!");
	this->t[2].setString("Options");
	this->t[3].setString("Exit");

	this->t[0].setFont(f);
	this->t[0].setCharacterSize(100);
	t[0].setPosition(150, 0);
	t[0].setFillColor(sf::Color::Red);

	for (int i = 1; i <= 3; i++)
	{
		this->t[i].setFont(f);
		this->t[i].setPosition(150, pos);
		this->t[i].setCharacterSize(50);
		this->t[i].setFillColor(sf::Color::White);
		pos += 75;
	}
	int i = 1;
	ChangeColor(0);
}

void Menu::ChangeColor(int movement)
{	
	if (movement == 0)
	{
		this->t[index].setFillColor(sf::Color::Red);
	}
	else if (movement == -1)
	{
		if (index < 1)
		{
			index = 3;
			this->t[1].setFillColor(sf::Color::White);
			this->t[index].setFillColor(sf::Color::Red);
		}
		else
		{
			this->t[index].setFillColor(sf::Color::Red);
			this->t[index + 1].setFillColor(sf::Color::White);
		}
	}
	else if (movement == 1)
	{
		if (index > 3)
		{
			this->t[index - 1].setFillColor(sf::Color::White);
			index = 1;
			this->t[index].setFillColor(sf::Color::Red);
		}
		else
		{
			this->t[index - 1].setFillColor(sf::Color::White);
			this->t[index].setFillColor(sf::Color::Red);
		}
	}
}



void Menu::drawmenu(sf::RenderWindow& w) 
{
	if (activ == true)
	{
		for (int i = 0; i <= 3; i++)
		{
			w.draw(t[i]);
		}
	}
	
}
