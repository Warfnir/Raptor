#include "stdafx.h"
#include "EnemyShip.h"


EnemyShip::EnemyShip()
{
	
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::outOfWindow()
{
	if (sprite.getPosition().y > 632)
	{
		out = true;
	}
}

bool EnemyShip::getOut()
{
	return out;
}

int EnemyShip::getPoints()
{
	return points;
}

double EnemyShip::getLife()
{
	return HP;
}
