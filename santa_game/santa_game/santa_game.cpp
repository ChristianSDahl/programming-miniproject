// santa_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <SFML\Graphics.hpp>
#include "Santa.cpp"
#include "Elf.cpp"

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
	RenderWindow renderWindow(sf::VideoMode(1280, 720), "My window");

	sf::Texture texture;
	if (texture.loadFromFile("maxresdefault.jpg") != true)
	{
		return 0;
	}
		
	sf::Sprite sprite(texture);
	while (true) {
		renderWindow.clear();
		sprite.setPosition(00, 00);
		renderWindow.draw(sprite, sf::RenderStates::Default);
		renderWindow.display();
	}
	return 0;
}

