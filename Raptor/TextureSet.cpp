#include "stdafx.h"
#include "TextureSet.h"


TextureSet::TextureSet()
{
	//TLO
	 grass_water_down.loadFromFile("Images/Background/grass_water_down.png");
	grass_water_left.loadFromFile("Images/Background/grass_water_left.png");
	grass_water_up.loadFromFile("Images/Background/grass_water_up.png");
	grass_water_right.loadFromFile("Images/Background/grass_water_right.png");
	grass_water_rightDown.loadFromFile("Images/Background/grass_water_rightDown.png");
	grass_water_rightUp.loadFromFile("Images/Background/grass_water_rightUp.png");
	grass_water_leftDown.loadFromFile("Images/Background/grass_water_leftDown.png");
	grass_water_leftUp.loadFromFile("Images/Background/grass_water_leftUp.png");
	water_grass_leftUp.loadFromFile("Images/Background/water_grass_leftUp.png");
	water_grass_leftDown.loadFromFile("Images/Background/water_grass_leftDown.png");
	water_grass_rightUp.loadFromFile("Images/Background/water_grass_rightUp.png");
	water_grass_rightDown.loadFromFile("Images/Background/water_grass_rightDown.png");
	gras5.loadFromFile("Images/Background/grass5.png");
	water5.loadFromFile("Images/Background/water5.png");

	//STATKI
	ship_bae.loadFromFile("Images/Ships/ship_bae.png");
	Ship.loadFromFile("Images/Ships/Ship.png");
	enemy.loadFromFile("Images/Ships/enemy.png");

	//BONUSY
	bonus_health.loadFromFile("Images/Bonuses/bonus_health.png");
	bonus_shield.loadFromFile("Images/Bonuses/bonus_shield.png");
	bonus_points.loadFromFile("Images/Bonuses/bonus_points.png");

	//POCISKI
	bullet.loadFromFile("Images/Bullets/bullet.png");
	laser.loadFromFile("Images/Bullets/laser.png");
	rocket.loadFromFile("Images/Bullets/rocket.png");

	//EFEKTY SPECJALNE
	bullet_explode.loadFromFile("Images/Special_effects/bullet_explode.png");
	rocket_explode.loadFromFile("Images/Special_effects/rocket_explode.png");
}


TextureSet::~TextureSet()
{
}

TextureSet& TextureSet::getInstance()

{
	static TextureSet instance;
	return instance;
}
