#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class B1_ship :public EnemyShip
{
private:
	bool bul1;
	bool bul2;
	bool bul3;
	bool bul4;

	double rotation;
public:
	B1_ship(float x , float y, int lvl, Texture &texture);
	~B1_ship();



	void shoot(vector<Bullet*> &vec, Texture &texture);	//strzal 
	void move();	//sciezka statku

};

