#include "stdafx.h"
#include "MyShip.h"


MyShip::MyShip(Texture &tex)
{
	//load texture and set sprite
	/*if (!texture.loadFromFile("ship_bae.png"))
	{
		cout << "Can't open Ship.png\n";
	}*/
	tex.setSmooth(true);
	sprite.setTexture(tex);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(384, 500);
	vx = 0.0f;
	vy = 0.0f;
	sprite.setOrigin(16, 16);
	
	//basic stats
	left = right = up = down = 0;
	R = sqrt(8*8*2);

	//HP SHIELDS POINTS
	maxHp = 100;
	HP = 100;
	SHIELD = 100;
	points = 0;
	game_lvl = 1;

	//bullets
	laser_upg = 0;
	rocket_upg = 0;
	bullet_upg = 1;
	
	
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
void MyShip::shoot(vector<Bullet*> &vec, Texture &texture)
{

}
void MyShip::shoot2(vector<Bullet*> &vec, Texture &bul_texture, Texture &roc_texture)
{
	if (shoot_delay.getElapsedTime().asMilliseconds() > 150)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;
		vec.push_back(new standard_bullet(x - 12, y - 16, 0, bullet_upg, bul_texture));
		vec.push_back(new standard_bullet(x + 4, y - 16, 0, bullet_upg, bul_texture));
		shoot_delay.restart();
	}
	if (rocket_delay.getElapsedTime().asMilliseconds() > 500 && rocket_upg>0)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;
		vec.push_back(new rocket(x - 12, y - 16, 0, bullet_upg, roc_texture));
		rocket_delay.restart();
	}
}
/////////////////////////////////////////

void MyShip::move()
{
	if (left)
	{
		vx = -2;
		sprite.setTextureRect(IntRect(0, 33, 32, 64));
	}
	if (right)
	{
		vx = 2;
		sprite.setTextureRect(IntRect(33, 0, 64, 32));
	}
	if (left == 0 && right == 0)
	{
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	if (up)
	{
		vy = -2;
	}
	if (down)
	{
		vy = 2;
	}
	left= right = up = down = 0;
	sprite.move(vx, vy);
	vx = vy = 0;
	
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

int MyShip::getGameLevel()
{
	return game_lvl;
}

int MyShip::getLife()
{
	return HP;
}

void MyShip::nextLevel()
{
	game_lvl++;
}

int MyShip::getBulletLevel()
{
	return bullet_upg;
}
int MyShip::getRocketLevel()
{
	return rocket_upg;
}
int MyShip::getMaxHp()
{
	return maxHp;

}
int MyShip::getActHp()
{
	return HP;

}

void MyShip::rocketUp()
{
	points -= rocket_upg * 200 + 300;
	rocket_upg++;
}
void MyShip::bulletUp()
{
	points -= bullet_upg * 200;
	bullet_upg++;
}
void MyShip::maxHpUp()
{
	points -= maxHp *2;
	maxHp += 20;
}
void MyShip::heal()
{
	points -= maxHp-HP + 50;
	HP = maxHp;
}

void MyShip::bonusPoint(int bonus)
{
	points += bonus;
}
void MyShip::bonusHealth(int bonus)
{
	HP += bonus;
	if (HP > maxHp)
	{
		HP = maxHp;
	}
}
void MyShip::bonusShield(int bonus)
{
	//shield bonus
}


int MyShip::getLaserLevel()
{
	return laser_upg;
}
int MyShip::getActShield()
{
	return SHIELD;
}

void MyShip::move_back()
{
	sprite.setPosition(384, 500);
}

void MyShip::reset()
{
	//POSITION
	sprite.setPosition(384, 500);
	//HP SHIELDS POINTS
	maxHp = 100;
	HP = 100;
	SHIELD = 100;
	points = 0;
	game_lvl = 1;

	//bullets
	laser_upg = 0;
	rocket_upg = 0;
	bullet_upg = 1;
}

void MyShip::setStats(int gameLv, int maxLife, int actLife, int shield, int pt, int bulletLvl, int rocketLvl, int laserLvl)
{
	game_lvl = gameLv;
	maxHp = maxLife;
	HP = actLife;
	SHIELD = shield;
	points = pt;
	bullet_upg = bulletLvl;
	rocket_upg = rocketLvl;
	laser_upg = laserLvl;
}