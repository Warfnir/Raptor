#include "stdafx.h"
#include "rocket_explode_animation.h"


rocket_explode_animation::rocket_explode_animation(Vector2f pos)
{
	texture.loadFromFile("rocket_explode.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setOrigin(16, 16);
	sprite.setPosition(pos);
	end = false;
}


rocket_explode_animation::~rocket_explode_animation()
{
}

void rocket_explode_animation::next_frame()
{
	if (explosion_time.getElapsedTime().asMilliseconds() > 40)
	{
		IntRect rect = sprite.getTextureRect();
		if (rect.left >= 224)
		{
			end = true;
		}
		rect.left = rect.left + 32;
		sprite.setTextureRect(rect);
		explosion_time.restart();
	}
}
bool rocket_explode_animation::end_animation()
{
	return end;
}

