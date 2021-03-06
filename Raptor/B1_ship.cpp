#include "stdafx.h"
#include "B1_ship.h"


B1_ship::B1_ship(float x, float y, int lvl, Texture &texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(62, 110, 32, 32));
	sprite.setOrigin(16, 16);
	sprite.setPosition(x, y);
	R = sqrt(8 * 8 * 2);

	
	SHIELD = 20 * lvl;
	HP = 10 * lvl;
	points = 10 * lvl;
	level = lvl;

	bul1 = true;
	bul2 = false;
	bul3 = false;
	bul4 = false;

	out = false;

	rotation = 180;

	shoot_delay.restart();
	
}


B1_ship::~B1_ship()
{
}

void  B1_ship::shoot(vector<Bullet*> &vec, Texture &texture)
{
	if (shoot_delay.getElapsedTime().asMilliseconds() > 1650 && bul1)
	{
		vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, 180, level,texture));
		bul1 = false;
		bul2 = true;
	}
	if (shoot_delay.getElapsedTime().asMilliseconds() > 1700 && bul2)
	{
		vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, 180, level,texture));
		bul2 = false;
		bul3 = true;
	}
	if (shoot_delay.getElapsedTime().asMilliseconds() > 1750 && bul3)
	{
		vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, 180, level,texture));
		bul3 = false;
		bul4 = true;
	}
	if (shoot_delay.getElapsedTime().asMilliseconds() > 1800 && bul4)
	{
		vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, 180, level,texture));
		bul4 = false;
		bul1 = true;
		shoot_delay.restart();
	}

}



void B1_ship::move()
{
	if (sprite.getPosition().x > 400)
	{
		if (rotation < 240)
		{
			rotation += 0.1;
		}
		vx = sin(rotation*3.14 / 180);
		vy = -cos(rotation*3.14 / 180);
		sprite.move(vx, vy);
	}
	else
	{
		if (rotation > 120)
		{
			rotation -= 0.1;
		}
		vx = sin(rotation*3.14 / 180);
		vy = -cos(rotation*3.14 / 180);
		sprite.move(vx, vy);
	}
}