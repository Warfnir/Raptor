#pragma once
#include "stdafx.h"

enum bg_type		//do generowania mapy i sprawdzania warunkow dopasowania
{
	blank = 0,
	//---------------
	gw_leftUp = 1,
	gw_up = 2,
	gw_rightUp = 3,
	gw_left = 4,
	grass = 5,
	gw_right = 6,
	gw_leftDown = 7,
	gw_down = 8,
	gw_rightDown = 9,
	//----------------
	wg_leftUp = 10,
	wg_rightUp = 11,
	water = 12,
	wg_leftDown = 13,
	wg_rightDown = 14,
};