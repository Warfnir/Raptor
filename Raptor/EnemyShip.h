#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class EnemyShip : public Ship
{
protected:
	int way;
	bool out;
	int points;
	int level;
public:
	EnemyShip();
	~EnemyShip();
	void outOfWindow() override;
	bool getOut();
	int getPoints();
	double getLife();
};

