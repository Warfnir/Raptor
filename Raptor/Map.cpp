#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	mat.resize(50);
	for (int i = 0; i < 50; i++)
	{
		mat[i].resize(30);
		for (int j = 0; j < 30; j++)
		{
			mat[i][j] = new Tile(j * 32, 600 - i * 32);
		}
	}
}



Map::~Map()
{
}

void Map::draw(RenderWindow &window)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			window.draw(*mat[i][j]);
			mat[i][j]->move(0.4);
		}
	}
}

void Map::update()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			mat[i][j]->move(1);
		}
	}
}
