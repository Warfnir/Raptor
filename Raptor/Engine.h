#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class Engine
{
private:
	//friend classes
	//potrzebne by zawieral wektory
	//do tych klas
	friend class MyShip;
	friend class EnemyShip;
	friend class Bullet;
	friend class Map;
	friend class animation;

	RenderWindow window;
	Event eve;
	Texture bg_texture;
	Sprite bg_sprite1;
	Sprite bg_sprite2;
	//Map mapa;		MAPA NIE DZIALA
	//wektory do statkow i pociskow
	//-----------------------------
	//vector <MyShip*> myShip;
	MyShip *myShip;
	vector <EnemyShip*> enemyShips;
	//-----------------------------
	vector <Bullet*> myBullet;
	vector <Bullet*> enemyBullet;
	//-----------------------------
	vector <animation*> animations;
	//-----------------------------
	//MUSIC
	Music main_music;
public:
	
	bool window_ok();		//zwraca czy okno dziala
	void display_window();	//wyswietla okno
	bool isCollision(Vector2f a, double Ra, Vector2f b, double Rb);		//zwraca czy obiekty koliduj¹
	void drawAll();			//rysuje wszystkich na ekranie
	void move_All();		//przesuwa obiekty
	void update_colission();
	RenderWindow* getWindow();
	Event getEvent();
	void start();
	void update_backGround();
	void check_bullets();
	//------
	Engine();
	~Engine();
};

