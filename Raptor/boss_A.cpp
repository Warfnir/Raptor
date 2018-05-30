#include "stdafx.h"
#include "boss_A.h"


boss_A::boss_A(float x, float y)
{
	if (!texture.loadFromFile("enemy.png"))
	{
		cout << "Can't load enemy.png\n";
	}
	sprite.setTexture(texture);
	sprite.setOrigin(64, 32);
	sprite.setTextureRect(IntRect(0, 0, 128, 110));
	R = sqrt(32 * 32 * 2);
	sprite.setPosition(x, y);
	out = false;
	points = 500;
	HP = 1000;
}


boss_A::~boss_A()
{
}


void boss_A::move()
{

}

void boss_A::shoot(vector<Bullet*> &vec)
{
	/*
	if (shoot_delay.getElapsedTime().asMilliseconds > 200)
	{
		//shoot hier
		//shoot_delay.restart();
		//shooting_pause++;
	}*/
}
void boss_A::aim(vector<Bullet*> &vec, Vector2f pos)
{

}