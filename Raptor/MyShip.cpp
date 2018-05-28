#include "stdafx.h"
#include "MyShip.h"


MyShip::MyShip()
{
	//load texture and set sprite
	if (!texture.loadFromFile("ship_bae.png"))
	{
		cout << "Can't open Ship.png\n";
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(380, 300);
	vx = 0.0f;
	vy = 0.0f;
	sprite.setOrigin(16, 16);
	
	//basic stats
	left = right = up = down = 0;
	R = sqrt(16*16*2);
	HP = 100;
	SHIELD = 100;
	points = 0;
	
}
/////////////////////////////////////////
MyShip::~MyShip()
{
}
/////////////////////////////////////////
void MyShip::outOfWindow()
{
	if (sprite.getPosition().x + R > 800)
	{
		sprite.setPosition(800 - R, sprite.getPosition().y);
	}
	if (sprite.getPosition().x - R <0)
	{
		sprite.setPosition(0 + R, sprite.getPosition().y);
	}
	if (sprite.getPosition().y + R > 600)
	{
		sprite.setPosition(sprite.getPosition().x, 600-R);
	}
	if (sprite.getPosition().y - R < 0)
	{
		sprite.setPosition(sprite.getPosition().x, 0+R);
	}
}
/////////////////////////////////////////

Sprite MyShip::getSprite()
{
	return sprite;
}

/////////////////////////////////////////
void MyShip::shoot(vector<Bullet*> &vec)
{
	if (shoot_delay.getElapsedTime().asMilliseconds() > 100)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;
		vec.push_back(new Bullet(x - 12, y - 16,0,true));
		vec.push_back(new Bullet(x + 4, y - 16,0,true));
		shoot_delay.restart();
	}
}

/////////////////////////////////////////

void MyShip::move()
{
	if (left)
	{
		vx = -4;
		sprite.setTextureRect(IntRect(0, 33, 32, 64));
	}
	if (right)
	{
		vx = 4;
		sprite.setTextureRect(IntRect(33, 0, 64, 32));
	}
	if (left == 0 && right == 0)
	{
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	if (up)
	{
		vy = -4;
	}
	if (down)
	{
		vy = 4;
	}
	left= right = up = down = 0;
	sprite.move(vx, vy);
	vx = vy = 0;
	
}

void draw()
{

}

void MyShip::getData()
{
	cout << this->vx << "  " << this->vy<<endl;
}

Vector2f MyShip::getPosition()
{
	return sprite.getPosition();
}

void MyShip::grantPoints(int pt)
{
	points += pt;
}

int MyShip::getPoints()
{
	return points;
}

void MyShip::gotHit(int dmg)
{
	HP -= dmg;
}