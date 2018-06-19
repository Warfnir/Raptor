#pragma once
#include "stdafx.h"
#include "Ship.h"
#include "Bullet.h"
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
	
	void shoot(vector<Bullet*> &vec, Texture &texture);
	void shoot2(vector<Bullet*> &vec, Texture &bul_texture, Texture &roc_texture);
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
	void move_back();
	void reset();
	void setStats(int gameLv, int maxLife, int actLife, int shield, int pt, int bulletLvl, int rocketLvl, int laserLvl);

	MyShip(Texture &tex);
	~MyShip();
};

