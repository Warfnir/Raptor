#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class Bullet : public object
{
private:
	int dmg;
	bool life;
public:
	void move();
	bool outOfMap();
	Bullet(float, float);
	~Bullet();
	double getDmg();
	bool getLife();
	void destroy();
	Vector2f getPosition();
};
