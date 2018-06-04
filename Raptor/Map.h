#pragma once
#include "stdafx.h"
#include "Tile.h"
using namespace sf;
using namespace std;

typedef vector< vector<Tile*> > matrix;


class Map
{
private:
	matrix mat;
	vector <vector<Tile*>*> mapa;
	vector <vector<Tile>> mapa2;
public:
	friend class Tile;
	Map();
	~Map();
	void draw(RenderWindow &window);
	void update();
	void generateMap();
	
};

