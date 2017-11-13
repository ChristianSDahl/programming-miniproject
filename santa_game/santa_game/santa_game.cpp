// santa_game.cpp : Defines the entry point for the console application.
//


//#include <opencv2/opencv.hpp>
#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "Santa.h"
#include "Elf.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include <SFML/System/Time.hpp>


using namespace std;
using namespace cv;
using namespace sf;


bool cooldown = false;
string player;

TcpSocket socket;
IpAddress localhost;
Socket::Status status = socket.connect(localhost.getLocalAddress(), 44000);

sf::Packet& operator <<(sf::Packet& packet, Santa* character)
{

	//cout << character->get_drop_list()->size() << endl;
	float x = character->get_x();
	float y;
	float y2;
	
	for (int i = 0; i < character->get_drop_list()->size(); i++) {
		//drop_list.push_back(*character->get_drop_list()->operator[](i));
		//cout << drop_list[i].get_y() << endl;
		//float y = drop_list[1].get_y();
		//float y2 = drop_list[2].get_y();
		cout << i << ": " << character->get_drop_list()->operator[](i)->get_y() << endl;

		//cout << "in the loop" << endl;
		//return packet << character->get_x() << y << y2;
	}
	
	
	return packet << character->get_x() << character->get_drop_list();// << character->get_drop_list();
}

sf::Packet& operator >>(sf::Packet& packet, Santa* character)
{
	float x = character->get_x();
	vector<Props> drops;
	for (int i = character->get_drop_list()->size(); i > 0; i--) {
		//error here
		drops.push_back(*character->get_drop_list()->operator[](i));
	}

	return packet >> x >> drops;
}

sf::Packet& operator >>(sf::Packet& packet, vector<Props*>* drop_list)
{
	return packet << drop_list;
}

sf::Packet& operator <<(sf::Packet& packet, Elf* character)
{
	float x = character->get_x();
	return packet << x ;// << character->get_drop_list();
}


sf::Packet& operator >>(sf::Packet& packet, Elf* character)
{
	float x = character->get_x();
	return packet << x; // << character->get_drop_list();
}




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


/*
sf::IpAddress a1 = sf::IpAddress::getLocalAddress();

sf::IpAddress a2 = sf::IpAddress::getLocalAddress();//creating the server,  setting ip address on of it to your local computers ip
sf::TcpSocket socketSend; // creating a socket which will be needed to recieve data

sf::TcpSocket santaBack;
sf::TcpListener santaBackListener;
sf::Socket::Status status = socketSend.connect(a2, 44000);
*/


void feedbackSanta(Santa *n,Elf *b) {
	Packet data;
	//data << n;

	int santaXpos,propsXpos,propsYpos,elfXpos;
	
	//santaBack.receive(data);
	
	data >> propsXpos >> propsYpos >> santaXpos >> elfXpos;
	n->set_x(santaXpos);
	//santaBack.receive(packetDrop);
	//n->action();
	
	/*for (int i = 0; i < n->get_drop_list()->size(); i++)
	{
	n->get_drop_list()->operator[](i)->set_x(dropXpos);
	n->get_drop_list()->operator[](i)->set_y(dropYpos);
	n->get_drop_list()->operator[](i)->set_gravity(gravityProps);


	//elfSocket.send(packetDrop);

	}*/
	n->set_x(santaXpos);
	cout << santaXpos << "comeonNNSNDNASNDSANNASD" << endl;
	data.clear();


}


void santaSend( Santa *n, Elf *b) {


		Packet data;
		int santaXpos, propsXpos, propsYpos, elfXpos;
		santaXpos = n->get_x();
		elfXpos = b->get_x();
		propsXpos = 1;
		propsYpos = 1;
	
		cout << "something " << santaXpos << endl;



		/*for (int i = 0; i < n->get_drop_list()->size(); i++)
		{



			propsXpos = n->get_drop_list()->operator[](i)->get_x();
			propsYpos = n->get_drop_list()->operator[](i)->get_y();

			data << propsXpos << propsYpos << santaXpos<<elfXpos;
		

			socketSend.send(data);
			data.clear();
	
		}*/
		data << propsXpos << propsYpos << santaXpos << elfXpos;
		//->set_x(santaXpos);
		//cout <<"new position"<<santaXpos << endl;


		//socketSend.send(data);

		data.clear();
		
}	



