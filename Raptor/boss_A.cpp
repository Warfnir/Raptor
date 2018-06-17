#include "stdafx.h"
#include "boss_A.h"


boss_A::boss_A(float x, float y, Texture &texture, int lvl)
{
	sprite.setTexture(texture);
	sprite.setOrigin(64, 40);
	sprite.setTextureRect(IntRect(0, 0, 128, 110));
	R = sqrt(32 * 32 * 2);
	sprite.setPosition(x, y);
	out = false;
	points = 500;
	HP = 1000*lvl;
	bullets_counter = 0;
	begin_fight = false;
	attack_A = false;
	attack_B = false;
	attack_C = false;
	xmax = 600;
	ymax = 300;
	vx = 0;
	vy = 1;
	level = 1;
	maxV = 1;
	rotation = 180;
}


boss_A::~boss_A()
{
}


void boss_A::move()
{
	if (!begin_fight)
	{
		sprite.move(vx, vy);
		if (sprite.getPosition().y > 150)
		{
			begin_fight = true;
			attack_A = true;
			shoot_delay.restart();
			
		}
	}
	else if (right_direction)
	{
		rotation -= 0.5;
		vx = sin(rotation*3.14 / 180);
		vy = -cos(rotation*3.14 / 180);
		sprite.move(vx, vy);
		if (rotation <= -180)
		{
			right_direction = false;
			rotation = 180;
		}
	}
	else
	{
		rotation += 0.5;
		vx = sin(rotation*3.14 / 180);
		vy = -cos(rotation*3.14 / 180);
		sprite.move(vx, vy);
		if (rotation>=540 )
		{
			right_direction = true;
			rotation = 180;
		}
	}
}

void boss_A::shoot(vector<Bullet*> &vec, Texture &texture)
{
	if (attack_A && shoot_delay.getElapsedTime().asMilliseconds()>2000)
	{
		for (int i = 0; i < 36; i++)
		{
			vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, i * 10, level, texture));
		}
		bullets_counter++;
		shoot_delay.restart();
		if (bullets_counter > 3)
		{
			attack_A = false;
			attack_B = true;
			bullets_counter = 0;
		}

	}
	else if (attack_B && shoot_delay.getElapsedTime().asMilliseconds()>500)
	{
		vec.push_back(new rocket(sprite.getPosition().x-30, sprite.getPosition().y+20, 180, level,texture));
		vec.push_back(new rocket(sprite.getPosition().x+30, sprite.getPosition().y+20, 180, level,texture));
		bullets_counter++;
		shoot_delay.restart();
		if (bullets_counter > 9)
		{
			attack_B = false;
			attack_A = true;
			bullets_counter = 0;
		}
	}
	/*
	else if(attack_C && shoot_delay.getElapsedTime().asMilliseconds()>400)
	{

	}*///niegotowy atak
}
void boss_A::shoot2(vector<Bullet*> &vec, Texture &bul_texture, Texture &roc_texture)
{
	if (attack_A && shoot_delay.getElapsedTime().asMilliseconds()>2000)
	{
		for (int i = 0; i < 36; i++)
		{
			vec.push_back(new standard_bullet(sprite.getPosition().x, sprite.getPosition().y, i * 10, level, bul_texture));
		}
		bullets_counter++;
		shoot_delay.restart();
		if (bullets_counter > 3)
		{
			attack_A = false;
			attack_B = true;
			bullets_counter = 0;
		}

	}
	else if (attack_B && shoot_delay.getElapsedTime().asMilliseconds()>500)
	{
		vec.push_back(new rocket(sprite.getPosition().x - 30, sprite.getPosition().y + 20, 180, level, roc_texture));
		vec.push_back(new rocket(sprite.getPosition().x + 30, sprite.getPosition().y + 20, 180, level, roc_texture));
		bullets_counter++;
		shoot_delay.restart();
		if (bullets_counter > 9)
		{
			attack_B = false;
			attack_A = true;
			bullets_counter = 0;
		}
	}
	/*
	else if(attack_C && shoot_delay.getElapsedTime().asMilliseconds()>400)
	{

	}*///niegotowy atak
}
void boss_A::aim(vector<Bullet*> &vec, Vector2f pos)
{

}