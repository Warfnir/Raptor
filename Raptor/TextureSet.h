#pragma once
#include "stdafx.h"

using namespace sf;

class TextureSet
{
private:
public:
	//TLO
	Texture grass_water_down;
	Texture grass_water_left;
	Texture grass_water_up;
	Texture grass_water_right;
	Texture grass_water_rightDown;
	Texture grass_water_rightUp;
	Texture grass_water_leftDown;
	Texture grass_water_leftUp;
	Texture water_grass_leftUp;
	Texture water_grass_leftDown;
	Texture water_grass_rightUp;
	Texture water_grass_rightDown;
	Texture gras5;
	Texture water5;

	//STATKI
	Texture ship_bae;
	Texture Ship;
	Texture enemy;

	//BONUSY
	Texture bonus_health;
	Texture bonus_shield;
	Texture bonus_points;
	
	//POCISKI
	Texture bullet;
	Texture laser;
	Texture rocket;
	
	//EFEKTY SPECJALNE
	Texture bullet_explode;
	Texture rocket_explode;


	friend class Engine;
	static TextureSet& getInstance();
	TextureSet(TextureSet const&) = delete;
	void operator=(TextureSet const&) = delete;
	TextureSet();
	~TextureSet();
};

