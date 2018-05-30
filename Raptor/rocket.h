#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
class rocket:public Bullet
{
public:
	rocket(float x, float y, float rotate, int upgLvl);
	~rocket();
};

