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
sf::IpAddress a3 = sf::IpAddress::getLocalAddress();
sf::TcpSocket client1; // creating a socket which will be needed to recieve data
sf::TcpSocket client2;
sf::TcpSocket client1R;
sf::TcpSocket client2R;

std::size_t recieved;

sf::TcpListener client1Listener; // creating a listener 

sf::TcpListener client2Listener;
int main() {


	



	sf::Packet packet;
	//int Xelf, Xsanta;
	//int Yelf, Ysanta;



	
		client1Listener.listen(43000); //  setting a port number of the listener
		client1Listener.accept(client1);// if the listener recives data it willa accept the socket
		client1Listener.setBlocking(false);

		

		//client2Listener.listen(33000); //  setting a port number of the listener
		client2Listener.accept(client2);// if the listener recives data it willa accept the socket
		client2Listener.setBlocking(false);
		
	//client1R.connect(a2,33000);
	//
		client2R.connect(a3, 44000);
		//client2R.connect(a3,44000);
		// Data extracted successfully...
		
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
	

		
	
			
		










	}




