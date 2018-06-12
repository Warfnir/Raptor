#include "stdafx.h"
#include "B0_ship.h"


B0_ship::B0_ship(int x, int y,int lvl, Texture &texture)
{
	way = 0;
	level = lvl;
	sprite.setTexture(texture);
	sprite.setOrigin(16, 16);
	sprite.setTextureRect(IntRect(0,110,32,32));
	R= sqrt(8 * 8 * 2);
	sprite.setPosition(x, y);
	out = false;
	points = 25*lvl;
	HP = 50 *level;
}

void B0_ship::shoot(vector<Bullet*> &vec, Texture &texture)
{
	if (shoot_delay.getElapsedTime().asMilliseconds() > 2000)
	{
		vec.push_back(new standard_bullet(sprite.getPosition().x+5, sprite.getPosition().y+5,180,level,texture));
		shoot_delay.restart();
	}
}


void B0_ship::aim(vector<Bullet*> &vec, Vector2f pos,Texture &texture)
{
	if ((sprite.getPosition().x <(pos.x + 10) || sprite.getPosition().x >(pos.x - 10)) && sprite.getPosition().y < pos.y)
	{
		shoot(vec, texture);
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