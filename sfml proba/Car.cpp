#include "Car.h"

Car::Car()
{
	t.loadFromFile("fonts\\car5.png");
	s.setTexture(t);
	s.setScale(0.5, 0.5);
	s.setPosition(350, 500);

}

void Car::border()
{
	if (s.getPosition().y > 521)
	{
		s.setPosition(s.getPosition().x, 520);
	}
	else if (s.getPosition().y < 20)
	{
		s.setPosition(s.getPosition().x, 21);
	}
	else if (s.getPosition().x < 314)
	{
		s.setPosition(315, s.getPosition().y);
	}
	else if (s.getPosition().x > 690)
	{
		s.setPosition(689, s.getPosition().y);
	}
}

void Car::movement(float& x,float& y)
{
	border();
	s.move(sf::Vector2f( x,  y));
}

void Car::drawcar(sf::RenderWindow& w,joc& j)
{
	if (j.active == true)
	{
		w.draw(s);
	}
	
}

void Car::deletecar(joc& j)
{
	if (j.gameover == true)
	{
		delete this;
	}
}
