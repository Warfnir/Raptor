#pragma once
#include"stdafx.h"
using namespace sf;
using namespace std;

class bullet_explode_animation :public animation
{
private:
	Clock explosion_time;
	bool end;
public:
	bullet_explode_animation(Vector2f pos, Texture &texture);
	~bullet_explode_animation();
	void next_frame();
	bool end_animation();
};

