// Raptor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
using namespace sf;

Vector2u vec(300, 300);



int main()
{
	game the_game;
	the_game.gMain();
	/*
	VideoMode vmode(800, 600);
	RenderWindow *window;
	window = new RenderWindow(vmode, "name", Style::Default);
	window->setFramerateLimit(60);
	
	while (window->isOpen())
	{

		Event eve;
		while (window->pollEvent(eve))
		{
			if (eve.type == Event::Closed)
			{
				window->close();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				vec.y = 800;
				window->setSize(vec);
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				vec.y = 400;
				window->setSize(vec);

			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				vec.x = 800;
				window->setSize(vec);

			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				vec.x = 400;
				window->setSize(vec);

			}

			else if (eve.type == Event::Resized)
			{
				vmode.height += 10;
				cout << eve.size.width << " " << eve.size.height << endl;
				eve.Resized;
			}
			else if (Mouse::isButtonPressed(Mouse::Left))
			{
				window->setSize(vec);

			}
		}
		//window->clear(Color::Green);
		window->draw(sp);
		window->display();

	}
	*/
    return 0;
}

