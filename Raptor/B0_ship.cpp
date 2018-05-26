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
	to_destroy = 0;
	
}

void B0_ship::shoot(vector<Bullet*> &vec)
{

}

void B0_ship::outOfWindow()
{
	if (sprite.getPosition().x > 800 +R)
	{
		to_destroy = 1;
	}
	if (sprite.getPosition().x <0 -R)
	{
		to_destroy = 1;
	}
	if (sprite.getPosition().y > R+600)
	{
		to_destroy = 1;
	}
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