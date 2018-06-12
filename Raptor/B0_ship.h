#pragma once
#include "stdafx.h"

class B0_ship:public EnemyShip
{
private:
 
public:
	

	B0_ship(int x, int y, int lvl, Texture &texture);
	~B0_ship();

	void shoot(vector<Bullet*> &vec, Texture &texture);	//strzal 
	void aim(vector<Bullet*> &vec, Vector2f pos, Texture &texture);	//sprawdza polozenie naszego statku i w odpowiednim momencie strzela
	void move();
	void trace(Vector2f pos); //require position of the enemy
};

