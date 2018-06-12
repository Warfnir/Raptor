#pragma once
#include"stdafx.h"
using namespace sf;
using namespace std;

class bonus :public object
{
private:
	int bonusHP;
	int bonusSHield;
	int bonusPoints;
	Clock nextFrame;

	bool life;
public:
	void move() ;
	Vector2f getPosition();
	double getR();
	void changeFrame();
	bool getLife();
	void outOfWindow();
	void giveBonus(MyShip &ship);

	bonus(Vector2f pos, int type, int level, Texture &texture);
	~bonus();
};

