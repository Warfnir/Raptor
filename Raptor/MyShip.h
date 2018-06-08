#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class MyShip : public Ship
{
private:
	double cash;
	int points;
	int game_lvl;
	int maxHp;

	int bullet_upg;
	int rocket_upg;
	int laser_upg;

	Clock rocket_delay;
public:
	friend class Engine;
	
	void shoot(vector<Bullet*> &vec);
	void move();
	Sprite getSprite();
	void getData();
	Vector2f getPosition();
	void outOfWindow();
	void grantPoints(int pt);
	int getPoints();
	void gotHit(int dmg);
	int getLife();
	bool left, right, up, down;
	void nextLevel();
	int getBulletLevel();
	int getRocketLevel();
	int getMaxHp();
	int getActHp();

	void rocketUp();
	void bulletUp();
	void maxHpUp();
	void heal();

	void bonusPoint(int bonus);
	void bonusHealth(int bonus);
	void bonusShield(int bonus);

	int getGameLevel();

	

	MyShip();
	~MyShip();
};

