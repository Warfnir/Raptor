#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class standard_bullet:public Bullet
{
private:

public:
	
	//------------------------------------------------------------
	standard_bullet(float x, float y, float rotate, int upgLvl);	//xy defines position, rotates sprite, upgLvl defines DMG
	~standard_bullet();
};

