#include "stdafx.h"
#include "standard_bullet.h"


standard_bullet::standard_bullet(float x, float y, float rotate, int upgLvl, Texture &texture)
{

	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.rotate(rotate);
	vx = sin(sprite.getRotation()*3.14 / 180) * 4;
	vy = -cos(sprite.getRotation()*3.14 / 180) * 4;
	sprite.setOrigin(16, 16);
	sprite.setPosition(x, y);
	R = sqrt(8 * 8 * 2);
	dmg = 5 * upgLvl;
	life = true;
}


standard_bullet::~standard_bullet()
{
}
