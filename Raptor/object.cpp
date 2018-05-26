#include "stdafx.h"
#include "object.h"

void object::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->sprite, state);
}

Vector2f object::getPosition()
{
	return sprite.getPosition();
}

double object::getR()
{
	return R;
}