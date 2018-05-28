#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(float x, float y, float rotate, bool up)
{
	if (!texture.loadFromFile("bullet.png"))
	{
		cout << "Can't open bullet.png\n";
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.rotate(rotate);
	if (up)
	{
		vx = 0.0f;
		vy = -8.0f;
	}
	else
	{
		vx = 0.0f;
		vy = 8.0f;
	}
	sprite.setOrigin(8, 8);
	sprite.setPosition(x, y);
	R = sqrt(8 * 8 * 2);
	dmg = 10;
	life = true;
}

double Bullet::getDmg()
{
	return dmg;
}

void Bullet::destroy()
{
	life = false;
}

bool Bullet::getLife()
{
	return life;
}


bool Bullet::outOfMap()
{
	
	if (sprite.getPosition().y < -32)
	{
		return true;
	}
	return false;
}

Bullet::~Bullet()
{
}


void Bullet::move()
{
	sprite.move(vx, vy);
}

Vector2f Bullet::getPosition()
{
	return sprite.getPosition();
}