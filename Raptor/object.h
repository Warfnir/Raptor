#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;

class object:public Drawable
{
protected:
	Texture texture;	//textura
	Sprite sprite;		//sprite
	double R;
	double vx;
	double vy;

public:
	void draw(RenderTarget &target, RenderStates state)const override;
	virtual void move()=0;
	virtual Vector2f getPosition();
	virtual double getR();
};