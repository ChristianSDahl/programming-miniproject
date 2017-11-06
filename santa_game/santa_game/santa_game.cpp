// santa_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace cv;
using namespace sf;

int main()
{
	/*
	std::vector<int> mylist;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		mylist.push_back(myint);
		std::cin >> myint;
		mylist.push_back(myint);
		break;
	} while (myint);

	std::cout << "mylist stores " << mylist.size() << " numbers.\n" << endl;
	for (int i = 0; i < mylist.size();i++) {
		std::cout << mylist[i] << endl;
	}
	//getchar;
	*/

	//Get input from server regarding who is who
	//Santa* p1 = new Santa(width / 2);
	//Elf* p2 = new Elf(width / 2);



	//Draw
	RenderWindow renderWindow(sf::VideoMode(1233, 827), "My window");

	sf::Texture texture;
	if (texture.loadFromFile("game.jpg") != true)
	{
		return 0;
	}
		
	sf::Sprite sprite(texture);
	while (true) {
		renderWindow.clear();
		sprite.setPosition(00, 00);
		renderWindow.draw(sprite, sf::RenderStates::Default);
		renderWindow.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "smth" << endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "nothing" << endl;
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "smth else" << endl;
		}
	}

	

	return 0;
}

