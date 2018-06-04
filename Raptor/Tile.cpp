#include "stdafx.h"
#include "Tile.h"


Tile::Tile(float x, float y)
{
	texture.loadFromFile("water5.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
}
Tile::Tile()
{

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

void Tile::did()
{
	cout<<"DID ";
}

Sprite Tile::getSprite()
{
	return sprite;
}

void Tile::move(double y)
{
	sprite.move(0, y);
}