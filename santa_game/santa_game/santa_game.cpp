// santa_game.cpp : Defines the entry point for the console application.
//


//#include <opencv2/opencv.hpp>
#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Santa.h"
#include "Elf.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include <SFML/System/Time.hpp>


using namespace std;
using namespace sf;


bool cooldown = false;
string player;

TcpSocket socket;
IpAddress localhost;
Socket::Status status = socket.connect(localhost.getLocalAddress(), 44000);

struct propsstruct
{
	float x;
	float y;
	int type;
};

sf::Packet& operator <<(sf::Packet& packet, propsstruct character)
{
	return packet << character.x << character.y << character.type;
}
sf::Packet& operator >>(sf::Packet& packet, propsstruct* character)
{
	return packet >> character->x >> character->y >> character->type;
}

void keyInput(Santa* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1236 - 123)
	{
		// left key is pressed: move our character
		p1->move_x(1);
	}
}

void keyInput(Elf* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our character
		p1->move_x(1);
	}
}


//santa
void gameRun(Santa* p1, Elf* p2) {
	//Santa is player one

	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "SANTA GAME");


	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);


	float elfX;
	float santaXpos;

	while (true) {
		renderWindow.clear();
		Packet santaSend;
		Packet elfReceived;


		int counter = 0;
		while (true) {
			renderWindow.clear();
			Event event;
			keyInput(p1);
			if (counter > 100) {
				cooldown = false;
				counter = 0;
			}
			if (cooldown) {
				counter++;
			}
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
							cout << "space clicked" << endl;
							p1->action();
							cooldown = true;
						}
					}
					break;
				default:
					break;
				}
			}

			//go through every prop element and calcute new position
			//based on its respective gravity
			for (int i = 0; i < p1->get_drop_list()->size(); i++) 
				p1->get_drop_list()->operator[](i)->fall();
			for (int i = 0; i < p1->get_drop_list()->size(); i++) {
				if (p1->get_drop_list()->operator[](i)->get_y() > renderWindow.getSize().y) 
					p1->get_drop_list()->erase(p1->get_drop_list()->begin() + i);
				else 
					p1->get_drop_list()->operator[](i)->get_image()->setPosition(p1->get_drop_list()->operator[](i)->get_x(), p1->get_drop_list()->operator[](i)->get_y());
			}

			//send x
			santaXpos = p1->get_x();
			santaSend << santaXpos;
			socket.send(santaSend);
			santaSend.clear();

			//send count
			Packet countnotifier;
			int count = p1->get_drop_list()->size();
			countnotifier << count;
			socket.send(countnotifier);
			countnotifier.clear();

			//send per count each prop
			propsstruct doesthiswork;
			for (int i = 0 ; i < p1->get_drop_list()->size(); i++)
			{
				doesthiswork.x = p1->get_drop_list()->operator[](i)->get_x();
				doesthiswork.y = p1->get_drop_list()->operator[](i)->get_y();
				doesthiswork.type = p1->get_drop_list()->operator[](i)->get_type();
				santaSend << doesthiswork;
				socket.send(santaSend);
				santaSend.clear();
			}
			socket.receive(elfReceived);
			
			elfReceived >> elfX;
			p2->set_x(elfX);
			elfReceived.clear();
		
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

void gameRun(Elf* p1, Santa* p2) {
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "ELF GAME");

	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);

	float elfX;
	float santaXpos;

	while (true) {
		renderWindow.clear();

		Packet elfSend;
		Packet santaReceive;

		int counter = 0;
		while (true) {

			renderWindow.clear();
			Event event;

			keyInput(p1);
			if (counter == 100) {
				cooldown = false;
				counter = 0;
			}
			if (cooldown) {
				counter++;
			}


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
							p1->action(p2);
							cooldown = true;
						}
					}
					break;
				default:
					break;
				}
			}

			//receive x for santa first
			socket.receive(santaReceive);
			santaReceive >> santaXpos;
			p2->set_x(santaXpos);
			santaReceive.clear();
			//receive count of prop element
			socket.receive(santaReceive);
			int propcountnotifier;
			santaReceive >> propcountnotifier;
			santaReceive.clear();
			//receive per/ amount of prop element each element of prop
			propsstruct* receive_props = new propsstruct();

			if (propcountnotifier != 0)
			{
				p2->get_drop_list()->clear();
				for (int i = 0; i < propcountnotifier; i++)
					p2->get_drop_list()->push_back(new Props(0));
				for (int i = 0; i < propcountnotifier; i++)
				{
					socket.receive(santaReceive);
					santaReceive >> receive_props;
					p2->get_drop_list()->operator[](i)->set_x(receive_props->x);
					p2->get_drop_list()->operator[](i)->set_y(receive_props->y);
					p2->get_drop_list()->operator[](i)->set_type(receive_props->type);
					santaReceive.clear();
				}
			}

			elfX = p1->get_x();
			elfSend << elfX;
			socket.send(elfSend);
			elfSend.clear();

			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());
			for (int i = 0; i < p2->get_drop_list()->size(); i++) {
				p2->get_drop_list()->operator[](i)->set_image();
				p2->get_drop_list()->operator[](i)->get_image()->setPosition(p2->get_drop_list()->operator[](i)->get_x(), p2->get_drop_list()->operator[](i)->get_y());
			}
			
			renderWindow.draw(background_sprite);
			renderWindow.draw(*playerone);
			renderWindow.draw(*playertwo);
			for (int i = 0; i < p2->get_drop_list()->size(); i++)
				renderWindow.draw(*p2->get_drop_list()->operator[](i)->get_image());

			renderWindow.display();
		}
	}
}

int main()
{
	if (status == Socket::Status::Done)
		cout << "client made" << endl;

	else {
		cout << "connection not made" << endl;
		return 0;
	}
	
	socket.setBlocking(true);
	Packet packet;
	socket.receive(packet);
	string playerchoice;
	packet >> playerchoice;
	player = playerchoice;
	
	int width = 1244;
	int height = 837;
	RenderWindow newWindow(VideoMode(width, height), "SÁNTA GAME");

	Texture texture4;
	if (texture4.loadFromFile("Newgame.jpg") != true) {
	}
	Sprite newgame;
	newgame.setTexture(texture4);

	while (true) {
		newWindow.clear();
		newWindow.draw(newgame);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			if (sf::Mouse::getPosition(newWindow).y > 522 && sf::Mouse::getPosition(newWindow).y < 567 && sf::Mouse::getPosition(newWindow).x > 485 && sf::Mouse::getPosition(newWindow).x < 795) {
				if (player == "santa") {
					Santa* p1 = new Santa(width / 2);
					Elf* p2 = new Elf(width / 2);
					newWindow.close();
					gameRun(p1, p2);
				}
				else {
					Elf* p1 = new Elf(width / 2);
					Santa* p2 = new Santa(width / 2);
					newWindow.close();
					gameRun(p1, p2);
				}
			}
		newWindow.display();
	}
}

