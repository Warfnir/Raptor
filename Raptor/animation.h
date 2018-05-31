#pragma once
#include "stdafx.h"
class animation : public Drawable
{
protected:
	Sprite sprite;
	Texture texture;
	Music sound;
public:
	animation();
	~animation();
	void draw(RenderTarget &target, RenderStates state)const override;
};

