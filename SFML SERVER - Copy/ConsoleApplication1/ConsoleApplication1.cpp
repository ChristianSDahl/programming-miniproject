// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "string"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include <SFML/System/Time.hpp>

using namespace std;
using namespace sf;

sf::IpAddress a1 = sf::IpAddress::getLocalAddress(); //creating the server,  setting ip address on of it to your local computers ip

sf::IpAddress a2 = sf::IpAddress::getLocalAddress(); //creating the server,  setting ip address on of it to your local computers ip
sf::TcpListener listener;
sf::TcpSocket client1; // creating a socket which will be needed to recieve data
sf::TcpSocket client2;


std::size_t recieved;
int main() {
	sf::Packet packet;
	//int Xelf, Xsanta;
	//int Yelf, Ysanta;
		listener.setBlocking(true);
		listener.listen(44000); //  setting a port number of the listener
		listener.accept(client1);// if the listener recives data it willa accept the socket
		cout << "client 1 connected" << endl;	

		//client2Listener.listen(33000); //  setting a port number of the listener
		//listener.listen(44000);
		listener.accept(client2);// if the listener recives data it will accept the socket
		cout << "client 2 connected" << endl;
		
		string s1 = "santa";
		packet << s1;
		client1.send(packet);
		packet.clear();
		string s2 = "elf";
		packet << s2;
		client2.send(packet);
		packet.clear();
		int propcount;
		float santax;
		float elfx;

		while (true) {
			//listener.setBlocking(false);
			//recieves x position of santa
			client1.receive(packet);
			packet >> santax;
			cout << "Santa : X: " << santax << endl;
			//sends x position of santa
			client2.send(packet);
			packet.clear();
			//recieves count of props
			client1.receive(packet);
			//sends count of prop
			client2.send(packet);
			packet >> propcount;
			cout << "Count of props: " << propcount << endl;
			packet.clear();

			for (int i = 0; i < propcount; i++)
			{
				client1.receive(packet);
				client2.send(packet);
				packet.clear();
			}
			//receive from elf
			client2.receive(packet);
			packet >> elfx;
			cout << "Elf's X position: " << elfx << endl;
			client1.send(packet);
			packet.clear();

			cout << "Sucessfully sent" << endl;
		}
		

	//client1R.connect(a2,33000);
	//
		//client2R.connect(a3, 44000);
		//client2R.connect(a3,44000);
		// Data extracted successfully...
		/*
		while (true) {

			if (client1.getRemoteAddress() != sf::IpAddress::None){
				std::cout << "CLIENT 1" << std::endl;
				Packet data;
		
				client1.receive(data);
					
				int santaXpos, propsXpos, propsYpos, elfXpos;
					
				data >>propsXpos >> propsYpos >> santaXpos >> elfXpos;

			
				std::cout << santaXpos << std::endl;
				std::cout << elfXpos << std::endl;
				data << propsXpos << propsYpos << santaXpos << elfXpos;

				client2R.send(data);



				data.clear();

				
			}
			if (client2.getRemoteAddress() != sf::IpAddress::None) {
				std::cout << "CLIENT 2" << std::endl;
				Packet data;
				client2.receive(data);
				int santaXpos, propsXpos, propsYpos, elfXpos;

				data >> propsXpos >> propsYpos >> santaXpos >> elfXpos;


				std::cout << santaXpos << std::endl;
				std::cout << elfXpos << std::endl;
				data << propsXpos << propsYpos << santaXpos << elfXpos;

				client1R.send(data);



				data.clear();


			}
		}
	

		
	
			
		







		*/


	}




