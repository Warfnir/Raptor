#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class Tile:public Drawable
{
private:
	Texture texture;
	Sprite sprite;
	float x_pos;
	float y_pos;

public:
	void draw(RenderTarget &target, RenderStates state)const override;
	Tile(float x, float y);
	Tile();
	~Tile();

	void setPos(float x, float y);
	void did();
	Sprite getSprite();
	void move(double y);
};

