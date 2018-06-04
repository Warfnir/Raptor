#pragma once
#include "stdafx.h"

class B0_ship:public EnemyShip
{
private:
 
public:
	

	B0_ship(int x, int y, int lvl);
	~B0_ship();

	void shoot(vector<Bullet*> &vec);	//strzal 
	void aim(vector<Bullet*> &vec, Vector2f pos);	//sprawdza polozenie naszego statku i w odpowiednim momencie strzela
	void move();
	void trace(Vector2f pos); //require position of the enemy
};

