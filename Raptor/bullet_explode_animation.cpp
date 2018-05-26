#include "stdafx.h"
#include "bullet_explode_animation.h"


bullet_explode_animation::bullet_explode_animation(Vector2f pos)
{
	texture.loadFromFile("bullet_explode.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
	sprite.setPosition(pos);
	end = false;
}


bullet_explode_animation::~bullet_explode_animation()
{
}

void bullet_explode_animation::next_frame()
{
	if (explosion_time.getElapsedTime().asMilliseconds() > 100)
	{
		IntRect rect = sprite.getTextureRect();
		if (rect.left >= 64)
		{
			end = true;
		}
		rect.left = rect.left + 16;
		sprite.setTextureRect(rect);
		explosion_time.restart();
	}
}
bool bullet_explode_animation::end_animation()
{
	return end;
}
