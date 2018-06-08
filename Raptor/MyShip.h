#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class MyShip : public Ship
{
private:
	int points;
	int game_lvl;
	int maxHp;

	int bullet_upg;
	int rocket_upg;
	int laser_upg;
	bool left, right, up, down;
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


	void nextLevel();//zwieksza poziom - nastepna iteracja

	//zwracata wartosci podstawowych statystyk
	int getBulletLevel();
	int getRocketLevel();
	int getLaserLevel();
	int getMaxHp();
	int getActHp();
	int getActShield();

	void rocketUp();//zwieksza obrazenia rakiet
	void bulletUp();//zwieksza obrazenia podstawowego ataku
	void maxHpUp();	//zwieksza max hp
	void heal();	//leczy do max hp

	void bonusPoint(int bonus);	//dodaje bonusowe punty
	void bonusHealth(int bonus);//reneneruje zycie
	void bonusShield(int bonus);//zwieksza tarcze

	
	int getGameLevel();			//zwraca aktualny poziom gry - iteracje

	//do wczytywania gry
	void setStats(int gmLvl, int maxHitPoints, int actHitPoints, int actPoints, int bulLvl, int rockLvl, int actShields, int lasLvl);

	

	MyShip();
	~MyShip();
};

