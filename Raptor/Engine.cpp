#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	srand(time(NULL)); //random seed

	//window set
	VideoMode vmode(800, 600);
	Vector2u vec2u(800, 600);
	window.create(vmode, "Raptor", Style::Default);
	window.setFramerateLimit(120);

	//background
	main_music.openFromFile("Retribution.ogg");
	
	
	//my ship
	myShip = new(MyShip);

	font.loadFromFile("PressStart2P.ttf");
	myPoints.setFont(font);
	myPoints.setCharacterSize(30);
	myPoints.setStyle(sf::Text::Bold);
	myPoints.setFillColor(sf::Color::Red);
	
	mapa.generateMap();

	wave = 2;
}
bool Engine::ifMenu()
{
	return okno_menu;
}
bool Engine::ifShop()
{
	return okno_sklepu;
}
bool Engine::ifFight()
{
	return okno_walki;
}

void Engine::open_item_shop()
{
	okno_sklepu = true;
	cout << "sklep";
	string tekst_sklepu;
	string upg_tekst;
	string pointer;
	Text text;
	Text arrow;
	arrow.setPosition(760,300);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	arrow.setFont(font);
	arrow.setCharacterSize(30);
	arrow.setStyle(sf::Text::Bold);
	arrow.setFillColor(sf::Color::Red);
	while (okno_sklepu)
	{
		window.clear(Color::Black);
		//potrzebne dla prawidlowego dzialania okna
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
			if (eve.type == Event::KeyPressed)
			{
				if (eve.key.code == Keyboard::Key::Up)
				{
					if (arrow.getPosition().y > 210)
					{
						arrow.move(0, -30);
						if (arrow.getPosition().y < 330)
						{
							arrow.setPosition(760, arrow.getPosition().y);
						}
					}
				}
				if (eve.key.code == Keyboard::Key::Down)
				{
					if (arrow.getPosition().y < 390)
					{
						arrow.move(0, 30);
						if (arrow.getPosition().y > 300)
						{
							arrow.setPosition(540, arrow.getPosition().y);
						}
					}
				}
				if (eve.key.code == Keyboard::Key::Return)
				{
					if(arrow.getPosition().y ==210)
					{ 
						if (myShip->getPoints() >= myShip->getBulletLevel() * 200)
						{
							myShip->bulletUp();
						}
					}
					else if(arrow.getPosition().y == 240)
					{
						if (myShip->getPoints() >= myShip->getRocketLevel() * 200 +300)
						{
							myShip->rocketUp();
						}
					}
					else if (arrow.getPosition().y == 270)
					{
						if (myShip->getPoints() >= myShip->getMaxHp() + 20)
						{
							myShip->maxHpUp();
						}
					}
					else if (arrow.getPosition().y == 300)
					{
						if (myShip->getPoints() >= (myShip->getMaxHp()- myShip->getActHp())+50 )
						{
							myShip->heal();
						}
					}
					else if (arrow.getPosition().y == 330)
					{
						okno_walki = true;
						okno_sklepu = false;
						okno_menu = false;
					}
					else if (arrow.getPosition().y == 360)
					{
						//save game save_game();
					}
					else if (arrow.getPosition().y == 390)
					{
						okno_menu = true;
						okno_sklepu = false;
						okno_walki = false;
					}
				}
			}
		}


		//pierwsza seria napisow
		tekst_sklepu.clear();
		tekst_sklepu.append("BUL LV ");
		tekst_sklepu.append(to_string(myShip->getBulletLevel()));
		tekst_sklepu.append("\nROC LV ");
		tekst_sklepu.append(to_string(myShip->getRocketLevel()));
		tekst_sklepu.append("\nMAX HP ");
		tekst_sklepu.append(to_string(myShip->getMaxHp()));
		tekst_sklepu.append("\nACT HP ");
		tekst_sklepu.append(to_string(myShip->getActHp()));
		text.setString(tekst_sklepu);
		text.setPosition(30, 210);
		window.draw(text);

		//druga seria napisow
		upg_tekst.clear();
		upg_tekst.append("UP   $ ");
		upg_tekst.append(to_string(myShip->getBulletLevel()*200));
		upg_tekst.append("\nUP   $ ");
		upg_tekst.append(to_string(myShip->getRocketLevel()*200+300));
		upg_tekst.append("\nUP   $ ");
		upg_tekst.append(to_string(myShip->getMaxHp()*2));
		upg_tekst.append("\nHEAL $ ");
		upg_tekst.append(to_string(myShip->getMaxHp()-myShip->getActHp()+50));
		text.setString(upg_tekst);
		text.setPosition(390, 210);
		window.draw(text);

		//rysowanie wskaznika
		pointer.clear();
		pointer.append("<");
		arrow.setString(pointer);
		window.draw(arrow);

		//aktualne punkty
		tekst_sklepu.clear();
		tekst_sklepu.append("ACTUAL POINTS: ");
		tekst_sklepu.append(to_string(myShip->getPoints()));
		int txtSize = tekst_sklepu.size();
		text.setString(tekst_sklepu);
		text.setPosition(400 - (txtSize / 2) * 30, 180);
		window.draw(text);

		//nastepna mapa, zapisz, wyjdz
		tekst_sklepu.clear();
		tekst_sklepu.append("NEXT MAP\n  SAVE\n  QUIT");
		text.setString(tekst_sklepu);
		text.setPosition(280 , 330);
		window.draw(text);
		window.display();
	}

}

