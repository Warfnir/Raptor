#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
	//window set
	VideoMode vmode(800, 600);
	Vector2u vec2u(800, 600);
	window.create(vmode, "Raptor", Style::Default);
	window.setFramerateLimit(60);

	//background
	main_music.openFromFile("Retribution.ogg");
	bg_texture.loadFromFile("b_cloud.png");
	bg_texture.setSmooth(true);
	bg_texture.setRepeated(true);
	bg_sprite1.setTexture(bg_texture);
	bg_sprite1.setTextureRect(IntRect(0, 0, 800, 1200));
	bg_sprite1.setPosition(0, 0);
	bg_sprite2.setTexture(bg_texture);
	bg_sprite2.setTextureRect(IntRect(0, 0, 800, 1200));
	bg_sprite2.setPosition(0, -1200);
	
	//enemies
	for (int i = 0; i < 5; i++)
	{
		enemyShips.push_back(new B0_ship(rand()%800,rand()%600));
	}
	//my ship
	myShip = new(MyShip);
}


Engine::~Engine()
{
	
}

//zwraca czy okno dziala poprawnie
bool Engine::window_ok()
{
	return window.isOpen();
}

//wyswietla okno
void Engine::display_window()
{
	window.display();
}

//rysuje t³o
//dwie textury wyswietlane na zmiane
//i przesuwajace sie w dol ekranu
void Engine::update_backGround()
{
	bg_sprite1.move(0, 1);
	bg_sprite2.move(0, 1);
	if (bg_sprite1.getPosition().y > 1200)
	{
		bg_sprite1.setPosition(0, -1190);
	}
	if (bg_sprite2.getPosition().y > 1200)
	{
		bg_sprite2.setPosition(0, -1190);
	}
}


//rysuje wszystkie elementy na oknie
void Engine::drawAll()
{
	//CLEAR WINDOW AND DRAW UPDATED BACKGROUND
	window.clear();
	update_backGround();
	window.draw(bg_sprite1);
	window.draw(bg_sprite2);


	//DRAW BULLETS AND CHECK IF NEED TO DELETE
	for (int i = 0; i < myBullet.size(); i++)
	{
		//Bullet *wsk = *i;
		if (myBullet[i]->outOfMap() || !(myBullet[i]->getLife()))
		{
			if (myBullet[i]->outOfMap())
			{
				delete myBullet[i];
				myBullet.erase(myBullet.begin() + i);
			}
			else if (!(myBullet[i]->getLife()))
			{
				animations.push_back(new bullet_explode_animation(myBullet[i]->getPosition()));
				delete myBullet[i];
				myBullet.erase(myBullet.begin() + i);
				
			}
		}
		//DRAW BULLET IF NOT DESTROYED
		else
		{
			window.draw(*myBullet[i]);
		}
	}
	//ENEMY BULLETS
	for (int i = 0; i < enemyBullet.size(); i++)
	{
		//Bullet *wsk = *i;
		if (enemyBullet[i]->outOfMap() || !(enemyBullet[i]->getLife()))
		{
			if (enemyBullet[i]->outOfMap())
			{
				delete enemyBullet[i];
				enemyBullet.erase(enemyBullet.begin() + i);
			}
			else if (!(enemyBullet[i]->getLife()))
			{
				animations.push_back(new bullet_explode_animation(enemyBullet[i]->getPosition()));
				delete enemyBullet[i];
				enemyBullet.erase(enemyBullet.begin() + i);

			}
		}
		//DRAW BULLET IF NOT DESTROYED
		else
		{
			window.draw(*enemyBullet[i]);
		}
	}
	//DRAW ENEMY SHIPS
	for (int i = 0; i < enemyShips.size(); i++)
	{
		enemyShips[i]->outOfWindow();
		if (enemyShips[i]->getLife() > 0 && !(enemyShips[i]->getOut()))
		{
			window.draw(*enemyShips[i]);
		}
		else 
		{
			if (enemyShips[i]->getLife() < 0)
			{
				myShip->grantPoints(enemyShips[i]->getPoints());
				delete enemyShips[i];
				enemyShips.erase(enemyShips.begin() + i);
			}
			else if (enemyShips[i]->getOut())
			{
				delete enemyShips[i];
				enemyShips.erase(enemyShips.begin() + i);
			}
		}
	}

	//DRAW OUR SHIP
	window.draw(*myShip);

	//DRAW ANIMATIONS
	for (int i=0; i<animations.size(); i++)
	{
		if (typeid(*animations[i]) == typeid(bullet_explode_animation))
		{
			bullet_explode_animation *wsk = dynamic_cast<bullet_explode_animation*>(animations[i]);
			if (!wsk->end_animation())
			{
				wsk->next_frame();
				window.draw(*animations[i]);
			}
			else
			{
				delete animations[i];
				animations.erase(animations.begin() + i);
			}
		}
	}
	//WYPISZ ZAWARTOSC WEKTOROW
	/*
	system("cls");
	cout << "MyBullet: " << myBullet.size()<<endl;
	cout << "Enemy ships: " << enemyShips.size() << endl;
	cout << "Animations: " << animations.size() << endl;
	cout << "EnemyBullets: " << enemyBullet.size() << endl;
	*/

}



