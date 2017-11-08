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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// left key is pressed: move our character
		cout << "smth else" << endl;
		
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// left key is pressed: move our character
		cout << "smth else" << endl;

	}

}


int main()
{
	//Get input from server regarding who is who

	
	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");

	Santa* p2 = new Santa(width / 2);
	Elf* p1 = new Elf(width / 2);
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
		playerone->setPosition(p1->get_x(),p1->get_y());
		playertwo->setPosition(p2->get_x(), p2->get_y());
		renderWindow.draw(background_sprite);
		renderWindow.draw(*playerone);
		renderWindow.draw(*playertwo);

		renderWindow.display();
	}
	return 6;
	
}