void Engine::menu()
{
	okno_menu = true;
	cout << "menu";
	string tekst_menu;
	string pointer = "<";
	Text text;
	Text arrow;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	arrow.setFont(font);
	arrow.setCharacterSize(30);
	arrow.setStyle(sf::Text::Bold);
	arrow.setFillColor(sf::Color::Red);
	arrow.setPosition(530, 255);
	arrow.setString(pointer);
	while (okno_menu)
	{
		window.clear(Color::Black);
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
			if (eve.type == Event::KeyPressed)
			{
				if (eve.key.code == Keyboard::Key::Up)
				{
					if (arrow.getPosition().y > 255)
					{
						arrow.move(0, -30);
					}
				}
				if (eve.key.code == Keyboard::Key::Down)
				{
					if (arrow.getPosition().y < 315)
					{
						arrow.move(0, 30);
					}
				}
				if (eve.key.code == Keyboard::Key::Return)
				{
					if (arrow.getPosition().y == 255)
					{
						okno_menu = false;
						okno_sklepu - false;
						okno_walki = true;
					}
					else if (arrow.getPosition().y == 285)
					{
						/*if (load_game())
						{
							okno_menu = true;
							okno_sklepu - false;
							okno_walki = false;
						}*/
						cout << "LAOD";
					}
					else if (arrow.getPosition().y == 315)
					{
						okno_menu = false;
						okno_sklepu - false;
						okno_walki = false;
					}
				}
			}
		}

		//tekst menu
		tekst_menu.clear();
		tekst_menu.append("NEW GAME\n  LOAD\n  QUIT");//opcje mog¹ dojsc pozniej
		text.setString(tekst_menu);
		text.setPosition(280, 255);
		window.draw(text);

		//strzalka
		window.draw(arrow);

		window.display();
	}
}

//tworzy nowa fale przeciwnikow
void Engine::next_wave()
{
	if (enemyShips.size() == 0)
	{
		if (wave > 0)
		{
			for (int i = 0; i < 10; i++)
			{
				enemyShips.push_back(new B1_ship(rand() % 800, rand() % 200 - 200, myShip->getGameLevel()));
			}
			enemyShips.push_back(new B0_ship(32, -40, myShip->getGameLevel()));
			enemyShips.push_back(new B0_ship(768, -40, myShip->getGameLevel()));
			wave--;
		}
		else if(wave ==0)
		{
			enemyShips.push_back(new boss_A(410, -125));
			wave--;
		}

	}
}

Engine::~Engine()
{
	
}

//zwraca czy okno dziala poprawnie
bool Engine::window_ok()
{
	return window.isOpen();
}


