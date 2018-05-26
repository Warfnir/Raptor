#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class EnemyShip : public Ship
{
protected:
	int way;
	bool out;
	double points;
public:
	EnemyShip();
	~EnemyShip();
	void outOfWindow() override;
	bool getOut();
	double getPoints();
	double getLife();
};

