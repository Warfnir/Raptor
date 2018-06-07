#include "stdafx.h"
#include "Tile.h"


Tile::Tile(float x, float y, int type_of_bg)
{
	type = static_cast<bg_type>(type_of_bg);
	if (type == grass)
	{
		texture.loadFromFile("Images/Background/grass5.png");
		left_neighbours.push_back(new int(4));
		left_neighbours.push_back(new int(5));
		left_neighbours.push_back(new int(10));
		left_neighbours.push_back(new int(13));
		down_neighbours.push_back(new int(5));
		down_neighbours.push_back(new int(8));
		down_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(11));

		right_neighbours.push_back(new int(5));
		right_neighbours.push_back(new int(6));
		right_neighbours.push_back(new int(10));
		right_neighbours.push_back(new int(13));

		up_neighbours.push_back(new int(2));
		up_neighbours.push_back(new int(5));
		up_neighbours.push_back(new int(13));
		up_neighbours.push_back(new int(14));
	}
	else if (type == gw_leftUp)
	{
		texture.loadFromFile("Images/Background/grass_water_leftUp.png");
		left_neighbours.push_back(new int(3));
		left_neighbours.push_back(new int(6));
		left_neighbours.push_back(new int(9));
		left_neighbours.push_back(new int(12));
		down_neighbours.push_back(new int(4));
		down_neighbours.push_back(new int(7));
		down_neighbours.push_back(new int(14));

		right_neighbours.push_back(new int(2));
		right_neighbours.push_back(new int(3));
		right_neighbours.push_back(new int(14));

		up_neighbours.push_back(new int(7));
		up_neighbours.push_back(new int(8));
		up_neighbours.push_back(new int(9));
		up_neighbours.push_back(new int(12));
	}
	else if (type == gw_up)
	{
		texture.loadFromFile("Images/Background/grass_water_up.png");
		left_neighbours.push_back(new int(1));
		left_neighbours.push_back(new int(2));
		left_neighbours.push_back(new int(13));
		down_neighbours.push_back(new int(5));
		down_neighbours.push_back(new int(8));
		down_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(11));

		right_neighbours.push_back(new int(2));
		right_neighbours.push_back(new int(3));
		right_neighbours.push_back(new int(14));

		up_neighbours.push_back(new int(7));
		up_neighbours.push_back(new int(8));
		up_neighbours.push_back(new int(9));
		up_neighbours.push_back(new int(12));
	}
	else if (type == gw_rightUp)
	{
		texture.loadFromFile("Images/Background/grass_water_rightUp.png");
		left_neighbours.push_back(new int(1));
		left_neighbours.push_back(new int(2));
		left_neighbours.push_back(new int(13));
		down_neighbours.push_back(new int(6));
		down_neighbours.push_back(new int(9));
		down_neighbours.push_back(new int(13));

		right_neighbours.push_back(new int(1));
		right_neighbours.push_back(new int(4));
		right_neighbours.push_back(new int(7));
		right_neighbours.push_back(new int(12));

		up_neighbours.push_back(new int(7));
		up_neighbours.push_back(new int(8));
		up_neighbours.push_back(new int(9));
		up_neighbours.push_back(new int(12));
	}
	else if (type == gw_left)
	{
		texture.loadFromFile("Images/Background/grass_water_left.png");
		left_neighbours.push_back(new int(3));
		left_neighbours.push_back(new int(6));
		left_neighbours.push_back(new int(9));
		left_neighbours.push_back(new int(12));
		down_neighbours.push_back(new int(4));
		down_neighbours.push_back(new int(7));
		down_neighbours.push_back(new int(14));

		right_neighbours.push_back(new int(5));
		right_neighbours.push_back(new int(6));
		right_neighbours.push_back(new int(10));
		right_neighbours.push_back(new int(13));

		up_neighbours.push_back(new int(1));
		up_neighbours.push_back(new int(4));
		up_neighbours.push_back(new int(11));
	}
	else if (type == gw_right)
	{
		texture.loadFromFile("Images/Background/grass_water_right.png");
		left_neighbours.push_back(new int(4));
		left_neighbours.push_back(new int(5));
		left_neighbours.push_back(new int(11));
		left_neighbours.push_back(new int(14));
		down_neighbours.push_back(new int(5));
		down_neighbours.push_back(new int(8));
		down_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(11));

		right_neighbours.push_back(new int(1));
		right_neighbours.push_back(new int(4));
		right_neighbours.push_back(new int(7));
		right_neighbours.push_back(new int(12));

		up_neighbours.push_back(new int(3));
		up_neighbours.push_back(new int(6));
		up_neighbours.push_back(new int(10));
	}
	else if (type == gw_leftDown)
	{
		texture.loadFromFile("Images/Background/grass_water_leftDown.png");
		left_neighbours.push_back(new int(3));
		left_neighbours.push_back(new int(6));
		left_neighbours.push_back(new int(9));
		left_neighbours.push_back(new int(12));
		down_neighbours.push_back(new int(1));
		down_neighbours.push_back(new int(2));
		down_neighbours.push_back(new int(3));
		down_neighbours.push_back(new int(12));

		right_neighbours.push_back(new int(8));
		right_neighbours.push_back(new int(9));
		right_neighbours.push_back(new int(11));

		up_neighbours.push_back(new int(1));
		up_neighbours.push_back(new int(4));
		up_neighbours.push_back(new int(11));
		up_neighbours.push_back(new int(14));
	}
	else if (type == gw_down)
	{
		texture.loadFromFile("Images/Background/grass_water_down.png");
		left_neighbours.push_back(new int(7));
		left_neighbours.push_back(new int(8));
		left_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(1));
		down_neighbours.push_back(new int(2));
		down_neighbours.push_back(new int(3));
		down_neighbours.push_back(new int(10));

		right_neighbours.push_back(new int(8));
		right_neighbours.push_back(new int(9));
		right_neighbours.push_back(new int(11));

		up_neighbours.push_back(new int(2));
		up_neighbours.push_back(new int(5));
		up_neighbours.push_back(new int(13));
		up_neighbours.push_back(new int(14));
	}
	else if (type == gw_rightDown)
	{
		texture.loadFromFile("Images/Background/grass_water_rightDown.png");
		left_neighbours.push_back(new int(7));
		left_neighbours.push_back(new int(8));
		left_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(1));
		down_neighbours.push_back(new int(2));
		down_neighbours.push_back(new int(3));
		down_neighbours.push_back(new int(12));

		right_neighbours.push_back(new int(1));
		right_neighbours.push_back(new int(4));
		right_neighbours.push_back(new int(7));
		right_neighbours.push_back(new int(12));

		up_neighbours.push_back(new int(3));
		up_neighbours.push_back(new int(6));
		up_neighbours.push_back(new int(10));
	}
	else if (type == water)
	{

		texture.loadFromFile("Images/Background/water5.png");
		left_neighbours.push_back(new int(3));
		left_neighbours.push_back(new int(6));
		left_neighbours.push_back(new int(9));
		left_neighbours.push_back(new int(12));
		down_neighbours.push_back(new int(1));
		down_neighbours.push_back(new int(2));
		down_neighbours.push_back(new int(3));
		down_neighbours.push_back(new int(12));

		right_neighbours.push_back(new int(1));
		right_neighbours.push_back(new int(4));
		right_neighbours.push_back(new int(7));
		right_neighbours.push_back(new int(12));

		up_neighbours.push_back(new int(7));
		up_neighbours.push_back(new int(8));
		up_neighbours.push_back(new int(9));
		up_neighbours.push_back(new int(12));
	}
	else if (type == wg_leftUp)
	{
		texture.loadFromFile("Images/Background/water_grass_leftUp.png");
		left_neighbours.push_back(new int(4));
		left_neighbours.push_back(new int(5));
		left_neighbours.push_back(new int(13));
		left_neighbours.push_back(new int(14));
		down_neighbours.push_back(new int(6));
		down_neighbours.push_back(new int(9));
		down_neighbours.push_back(new int(13));

		right_neighbours.push_back(new int(8));
		right_neighbours.push_back(new int(9));
		right_neighbours.push_back(new int(11));

		up_neighbours.push_back(new int(2));
		up_neighbours.push_back(new int(5));
		up_neighbours.push_back(new int(13));
		up_neighbours.push_back(new int(14));
	}
	else if (type == wg_rightUp)
	{
		texture.loadFromFile("Images/Background/water_grass_rightUp.png");
		left_neighbours.push_back(new int(7));
		left_neighbours.push_back(new int(8));
		left_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(4));
		down_neighbours.push_back(new int(7));
		down_neighbours.push_back(new int(14));

		right_neighbours.push_back(new int(5));
		right_neighbours.push_back(new int(6));
		right_neighbours.push_back(new int(10));
		right_neighbours.push_back(new int(13));

		up_neighbours.push_back(new int(2));
		up_neighbours.push_back(new int(5));
		up_neighbours.push_back(new int(13));
		up_neighbours.push_back(new int(14));
	}
	else if (type == wg_leftDown)
	{
		texture.loadFromFile("Images/Background/water_grass_leftDown.png");
		left_neighbours.push_back(new int(4));
		left_neighbours.push_back(new int(5));
		left_neighbours.push_back(new int(11));
		left_neighbours.push_back(new int(14));
		down_neighbours.push_back(new int(6));
		down_neighbours.push_back(new int(9));
		down_neighbours.push_back(new int(13));

		right_neighbours.push_back(new int(2));
		right_neighbours.push_back(new int(3));
		right_neighbours.push_back(new int(14));

		up_neighbours.push_back(new int(3));
		up_neighbours.push_back(new int(6));
		up_neighbours.push_back(new int(10));
	}
	else if (type == wg_rightDown)
	{
		texture.loadFromFile("Images/Background/water_grass_rightDown.png");
		left_neighbours.push_back(new int(1));
		left_neighbours.push_back(new int(2));
		left_neighbours.push_back(new int(13));
		down_neighbours.push_back(new int(5));
		down_neighbours.push_back(new int(8));
		down_neighbours.push_back(new int(10));
		down_neighbours.push_back(new int(11));

		right_neighbours.push_back(new int(5));
		right_neighbours.push_back(new int(6));
		right_neighbours.push_back(new int(10));
		right_neighbours.push_back(new int(13));

		up_neighbours.push_back(new int(1));
		up_neighbours.push_back(new int(4));
		up_neighbours.push_back(new int(11));
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
}

Tile::~Tile()
{
}

void Tile::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->sprite, state);
}


void Tile::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}

Sprite Tile::getSprite()
{
	return sprite;
}

void Tile::move(double y)
{
	sprite.move(0, y);
}

Vector2f Tile::getPos()
{
	return sprite.getPosition();
}

