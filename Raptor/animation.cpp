#include "stdafx.h"
#include "animation.h"


animation::animation()
{
}


animation::~animation()
{
}

void animation::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->sprite, state);
}


