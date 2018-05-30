#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	
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
	
	if (sprite.getPosition().y < -32 || sprite.getPosition().y >632 || sprite.getPosition().x<-32 || sprite.getPosition().x >832)
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