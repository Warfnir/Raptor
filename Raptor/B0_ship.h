#pragma once
#include "stdafx.h"

class B0_ship:public EnemyShip
{
private:
 
public:
	B0_ship(int x, int y);
	~B0_ship();

	void shoot(vector<Bullet*> &vec);
	void move();
	void trace(Vector2f pos); //require position of the enemy
};

