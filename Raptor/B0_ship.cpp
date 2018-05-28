#include "stdafx.h"
#include "B0_ship.h"


B0_ship::B0_ship(int x, int y)
{
	way = 0;
	if (!texture.loadFromFile("enemy.png"))
	{
		cout << "Can't load enemy.png\n";
	}
	sprite.setTexture(texture);
	sprite.setOrigin(16, 16);
	sprite.setTextureRect(IntRect(0,110,32,32));
	R= sqrt(16 * 16 * 2);
	sprite.setPosition(x, y);
	out = false;
	points = 50;
	
}

void B0_ship::shoot(vector<Bullet*> &vec)
{
	cout << "shoot";
	if (shoot_delay.getElapsedTime().asMilliseconds() > 1000)
	{
		vec.push_back(new Bullet(sprite.getPosition().x+5, sprite.getPosition().y+5,180,false));
		shoot_delay.restart();
	}
}


void B0_ship::aim(vector<Bullet*> &vec, Vector2f pos)
{
	if ((sprite.getPosition().x <(pos.x + 10) || sprite.getPosition().x >(pos.x - 10)) && sprite.getPosition().y < pos.y)
	{
		shoot(vec);
	}
	cout << vec.size();
}

void B0_ship::move()
{
	sprite.move(way, 0.5);
}

B0_ship::~B0_ship()
{
}

void B0_ship::trace(Vector2f pos)
{
	if (sprite.getPosition().x < pos.x)
	{
		way= 1;
	}
	else if (sprite.getPosition().x > pos.x)
	{
		way = -1;
	}
}