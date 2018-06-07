#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
class laser :public Bullet
{
private:
	vector <Sprite*> vec;
public:
	
	laser(Vector2f pos, double rotation);
	~laser();
};