//przesuwa wszystkie elementy na mapie
void Engine::move_All()
{
	//aktualizacja pociskow
	for (auto i = myBullet.begin(); i != myBullet.end(); i++)
	{
		Bullet *wsk = *i;
		wsk->move();
	}
	for (auto i = enemyBullet.begin(); i != enemyBullet.end(); i++)
	{
		Bullet *wsk = *i;
		wsk->move();
	}
	//aktualizacja ruchu przeciwnikow + strzelanie
	for (int i=0; i<enemyShips.size();i++)
	{
		if (typeid(*enemyShips[i]) == typeid(B0_ship))
		{
			B0_ship *wsk = dynamic_cast<B0_ship*>(enemyShips[i]);
			wsk->trace(myShip->getPosition());
			wsk->move();	
			wsk->aim(enemyBullet, myShip->getPosition());
		}	
		
	}
	myShip->move();
	myShip->outOfWindow();
}

void Engine::update_colission()
{
	
	//our bullets + enemy ships
	for (auto i : myBullet)
	{
		for (auto j : enemyShips)
		{
			
			if (isCollision(i->getPosition(), i->getR(), j->getPosition(), j->getR()))
			{
				j->gotHit(i->getDmg());
				i->destroy();
			}
		}
	}
	//enemy bullets + our ship

	//our ship + enemy ships
}



bool Engine::isCollision(Vector2f a, double Ra, Vector2f b, double Rb)
{
	
	if (sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y)) < (Ra+Rb))
	{
		return true;
	}
	return false;
}

//glowna petla gry?
void Engine::start()
{
	main_music.play();
	while (window.isOpen())	//okno jest otwarte
	{
		while (window.pollEvent(eve))
		{
			if (eve.type == Event::Closed)
			{

				window.close();
			}
			if (eve.type == Event::Resized)
			{
				eve.Resized;
			}
		}
			 if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				myShip->up = 1;
				
			}
			 if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				myShip->down = 1;
			}
			 if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				myShip->left = 1;
			}
			 if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				myShip->right = 1;
			}
			 if (Keyboard::isKeyPressed(Keyboard::LControl))
			 {
				 myShip->shoot(myBullet);
			 }

			
			/* //USTAWIA ILE ERKANU MA BYC WIDOCZNE DLA NAS
			 View view;
			 view.setSize(600, 400);
			 view.setCenter(400, 300);
			 window.setView(view);*/
	
		move_All();				//przesuwa wszystkie elementy
		update_colission();
		drawAll();				//rysuje wszystkie elementy
		window.display();		//wyswietla okno
		//cout << myBullet.size();//wypisuje aktualny stan pocisków
	}
}