#pragma once
#include "stdafx.h"
class animation : public Drawable
{
protected:
	Sprite sprite;
	Music sound;
public:
	animation();
	~animation();
	void draw(RenderTarget &target, RenderStates state)const override;
};