//santa
void gameRun(Santa* p1, Elf* p2) {
	//Santa is player one

	//Get input from server regarding who is who
	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");


	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	sf::Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);


	float elfX;
	while (true) {
		renderWindow.clear();
		keyInput(p1);
		Packet santaSend;
		Packet elfReceived;


		int counter = 0;
		while (true) {
			renderWindow.clear();

			//santaBackListener.setBlocking(false);
			//santaSend(p1, p2);
			//feedbackSanta(p1, p2);
			//santaBackListener.listen(6000);
			//santaBackListener.accept(santaBack);

			Event event;
			keyInput(p1);

			

			if (counter == 500) {
				cooldown = false;
				counter = 0;
			}
			if (cooldown) {
				counter++;
			}

			
			//feedbackSanta(p1);

			//cout << counter << endl;
			while (renderWindow.pollEvent(event))
			{


				//santaSend( p1,p2);/////////
				//feedbackSanta(p1, p2);														 ///////////
				//elfSend(p2->get_x(), p2->get_x(), p1->get_drop_list(), p2);///////////
				
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

			santaSend << p1;
			socket.send(santaSend);

			santaSend.clear();

			socket.receive(elfReceived);

			elfReceived >> elfX;

			p2->set_x(elfX);


			elfReceived.clear();



			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());
			//cout << "data" << elfX << endl;
			//feedbackSanta(p1, p2);
			//santaSend(p1, p2);
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

	//Get input from server regarding who is who


	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "My window");


	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	sf::Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);


	float santaX;
	while (true) {
		
		renderWindow.clear();
		keyInput(p1);
		Packet elfSend;
		Packet santaReceive;



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

			//cout << counter << endl;
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
					// we don't process other types of events
				default:
					break;
				}
			}


			elfSend << p1;
			socket.send(elfSend);
			elfSend.clear();

			socket.receive(santaReceive);
			float fuckyou = 10;
			Santa* p3 = new Santa(fuckyou);
			santaReceive >> p3;
			cout << "drop list size: " << p3->get_drop_list()->size() << endl;
			
			p2->set_x(p3->get_x());

			santaReceive.clear();


			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());

			
			renderWindow.draw(background_sprite);
			renderWindow.draw(*playerone);
			renderWindow.draw(*playertwo);
			
			for (int i = 0; i < p2->get_drop_list()->size(); i++) {
				renderWindow.draw(*p2->get_drop_list()->operator[](i)->get_image());
			}
			

			renderWindow.display();

		}
	}
}

int main()
{
//	santaBackListener.listen(44000); //  setting a port number of the listener
	//setBlocking(true);
//	santaBackListener.accept(santaBack);// if the listener recives data it willa accept the socket
	
	if (status == Socket::Status::Done) {
		cout << "client made" << endl;
	}
	else {
		cout << "connection not made" << endl;
	}
	
	socket.setBlocking(true);
	Packet packet;
	socket.receive(packet);
	string playerchoice;
	packet >> playerchoice;
	player = playerchoice;
	

	//santaBackListener.setBlocking(false);
	//sf::IpAddress a3 = sf::IpAddress::getLocalAddress();
	//socketSend.connect(a2, 33000);
	/*Packet p;
	int i = 1;
	p << i;
	socketSend.send(p);
	*/
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
			//cout << sf::Mouse::getPosition(newWindow).x << ", " << sf::Mouse::getPosition(newWindow).y << endl;
			if (sf::Mouse::getPosition(newWindow).y > 522 && sf::Mouse::getPosition(newWindow).y < 567 && sf::Mouse::getPosition(newWindow).x > 485 && sf::Mouse::getPosition(newWindow).x < 795) {
				//cout << "test" << endl;
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
		}

	
		newWindow.display();
	}

	return 0;
}

