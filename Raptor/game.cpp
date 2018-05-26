#include "stdafx.h"
#include "game.h"


game::game()
{
	game_on = true;
}


game::~game()
{
}


void game::gMain()
{
	Engine engine;	//tworzy silnik
	engine.start(); //engine zawiera petle gry
	MyShip ss;
}
