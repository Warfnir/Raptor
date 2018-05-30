#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class rocket_explode_animation : public animation
{
private:
	Clock explosion_time;
	bool end;
public:
	void next_frame();
	bool end_animation();
public:
	rocket_explode_animation(Vector2f pos);
	~rocket_explode_animation();
};

