#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	//USTALAMY ROZMIAR WEKTOROW I POLOZENIE PLYTEK
	mat.resize(30);
	for (int i = 0; i < mat.size(); i++)
	{
		mat[i].resize(25);
	}

}



Map::~Map()
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			delete mat[i][j];
		}
	}
}

//RYSUJE CALA MAPE
void Map::draw(RenderWindow &window)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[j].size(); j++)
		{
			window.draw(*mat[i][j]);
		}
	}
	
}

//PRZESUWA CALA MAPE
void Map::move()
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[j].size(); j++)
		{
			mat[i][j]->move();
		}
	}
}

int Map::generate_next_tile(Tile &left, Tile &down)
{
	vector <int*> available;
	for (int i=0;i<left.right_neighbours.size();i++)
	{
		for (int j=0;j<down.up_neighbours.size();j++)
		{
			if (*left.right_neighbours[i] == *down.up_neighbours[j])
			{
				available.push_back(new int(*left.right_neighbours[i]));
			}
		}
	}
	int cos = *available[rand() % available.size()];
	return cos;
}

int Map::generate_next_tile(Tile &down)
{
	int i = *down.up_neighbours[rand() % down.up_neighbours.size()];
	return i;
}



//USUWA WIERSZ MAPY JESLI WYJDZIE POZA OKNO,
//GENERUJE NOWY WIERSZ
void Map::mapOutOfWindow()
{

	if (mat[0][0]->getPos().y > 632)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			delete mat[0][j];
		}
		mat.erase(mat.begin());


		//create new line at the top
		mat.push_back(vector <Tile*>());
		mat.back().resize(25);
		int size = mat.size() - 1;
		for (int i = 0; i < mat.back().size(); i++)
		{
			if (i == 0)
			{
				int g = generate_next_tile(*mat[size-1][i]);
				mat[size][i] = new Tile(i * 32, 600 - (size-1) * 32 +1, static_cast<bg_type>(g));
			}
			else
			{
				int g = generate_next_tile(*mat[size][i - 1], *mat[size - 1][i]);
				mat[size][i] = new Tile(i * 32, 600 - (size-1) * 32 +1, static_cast<bg_type>(g));
			}
		}
	}
}

void Map::generateMap()
{
	for (int i = 0; i < mat[0].size(); i++)
	{
		mat[0][i] = new Tile(i * 32, 600 - 32, water);
	}
	for (int i = 1; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (j == 0)
			{
				int g = generate_next_tile(*mat[i - 1][j]);
				mat[i][j] = new Tile(j * 32, 600 - i * 32, static_cast<bg_type>(g));
			}
			else
			{
				int g = generate_next_tile(*mat[i][j - 1], *mat[i - 1][j]);
				mat[i][j] = new Tile(j * 32, 600 - i * 32, static_cast<bg_type>(g));
			}
		}
	}
}