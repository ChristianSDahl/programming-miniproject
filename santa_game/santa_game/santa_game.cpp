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


void keyInput(Santa* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		cout << "smth" << endl;
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1236 - 123)
	{
		// left key is pressed: move our character
		cout << "nothing" << endl;
		p1->move_x(1);
	}
}

void keyInput(Elf* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		cout << "smth" << endl;
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our character
		cout << "nothing" << endl;
		p1->move_x(1);
	}
}


int main()
{
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


		while (true) {
			renderWindow.clear();
			Event event;
			keyInput(p1);
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
						cout << "test" << endl;
						p1->action();
					}
					break;
					// we don't process other types of events
				default:
					break;
				}
			}

			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());
			renderWindow.draw(background_sprite);
			renderWindow.draw(*playerone);
			renderWindow.draw(*playertwo);

			renderWindow.display();
		}
	}
	return 6;
	
}