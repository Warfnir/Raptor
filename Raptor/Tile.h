#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
#include"bg_enum.h"


class Tile:public Drawable
{
private:
	//Textury tla, 14 kratek wzajemnie dopasowanych
	/*static Texture grass;
	static Texture water;
	static Texture gw_left;
	static Texture gw_right;
	static Texture gw_up;
	static Texture gw_down;
	static Texture gw_leftUp;
	static Texture gw_leftDown;
	static Texture gw_rightUp;
	static Texture gw_rightDown;
	static Texture wg_leftUp;
	static Texture wg_leftDown;
	static Texture wg_rightUp;
	static Texture wg_rightDown;*/
	Sprite sprite;
	bg_type type;
	
	Texture texture;
	float x_pos;
	float y_pos;

	vector <int*> left_neighbours;
	vector <int*> right_neighbours;
	vector <int*> up_neighbours;
	vector <int*> down_neighbours;
public:
	friend class Map;
	Tile(float x, float y, int type_of_bg);
	~Tile();

	void draw(RenderTarget &target, RenderStates state)const override;

	void setPos(float x, float y);
	Sprite getSprite();
	void move(double y);
	Vector2f getPos();
};