//rysuje wszystkie elementy na oknie
void Engine::drawAll()
{
	//CLEAR WINDOW AND DRAW BACKGROUND
	window.clear();
	
	//update t³a, rysuje i przesuwa tlo
	mapa.mapOutOfWindow();
	mapa.move();
	mapa.draw(window);
	
	
	//--------------------------------------------------------------------------------------------------------
	//DRAW BULLETS AND CHECK IF NEED TO DELETE
	for (int i = 0; i < myBullet.size(); i++)
	{
		//pocisk poza map¹ lub nie ma "zycia"
		if (myBullet[i]->outOfMap() || !(myBullet[i]->getLife()))
		{
			//poza map¹
			if (myBullet[i]->outOfMap())
			{
				delete myBullet[i];
				myBullet.erase(myBullet.begin() + i);
			}
			//pocisk trafil
			else if (!(myBullet[i]->getLife()))
			{
				//dodaje animacje wybuchajacego pocisku
				if (typeid(*myBullet[i]) == typeid(standard_bullet))
				{
					animations.push_back(new bullet_explode_animation(myBullet[i]->getPosition()));
					delete myBullet[i];
					myBullet.erase(myBullet.begin() + i);
				}
				//dodaje animacje wybuchajacej rakiety
				else if (typeid(*myBullet[i]) == typeid(rocket))
				{
					animations.push_back(new rocket_explode_animation(myBullet[i]->getPosition()));
					delete myBullet[i];
					myBullet.erase(myBullet.begin() + i);
				}
			}
		}
		//rysuje pozostale pociski
		else
		{
			window.draw(*myBullet[i]);
		}
	}

	//-------------------------------------------------------------------------------------------------------------
	//ENEMY BULLETS podobnie jak wyzej
	for (int i = 0; i < enemyBullet.size(); i++)
	{
		if (enemyBullet[i]->outOfMap() || !(enemyBullet[i]->getLife()))
		{
			if (enemyBullet[i]->outOfMap())
			{
				delete enemyBullet[i];
				enemyBullet.erase(enemyBullet.begin() + i);
			}
			else if (!(enemyBullet[i]->getLife()))
			{
				if (typeid(*enemyBullet[i]) == typeid(standard_bullet))
				{
					animations.push_back(new bullet_explode_animation(enemyBullet[i]->getPosition()));
					delete enemyBullet[i];
					enemyBullet.erase(enemyBullet.begin() + i);
				}
				else if (typeid(*enemyBullet[i]) == typeid(rocket))
				{
					animations.push_back(new rocket_explode_animation(enemyBullet[i]->getPosition()));
					delete enemyBullet[i];
					enemyBullet.erase(enemyBullet.begin() + i);
				}
			}
		}
		//DRAW BULLET IF NOT DESTROYED
		else
		{
			window.draw(*enemyBullet[i]);
		}
	}

	//-----------------------------------------------------------------------------------------------------------
	//DRAW ENEMY SHIPS
	for (int i = 0; i < enemyShips.size(); i++)
	{
		//sprawdza czy jest poza oknem
		enemyShips[i]->outOfWindow();
		//rysuje statki ktore zyja i zostaly na ekranie
		if (enemyShips[i]->getLife() > 0 && !(enemyShips[i]->getOut()))
		{
			window.draw(*enemyShips[i]);
		}
		else 
		{
			//usuwa statki ktore zniszczylismy i dodaje punkty
			if (enemyShips[i]->getLife() <= 0)
			{
				myShip->grantPoints(enemyShips[i]->getPoints());
				animations.push_back(new rocket_explode_animation(enemyShips[i]->getPosition()));
				bonuses.push_back(new bonus(enemyShips[i]->getPosition(), rand() % 11, 1));
				delete enemyShips[i];
				enemyShips.erase(enemyShips.begin() + i);
			}
			//usuwa statki poza mapa bez dodawania punktow
			else if (enemyShips[i]->getOut())
			{
				delete enemyShips[i];
				enemyShips.erase(enemyShips.begin() + i);
			}
		}
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	//DRAW OUR SHIP
	if (myShip->getLife() <= 0)
	{
		//clear_memory();
		Clock koniec_gry;
		koniec_gry.restart();
		Text end_game;
		end_game.setFont(font);
		end_game.setCharacterSize(80);
		end_game.setStyle(sf::Text::Bold);
		end_game.setFillColor(sf::Color::White);
		end_game.setString("YOU LOST");
		end_game.setPosition(80, 220);
		okno_walki = false;
		while (koniec_gry.getElapsedTime().asSeconds() < 3)
		{
			window.clear(Color::Black);
			window.draw(end_game);
			window.display();
		}
		okno_menu = true;
		okno_sklepu = false;
		okno_walki = false;
	}
	window.draw(*myShip);

	//-----------------------------------------------------------------------------------------------------------------------------
	//DRAW ANIMATIONS
	for (int i=0; i<animations.size(); i++)
	{
		//animacja wybuchajacego pocisku
		if (typeid(*animations[i]) == typeid(bullet_explode_animation))
		{
			bullet_explode_animation *wsk = dynamic_cast<bullet_explode_animation*>(animations[i]);
			if (!wsk->end_animation())
			{
				wsk->next_frame();
				window.draw(*animations[i]);
			}
			//usuwanie animacji ktore sie zakonczyly
			else
			{
				delete animations[i];
				animations.erase(animations.begin() + i);
			}
		}
		//animacja wybuchajacej rakiety
		else if (typeid(*animations[i]) == typeid(rocket_explode_animation))
		{
			rocket_explode_animation *wsk = dynamic_cast<rocket_explode_animation*>(animations[i]);
			if (!wsk->end_animation())
			{
				wsk->next_frame();
				window.draw(*animations[i]);
			}
			//usuwanie animacji ktore sie zakonczyly
			else
			{
				delete animations[i];
				animations.erase(animations.begin() + i);
			}
		}
	}

	//---------------------------------------------------------------------------------------------------------------------------
	//DRAW BONUSES
	for (auto i : bonuses)
	{
		i->move();
		i->changeFrame();
		window.draw(*i);
	}

	//---------------------------------------------------------------------------------------------------------------------------
	//DRAW TEXTS
	string txt;
	txt = to_string(myShip->getPoints());
	int txtSize = txt.size();
	myPoints.setString(txt);
	myPoints.setPosition(400-(txtSize/2)*30, 0);
	myPoints.setPosition(300, 0);
	window.draw(myPoints);

	//WYPISZ ZAWARTOSC WEKTOROW
	/*
	system("cls");
	cout << "MyBullet: " << myBullet.size()<<endl;
	cout << "Enemy ships: " << enemyShips.size() << endl;
	cout << "Animations: " << animations.size() << endl;
	cout << "EnemyBullets: " << enemyBullet.size() << endl;
	*/

}


//--------------------------------------------------------------------------------------------------------
//przesuwa wszystkie elementy na mapie
void Engine::move_All()
{
	//pprzesuwanie pociskow
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
	//----------------------------------------------------------------------------------------------------
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
		if (typeid(*enemyShips[i]) == typeid(B1_ship))
		{
			B1_ship *wsk = dynamic_cast<B1_ship*>(enemyShips[i]);
			wsk->shoot(enemyBullet);
			wsk->move();
			
		}
		if (typeid(*enemyShips[i]) == typeid(boss_A))
		{
			boss_A*wsk = dynamic_cast<boss_A*>(enemyShips[i]);
			wsk->move();
			wsk->shoot(enemyBullet);
		}
	}

	//-------------------------------------------------------------------------------------------------
	//aktualizacja ruchu naszego statku + kolizja z granicami ekranu
	myShip->move();
	myShip->outOfWindow();
}

