#include "Optiuni.h"

Optiuni::Optiuni(sf::Font& f)
{
	for (int i = 0; i < 4; i++)
	{
		t[i].setFont(f);
	}
	t[0].setString("Optiuni");
	t[1].setString("HARD MODE");
	t[2].setString("No car mode");
	t[3].setString("exit");
	t[0].setCharacterSize(100);
	t[0].setPosition(200, 0);
	t[0].setFillColor(sf::Color::Blue);
	for (int i = 1; i <= 3; i++)
	{
		this->t[i].setFont(f);
		this->t[i].setPosition(200, pos);
		this->t[i].setCharacterSize(50);
		this->t[i].setFillColor(sf::Color::White);
		pos += 75;
	}
	int i = 1;
	changecolor(0);
	
	
}

void Optiuni::setactiv()
{
	activ = true;
}

void Optiuni::changecolor(int movement)
{
	if (movement == 0)
	{
		this->t[index].setFillColor(sf::Color::Yellow);
	}
	else if (movement == -1)
	{
		if (index < 1)
		{
			index = 3;
			this->t[1].setFillColor(sf::Color::White);
			this->t[index].setFillColor(sf::Color::Yellow);
		}
		else
		{
			this->t[index].setFillColor(sf::Color::Yellow);
			this->t[index + 1].setFillColor(sf::Color::White);
		}
	}
	else if (movement == 1)
	{
		if (index > 3)
		{
			this->t[index - 1].setFillColor(sf::Color::White);
			index = 1;
			this->t[index].setFillColor(sf::Color::Yellow);
		}
		else
		{
			this->t[index - 1].setFillColor(sf::Color::White);
			this->t[index].setFillColor(sf::Color::Yellow);
		}
	}
}


void Optiuni::drawoptions(sf::RenderWindow& w)
{
	if (activ == true)
	{
		for (int i = 0; i <= 3; i++)
		{
			w.draw(t[i]);
		}
	}
	
}
