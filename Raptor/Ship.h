#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class Ship : public object
{
protected:
	int HP;
	double SHIELD;
	Clock shoot_delay;
	

public:
	
	virtual void shoot(vector<Bullet*> &vec, Texture &texture) = 0;
	virtual void move() = 0;
	virtual void outOfWindow()=0;
	void gotHit(double dmg);
	Ship();
	~Ship();
};

