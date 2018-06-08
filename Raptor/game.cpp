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
		if (!menu && !sklep && !walka)
		{
			quit = true;
		}
		else
		{
			if (menu)
			{
				engine.menu(); //menu gry
				walka = engine.ifFight();
				sklep = engine.ifShop();
				menu = false;
			}
			else if (walka)
			{
				engine.start(); //engine zawiera petle gry, tu jest aktualnie walka
				walka = false;
				sklep = engine.ifShop();
				menu = engine.ifMenu();
				cout << "Po walce\n";
			}
			else if (sklep)
			{
				engine.open_item_shop();	//sklep
				walka = engine.ifFight();
				menu = engine.ifMenu();
				sklep = false;
			}
		}
	}
}
