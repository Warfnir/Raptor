#pragma once
#include "stdafx.h"
#include "Tile.h"
using namespace sf;
using namespace std;

typedef vector< vector<Tile*> > matrix;


class Map
{
private:
	matrix mat;	//macierz - mapa m x n
public:
	friend class Tile;
	Map();
	~Map();
	void draw(RenderWindow &window);	//rysuje mape
	void move();	//przesuwa cala mape w dol
	void mapOutOfWindow();	//usuwa wiersz mapy poza oknem i generuje nowy od gory

	int generate_next_tile(Tile &left, Tile &down);	//porownuje zawartosci z lewej i prawej strony, zwraca nr potrzebnej plytki
	int generate_next_tile(Tile &down);	//porownuje zawartosci z prawej strony, zwraca nr potrzebnej plytki
	void generateMap();
	void update();
};

