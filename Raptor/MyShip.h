#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class MyShip : public Ship
{
private:
	double cash;
	double points;
	int game_lvl;

public:
	friend class Engine;
	void shoot(vector<Bullet*> &vec);
	void move();
	Sprite getSprite();
	void getData();
	Vector2f getPosition();
	void outOfWindow();
	void grantPoints(double pt);

	bool left, right, up, down;
	

	MyShip();
	~MyShip();
};

