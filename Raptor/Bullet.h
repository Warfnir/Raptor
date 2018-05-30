#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class Bullet : public object
{
protected:
	int dmg;
	bool life;
public:
	void move();
	bool outOfMap();
	Bullet(); 
	~Bullet();
	double getDmg();
	bool getLife();
	void destroy();
	Vector2f getPosition();
};

