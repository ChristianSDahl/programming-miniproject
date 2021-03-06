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

// declaring global variables 
bool cooldown = false;
string player;

TcpSocket socket; //declearing a socket
IpAddress localhost; // declearing an ip adress

//
Socket::Status status = socket.connect(localhost.getLocalAddress(), 44000); // sentting up the socket with an ip-local ip , and port 44000

struct propsstruct  // declearing a struct of the props
{
	float x;
	float y;
	int type;
};
// takes as variables or objects .creates a packet with them and returns it
sf::Packet& operator <<(sf::Packet& packet, propsstruct character)
{
	return packet << character.x << character.y << character.type;
}
sf::Packet& operator >>(sf::Packet& packet, propsstruct* character)
{
	return packet >> character->x >> character->y >> character->type;
}
//move keys for Santa
void keyInput(Santa* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move Santa object , redusing the x value of its position by 1 
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1236 - 123)
	{
		// left key is pressed: move our Santa object, increasing the x value of its position by 1
		p1->move_x(1);
	}
}
// move keys for elf
void keyInput(Elf* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move Santa object , redusing the x value of its position by 1 
		p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our Santa object, increasing the x value of its position by 1
		p1->move_x(1);
	}
}


// 
void gameRun(Santa* p1, Elf* p2) {
	//Santa is player one
	//Elf is player two

	int width = 1236;
	int height = 833;// window size
	RenderWindow renderWindow(sf::VideoMode(width, height), "SANTA GAME"); // Renders the window with title santa game


	Sprite* playerone = p1->get_img();// assigning a image(sprite) to Santa
	Sprite* playertwo = p2->get_img(); // assigning a image(sprite) to Elf

	Texture background_texture;
	background_texture.loadFromFile("game.jpg"); // rendering game background
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0); // adjusting background position

	// 2 floats for x pos of the characters
	float elfX;
	float santaXpos;

	while (true) {
		renderWindow.clear(); //  clearring the window to create a motion with the help of the while loop

		// declearing a 2 objects of class Packet
		Packet santaSend;
		Packet elfReceived;


		int counter = 0; 
		while (true) {
			renderWindow.clear();
			Event event;
			keyInput(p1); // calling the keyimput method of Santa
			if (counter > 100) { 
				cooldown = false;
				counter = 0; 
			}
			if (cooldown) {
				counter++;
			}
			while (renderWindow.pollEvent(event))
			{
				// switches between different events 
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					renderWindow.close();
					break;
					// key pressed
				case sf::Event::KeyPressed:
					break;
					// Space key released
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

			//send x position of the santa 
			santaXpos = p1->get_x();
			santaSend << santaXpos;// packs  the x position of santa 
			socket.send(santaSend); // sents the packet thri the socket "socket"
			santaSend.clear(); // clears the packet

			//send the number of drops in the droplist 
			Packet countnotifier;   
			int count = p1->get_drop_list()->size(); // gets the value of the droplist size
			countnotifier << count; // packs the value 
			socket.send(countnotifier);// sents the value thru the socket 
			countnotifier.clear();// clears the packet 

			//send per count each prop
			propsstruct doesthiswork;
			for (int i = 0 ; i < p1->get_drop_list()->size(); i++) // goest thrue each element iof the droplist
			{
				doesthiswork.x = p1->get_drop_list()->operator[](i)->get_x(); // gets x pos of the drop and assigns it to the object of struct propsstruct
				doesthiswork.y = p1->get_drop_list()->operator[](i)->get_y(); // gets y pos of the frop
				doesthiswork.type = p1->get_drop_list()->operator[](i)->get_type(); // gets the type of the drop
				santaSend << doesthiswork; // packs the struct
				socket.send(santaSend);// sends the packet
				santaSend.clear(); // cleares the packet
			}
			socket.receive(elfReceived); // allows the soket to recieve a packet named elfRecieved
			
			elfReceived >> elfX; // unpacks the packet
			p2->set_x(elfX); // sets the position of the elf to the value of the position of the elf 
			elfReceived.clear();//  clears the packet
		
			playerone->setPosition(p1->get_x(), p1->get_y()); // moves the image of the santa
			playertwo->setPosition(p2->get_x(), p2->get_y()); // moves the image of the elf

			renderWindow.draw(background_sprite); //renders new background to create motion
			renderWindow.draw(*playerone);  
			renderWindow.draw(*playertwo);
			//for loop that drwas the drops depending on the size of drop list 
			for (int i = 0; i < p1->get_drop_list()->size(); i++) {
				renderWindow.draw(*p1->get_drop_list()->operator[](i)->get_image());
			}

			renderWindow.display();
		}
	}
}
// elf is a player 1
void gameRun(Elf* p1, Santa* p2) {
	int width = 1236;
	int height = 833;// window size 
	RenderWindow renderWindow(sf::VideoMode(width, height), "ELF GAME"); // Creating the window with title santa game

	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img(); // provides sprites to the players

	Texture background_texture;
	background_texture.loadFromFile("game.jpg"); // Rendering the background
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0); // adjusting the image position

	float elfX;
	float santaXpos; // declaring variables storing x positions of Santa and elf

	while (true) {
		renderWindow.clear();

		Packet elfSend;
		Packet santaReceive; // Elf presses the key, Santa is able to get an information 

		int counter = 0; 
		while (true) {

			renderWindow.clear();
			Event event;

			keyInput(p1);
			if (counter == 100) { 
				cooldown = false;
				counter = 0; // if the counter reaches 100, it resets
			}
			if (cooldown) {
				counter++; 
			}


			while (renderWindow.pollEvent(event))
			{
				
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					renderWindow.close();
					break;
					// key pressed
				case sf::Event::KeyPressed:
					break;
					// Space key released 
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
			//send x position of the elf 
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
		cout << "client made" << endl;  // if connection is made

	else {
		cout << "connection not made" << endl;
		return 0; // if its not made
	}
	
	socket.setBlocking(true); // waits for a  connection to the socket than executes the rest of the code 
	Packet packet;
	
	string playerchoice; // Creates a packet. Puts a string in the packet.
	packet >> playerchoice;
	player = playerchoice;
	
	int width = 1244;
	int height = 837;
	RenderWindow newWindow(VideoMode(width, height), "SÁNTA GAME"); // renders the window

	Texture texture4; 
	if (texture4.loadFromFile("Newgame.jpg") != true) { 
	}
	Sprite newgame;
	newgame.setTexture(texture4); // renders the background

	while (true) {
		newWindow.clear();
		newWindow.draw(newgame);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // if the button "new game" is clicked on 
			if (sf::Mouse::getPosition(newWindow).y > 522 && sf::Mouse::getPosition(newWindow).y < 567 && sf::Mouse::getPosition(newWindow).x > 485 && sf::Mouse::getPosition(newWindow).x < 795) {
				if (player == "santa") {
					Santa* p1 = new Santa(width / 2); 
					Elf* p2 = new Elf(width / 2); // creates new santa and elf object in the middle of the screen width
					newWindow.close();
					gameRun(p1, p2); // starts the gametun functuin
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

