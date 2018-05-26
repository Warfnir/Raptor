#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}


void Ship::gotHit(double dmg)
{
	HP -= dmg;
}