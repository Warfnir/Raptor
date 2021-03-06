// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
// TODO: reference additional headers your program requires here

//------------------SFML
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"


#include "TextureSet.h"
//------------------CLASSIC LBR
#include <iostream>
#include <vector>
#include <fstream>


//------------------IN GAME 
#include "game.h"
#include "Engine.h"

//------------------MAP
#include "Map.h"
#include "Tile.h"

//------------------MAIN OBJECT
#include "object.h"
#include "animation.h"
//------------------BULLETS
#include "Bullet.h"
#include "standard_bullet.h"
#include "rocket.h"
#include "laser.h"

//------------------SHIPS
#include "Ship.h"
#include "MyShip.h"
#include "EnemyShip.h"
#include "B0_ship.h"
#include "B1_ship.h"
#include "boss_A.h"

//------------------BONUSES
#include "bonus.h"

//------------------animations
#include "bullet_explode_animation.h"
#include "rocket_explode_animation.h"

//------------------other
#include "bg_enum.h"



