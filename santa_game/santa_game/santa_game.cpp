// santa_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <opencv2/opencv.hpp>
#include <SFML\Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include "Santa.h"
#include "Elf.h"

//Server
sf::IpAddress a1 = sf::IpAddress::getLocalAddress(); //creating the server,  setting ip address on of it to your local computers ip
sf::TcpSocket SantaSocket; // creating a socket which will be needed to recieve data
sf::TcpSocket ElfSocket;


	


using namespace std;
using namespace cv;
using namespace sf;



/*void recieved() {



	string b = "fuck u all";
	Packet packet;
	
	ElfSocket.receive(packet);
	
	int elfXpos, elfYpos;

	packet >> elfXpos >> elfYpos;

	packet << elfXpos<< 'b' << elfYpos;




}*/


void send(int a, int b) {
	int elfXpos = a;
	int elfYpos = b;

	Packet packet;
	packet << elfXpos << elfYpos;

	ElfSocket.connect(a1, 5000);
	ElfSocket.send(packet);

	packet.clear();

}



void keyInput(Santa* p1) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "smth" << endl;
	
		
		
		//int Xelf = p1->get_x();		// asigning the x value of elf to a packet sent to the server
	//	int Yelf = p1->get_y();
	//	send(Xelf, Yelf);
	

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1236 - 123)
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "nothing" << endl;
		p1->move_x(1);
		//int Xelf = p1->get_x();		// asigning the x value of elf to a packet sent to the server
	//	int Yelf = p1->get_y();
		//send(Xelf, Yelf);
	
	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "smth else" << endl;
		
	}
}

void keyInput(Elf* p1) {

	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "smth" << endl;
		cout << p1->get_x() << endl;
		p1->move_x(-1);
		int elfXpos = p1->get_x();
		int elfYpos = p1->get_x();
		send(elfXpos, elfYpos);

		//int Xelf = p1->get_x();
	//	int Yelf = p1->get_y();
		//send(Xelf, Yelf);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "nothing" << endl;
		p1->move_x(1);
		          		int elfXpos = p1->get_x();
		int elfYpos = p1->get_x();
		send(elfXpos, elfYpos);
		

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		// left key is pressed: move our character
		//character.move(1, 0);
		cout << "smth else" << endl;

	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123 || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && p1->get_x() >= 0)
	{

		p1->get_x();
		buffer = p1;



	}*/
}





int main()
{
	//Get input from server regarding who is who
	//Santa* p1 = new Santa(width / 2);
	//Elf* p2 = new Elf(width / 2);

	//ElfListener.listen(5000); //  setting a port number of the listener
	//ElfListener.accept(ElfSocket);// if the listener recives data it willa accept the socket

	ElfSocket.setBlocking(false);
	SantaSocket.connect(a1, 4000); //  client connecting to the socket a1 on a prot of 3000
	size_t size;










	
	sf::String myDisplayableText;

	

	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");

	Santa* p2 = new Santa(width / 2);
	Elf* p1 = new Elf(width / 2);


	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();
	while (true) {


		
	
		renderWindow.clear();
		keyInput(p1);
		playerone->setPosition(p1->get_x(),p1->get_y());
		playertwo->setPosition(p2->get_x(), p2->get_y());
		renderWindow.draw(*playerone);
		renderWindow.draw(*playertwo);
	
	
		
		
		
		

		 
	

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