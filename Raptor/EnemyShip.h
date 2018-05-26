#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class EnemyShip : public Ship
{
protected:
	int way;
	bool to_destroy;
public:
	EnemyShip();
	~EnemyShip();

	
};

