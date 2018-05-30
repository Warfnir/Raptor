#include "stdafx.h"
#include "bonus.h"


bonus::bonus(Vector2f pos, int type, int level)
{
	if (type < 7)
	{
		bonusPoints = level * 100;
		bonusHP = false;
		bonusSHield = false;
		texture.loadFromFile("bonus_points.png");
	}
	else if (type > 9)
	{
		bonusPoints = 0;
		bonusHP = true;
		bonusSHield = false;
		texture.loadFromFile("bonus_health.png");
	}
	else
	{
		bonusPoints = 0;
		bonusHP = false;
		bonusSHield = true;
		texture.loadFromFile("bonus_shield.png");
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(pos);
	R = sqrt(16 * 16 * 2);
	vx = 0;
	vy = 1;
	life = true;
}


bonus::~bonus()
{
}

double bonus::getR()
{
	return R;
}

Vector2f bonus::getPosition()
{
	return sprite.getPosition();
}

void bonus::move()
{
	sprite.move(vx, vy);
}

void bonus::changeFrame()
{
	if (nextFrame.getElapsedTime().asMilliseconds() > 200)
	{
		if (sprite.getTextureRect().left >= 128)
		{
			sprite.setTextureRect(IntRect(0, 0, 32, 32));
		}
		else
		{
			sprite.setTextureRect(IntRect(sprite.getTextureRect().left + 32, 0, 32, 32));
		}
		nextFrame.restart();
	}
}

void bonus::outOfWindow()
{
	if (sprite.getPosition().y > 632)
	{
		life = false;
	}
}

bool bonus::getLife()
{
	return life;
}