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

int main()
{

	//Get input from server regarding who is who
	//Santa* p1 = new Santa(width / 2);
	//Elf* p2 = new Elf(width / 2);


	
	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");

	Santa* p1 = new Santa(width / 2);
	Elf* p2 = new Elf(width / 2);
	while (true) {
		renderWindow.clear();
		Sprite* temp = p2->get_img();
		renderWindow.draw(*temp);
		renderWindow.display();
	}

	/*
	vector<Sprite> object_list;

	sf::Texture texture;
	if (texture.loadFromFile("game.jpg") != true)
	{
		return 1;
	}
	sf::Sprite sprite(texture);

	sf::Texture texture2;
	if (texture2.loadFromFile("santa_sprite.png") != true)
	{
		return 2;
	}
	sf::Sprite sprite2(texture2);


	
	//Testing elf
	sf::Texture texture3;
	if (texture3.loadFromFile("elf_sprite.png") != true)
	{
		return 3;
	}
	sf::Sprite sprite3(texture3);
	int xelf = (renderWindow.getSize().x / 2) - 61;
	sprite3.setPosition(xelf,690);

	sf::Texture texture4;
	if (texture4.loadFromFile("coal_sprite.png") != true)
	{
		return 4;
	}
	sf::Sprite sprite4(texture4);

	sf::Texture texture5;
	if (texture5.loadFromFile("present_sprite.png") != true)
	{
		return 5;
	}
	sf::Sprite sprite5(texture5);

	object_list.push_back(sprite);
	object_list.push_back(sprite2);
	object_list.push_back(sprite3);
	object_list.push_back(sprite4);
	object_list.push_back(sprite5);


	

//	sf::Sprite sprite(texture);
		//sf::Sprite santa_sprite(santa_texture);
	int xtemp = (renderWindow.getSize().x / 2) - 61;
	int ytemp = 0;
	while (true) {
		renderWindow.clear();
		//santa
		object_list[1].setPosition(xtemp, 100);
		//elf
		object_list[2].setPosition(xtemp, 690);
		for (int i = 0; i < object_list.size(); i++) {
			renderWindow.draw(object_list[i]);
		}
		//renderWindow.draw(santa_sprite, RenderStates::Default);
		renderWindow.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && xtemp>=0)
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "smth" << endl;
			xtemp--;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& xtemp<=1236-123)
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "nothing" << endl;
			xtemp++;
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			// left key is pressed: move our character
			//character.move(1, 0);
			cout << "smth else" << endl;
			ytemp++;
		}
	}
	*/
	return 6;
	
}