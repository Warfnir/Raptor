#include "stdafx.h"
#include "laser.h"


laser::laser(Vector2f pos, double rotation, Texture &texture)
{
	for (int i = 0; i < 63; i++)
	{
		vec.push_back(new Sprite(texture));
	}
	for (int i = 0; i < 63; i++)
	{
		vec[i]->rotate(rotation);
		vec[i]->setPosition(pos.x+i*16,0);
	}
}


laser::~laser()
{
}
