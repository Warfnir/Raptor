#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
class boss_A :public EnemyShip
{
private:
	float xmax;
	float ymax;
	bool right_direction;
	bool begin_fight;
	bool attack_A;
	bool attack_B;
	bool attack_C;
	int bullets_counter;
	int level;
	Clock shoot_delay;
	double maxV;
	float rotation;
public:
	boss_A(float x, float y, Texture &texture, int lvl);
	~boss_A();

	void shoot(vector<Bullet*> &vec, Texture &texture);	//strzal 
	void shoot2(vector<Bullet*> &vec, Texture &bul_texture, Texture &roc_texture);
	void aim(vector<Bullet*> &vec, Vector2f pos);	//sprawdza polozenie naszego statku i w odpowiednim momencie strzela
	void move();
	void trace(Vector2f pos); //require position of the enemy
};

