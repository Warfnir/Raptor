#pragma once
#include "stdafx.h"
#include "Map.h"
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
	friend class bonus;

	RenderWindow window;
	Event eve;
	
	TextureSet* textureSet;
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
	vector <bonus*> bonuses;
	//MUSIC
	Music main_music;
	//texts
	Text myPoints;
	Font font;
	Map mapa;
	

	//elementy rozgrywki
	int wave;
	bool okno_menu;
	bool okno_sklepu;
	bool okno_walki;

public:
	bool ifShop();
	bool ifMenu();
	bool ifFight();
	//-------------------------------------------------------------------------------------------------
	bool window_ok();		//zwraca czy okno dziala
	//-------------------------------------------------------------------------------------------------
	void menu();
	void load();
	//------------------------------------------------------------------------------------------------
	void open_item_shop();	//otwiera sklep po zakonczonej walce
	void save();
	//------------------------------------------------------------------------------------------------
	void start();
	void next_wave();		//generuje kolejnych przeciwników
	bool isCollision(Vector2f a, double Ra, Vector2f b, double Rb);		//zwraca czy obiekty koliduj¹
	void drawAll();			//rysuje wszystkich na ekranie
	void move_All();		//przesuwa obiekty
	void update_colission();//sprawdza wszytskie kolizje
	void updateNumberOfEnemies(); //dla celow testowych, dodaje nowych przeciwnikow
	//-------------------------------------------------------------------------------------------------
	void clear_memory();
	void game_Lost();
	Engine();
	~Engine();
};

