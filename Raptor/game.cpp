#include "stdafx.h"
#include "game.h"


game::game()
{
	quit = false;
	menu = true;
	walka = false;
	sklep = false;
}


game::~game()
{
}


void game::gMain()
{
	Engine engine;	//tworzy silnik
	while (!quit)
	{
		if (menu)
		{
			engine.menu();
		}
		else if (walka)
		{
			cout << "walka";
			engine.start(); //engine zawiera petle gry, tu jest aktualnie walka
			walka = false;
			sklep = engine.ifShop();
			menu = engine.ifMenu();
			cout << "Po walce";
		}
		else if(sklep)
		{
			cout << "sklep";
			engine.open_item_shop();
			walka = engine.ifFight();
			menu = engine.ifMenu();
			sklep = false;
			cout << "po sklepie";
		}
	}
}
