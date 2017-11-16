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

struct propsstruct
{
	float x;
	float y;
	int type;
};

struct elftemp
{
	float xtemp;

};
struct santatemp
{
	float xtemp;
	vector<Props*>* droplisttemp;
};
sf::Packet& operator <<(sf::Packet& packet, propsstruct& character)
{
	return packet << character.x << character.y << character.type;
}
sf::Packet& operator >>(sf::Packet& packet, propsstruct& character)
{
	return packet >> character.x >> character.y >> character.type;
}
sf::Packet& operator <<(sf::Packet& packet, std::vector<Props*>* tempsomething)
{
	return packet << tempsomething;
}
sf::Packet& operator >>(sf::Packet& packet, std::vector<Props*>* tempsomething)
{
	return packet >> tempsomething;
}
sf::Packet& operator <<(sf::Packet& packet, elftemp character)
{
	return packet << character.xtemp;
}
sf::Packet& operator >>(sf::Packet& packet, elftemp* character)
{
	return packet >> character->xtemp;
}
sf::Packet& operator <<(sf::Packet& packet, santatemp character)
{
	//cout << character.droplisttemp->size() << endl;
	if (character.droplisttemp->size() != 0) {
			return packet << character.xtemp << character.droplisttemp;
	}
	return packet << character.xtemp;

}
sf::Packet& operator >>(sf::Packet& packet, santatemp* character)
{
	//cout << character->droplisttemp->size() << endl;
	if (character->droplisttemp->size() != 0) {
		return packet >> character->xtemp >> character->droplisttemp;
	}
	return packet >> character->xtemp;
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
		//p1->move_x(-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && p1->get_x() <= 1276 - 123)
	{
		// left key is pressed: move our character
		//cout << "nothing" << endl;
		//p1->move_x(1);
	}
}


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
	RenderWindow renderWindow(sf::VideoMode(width, height), "SANTA GAME");


	Sprite* playerone = p1->get_img();
	Sprite* playertwo = p2->get_img();

	sf::Texture background_texture;
	background_texture.loadFromFile("game.jpg");
	Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	background_sprite.setPosition(0, 0);


	float elfX;
	float santaXpos;
	while (true) {
		renderWindow.clear();
		//keyInput(p1);
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


			
			//feedbackSanta(p1);

			//cout << counter << endl;
			while (renderWindow.pollEvent(event))
			{

				keyInput(p1);



				if (counter == 500) {
					cooldown = false;
					counter = 0;
				}
				if (cooldown) {
					counter++;
				}
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
			/*
			santatemp tempSantaSend;
			tempSantaSend.xtemp = p1->get_x();
			tempSantaSend.droplisttemp = p1->get_drop_list();
			//tempSantaSend.droplisttemp = p1->get_drop_list();

			*/
			//send x
			santaXpos = p1->get_x();
			cout << "Santa X position: " << santaXpos << endl;
			santaSend << santaXpos;
			socket.send(santaSend);

			//send count
			Packet countnotifier;
			countnotifier << p1->get_drop_list()->size();
			cout << "count notifier: " << p1->get_drop_list()->size() << endl;
			socket.send(countnotifier);
			countnotifier.clear();

			//send per count each prop
			propsstruct doesthiswork;
			for (int i = 0 ; i < p1->get_drop_list()->size(); i++)
			{
				santaSend.clear();
				doesthiswork.x = p1->get_drop_list()->operator[](i)->get_x();
				doesthiswork.y = p1->get_drop_list()->operator[](i)->get_y();
				doesthiswork.type = p1->get_drop_list()->operator[](i)->get_type();
				santaSend << doesthiswork;
				socket.send(santaSend);
			}

			socket.receive(elfReceived);
			elftemp* tempo = new elftemp;
			elfReceived >> tempo;
			p2->set_x(tempo->xtemp);

			//p2->set_x(elfX);


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
Props* tempprop = new Props(0);
void gameRun(Elf* p1, Santa* p2) {

	//Get input from server regarding who is who


	//Draw
	int width = 1236;
	int height = 833;
	RenderWindow renderWindow(sf::VideoMode(width, height), "ELF GAME");


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

			//receive x for santa first
			socket.receive(santaReceive);
			float santaXpos;
			santaReceive >> santaXpos;
			p2->set_x(santaXpos);
			santaReceive.clear();
			//receive count of prop element
			socket.receive(santaReceive);
			int propcountnotifier;
			santaReceive >> propcountnotifier;
			santaReceive.clear();

			//receive per/ amount of prop element each element of prop
			propsstruct receive_props;
			if (propcountnotifier != 0)
			{
				p2->get_drop_list()->clear();

				for (int i = 0; i < propcountnotifier; i++)
				{
					p2->get_drop_list()->push_back(tempprop);
				}
				for (int i = 0; i < propcountnotifier; i++)
				{
					socket.receive(santaReceive);
					santaReceive >> receive_props;
					p2->get_drop_list()->operator[](i)->set_x(receive_props.x);
					p2->get_drop_list()->operator[](i)->set_y(receive_props.y);
					p2->get_drop_list()->operator[](i)->set_type(receive_props.type);
				}
			}
			cout << p2->get_drop_list()->size() << endl;
			//show every prop element
			elftemp tempElfSend;
			tempElfSend.xtemp = p1->get_x();
			elfSend << tempElfSend;
			socket.send(elfSend);
			elfSend.clear();
			/*
			socket.receive(santaReceive);
			santatemp* tempo = new santatemp();
			santaReceive >> tempo;
			p2->set_x(tempo->xtemp);
			cout << p2->get_drop_list()->size() << endl;
			*/
			/*
			if (!tempo.droplisttemp->size() == 0) {
				p2->set_drop_list(tempo->droplisttemp);
				
			}
			*/
			/*
			santatemp* tempo = new santatemp();
			santaReceive >> tempo;
			p2->set_x(tempo->xtemp);
			if (!tempo->droplisttemp->size() == 0) {
				p2->set_drop_list(tempo->droplisttemp);
				cout << p2->get_drop_list()->size() << endl;
			}
			*/

			santaReceive.clear();


			playerone->setPosition(p1->get_x(), p1->get_y());
			playertwo->setPosition(p2->get_x(), p2->get_y());

			
			renderWindow.draw(background_sprite);
			renderWindow.draw(*playerone);
			renderWindow.draw(*playertwo);
			/*
			for (int i = 0; i < p2->get_drop_list()->size(); i++) {
				renderWindow.draw(*p2->get_drop_list()->operator[](i)->get_image());
			}
			*/
			

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
		return 0;
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
	RenderWindow newWindow(sf::VideoMode(width, height), "SÁNTA GAME");

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