//------------------------------------------------------------------------------------------------------
//sprawdza wszystkie kolizje
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
	for (auto i : enemyBullet)
	{
		if (isCollision(i->getPosition(), i->getR(), myShip->getPosition(), myShip->getR()))
		{
			myShip->gotHit(i->getDmg());
			i->destroy();
		}
	}
	//our ship + enemy ships
	for (auto i : enemyShips)
	{
		if (isCollision(i->getPosition(), i->getR(), myShip->getPosition(), myShip->getR()))
		{
			myShip->gotHit(i->getLife());	//dostajemy tyle obrazen ile przeciwnikowi zosta³o ¿ycia podczas kolizji
			i->crash();
			animations.push_back(new rocket_explode_animation(i->getPosition()));
		}
	}

	//out ship + bonuses
	for (int i=0 ;i<bonuses.size();i++)
	{
		if (isCollision(bonuses[i]->getPosition(), bonuses[i]->getR(), myShip->getPosition(), myShip->getR()))
		{
			bonuses[i]->giveBonus(*myShip);
			delete bonuses[i];
			bonuses.erase(bonuses.begin() + i);
		}
	}
}

//dodaje nowych przeciwnikow, na potrzeby testowania
void Engine::updateNumberOfEnemies()
{
	if (enemyShips.size() < 10)
	{
		enemyShips.push_back(new B1_ship(rand() % 800, -60, myShip->getGameLevel()));
	}
}

//sprawdza kolizje dwóch obiektów po promieniu
bool Engine::isCollision(Vector2f a, double Ra, Vector2f b, double Rb)
{
	
	if (sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y)) < (Ra+Rb))
	{
		return true;
	}
	return false;
}

//glowna petla okna walki
void Engine::start()
{
	Clock fps;
	int klatki = 0;
	main_music.play();
	okno_walki = true;
	wave = myShip->getGameLevel();
	next_wave();
	while (okno_walki)	//okno jest otwarte
	{
		if (enemyShips.size() == 0)
		{
			next_wave();
			if (wave < 0 && enemyShips.size() == 0)
			{
				okno_walki = false;
				okno_sklepu = true;
				myShip->nextLevel();
				
			}
		}

		if (fps.getElapsedTime().asMilliseconds() > 1000)
		{
			fps.restart();
			//cout << klatki << endl;
			klatki = 0;
		}
		klatki++;

		//sprawdza zdarzenia na oknie 
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

		//sterowanie statkiem
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
		update_colission();		//sprawdza kolizje
		drawAll();				//rysuje wszystkie elementy
		window.display();		//wyswietla okno
	}
}