// santa_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <opencv2/opencv.hpp>
#include <SFML\Graphics.hpp>
#include "Santa.h"
#include "Elf.h"

using namespace std;
using namespace cv;
using namespace sf;


bool cooldown = false;
void keyInput(Santa* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		//cout << "smth" << endl;
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1236 - 123)
	{
		// left key is pressed: move our character
		//cout << "nothing" << endl;
		p1->move_x(1);
	}
}

void keyInput(Elf* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		//cout << "smth" << endl;
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our character
		//cout << "nothing" << endl;
		p1->move_x(1);
	}
}


void gameRun() {

	//Get input from server regarding who is who


	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");

	Santa* p1 = new Santa(width / 2);
	Elf* p2 = new Elf(width / 2);
	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	sf::Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);


	while (true) {
		renderWindow.clear();
		keyInput(p1);

		int counter = 0;
		while (true) {

			renderWindow.clear();
			Event event;
			keyInput(p1);
			if (counter == 500) {
				cooldown = false;
				counter = 0;
			}
			if (cooldown) {
				counter++;
			}
			cout << counter << endl;
			while (renderWindow.pollEvent(event))
			{
				// check the type of the event...
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					renderWindow.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:

					break;
				case Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Space) {
						if (!cooldown) {
							p1->action();
							cooldown = true;
						}

					}
					break;
					// we don't process other types of events
				default:
					break;
				}
			}

			//go through every prop element and calcute new position
			//based on its respective gravity
			for (int i = 0; i < p1->get_drop_list()->size(); i++) {
				p1->get_drop_list()->operator[](i)->fall();
				//cout << i << ": " << p1->get_drop_list()->operator[](i)->get_y() << endl;
			}
			for (int i = 0; i < p1->get_drop_list()->size(); i++) {
				if (p1->get_drop_list()->operator[](i)->get_y() > renderWindow.getSize().y) {
					p1->get_drop_list()->erase(p1->get_drop_list()->begin() + i);
				}
				else {
					p1->get_drop_list()->operator[](i)->get_image()->setPosition(p1->get_drop_list()->operator[](i)->get_x(), p1->get_drop_list()->operator[](i)->get_y());
				}
			}

			//show every prop element


			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());
			renderWindow.draw(background_sprite);
			renderWindow.draw(*playerone);
			renderWindow.draw(*playertwo);
			for (int i = 0; i < p1->get_drop_list()->size(); i++) {
				renderWindow.draw(*p1->get_drop_list()->operator[](i)->get_image());
			}


			renderWindow.display();
		}
	}
}

int main()
{
	int width = 1244;
	int height = 837;
	RenderWindow newWindow(sf::VideoMode(width, height), "My window");

	Texture texture4;
	if (texture4.loadFromFile("Newgame.jpg") != true) {
	}
	Sprite newgame;
	newgame.setTexture(texture4);

	while (true) {
		newWindow.clear();
		newWindow.draw(newgame);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			cout << sf::Mouse::getPosition(newWindow).x << ", " << sf::Mouse::getPosition(newWindow).y << endl;
			if (sf::Mouse::getPosition(newWindow).y > 522 && sf::Mouse::getPosition(newWindow).y < 567 && sf::Mouse::getPosition(newWindow).x > 485 && sf::Mouse::getPosition(newWindow).x < 795) {
				cout << "test" << endl;
				gameRun();
			}
		}
		newWindow.display();
	}
	
	return 0;
}

