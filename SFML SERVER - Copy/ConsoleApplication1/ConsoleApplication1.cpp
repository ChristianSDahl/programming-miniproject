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




int main() {


	



	sf::Packet packet;
	//int Xelf, Xsanta;
	//int Yelf, Ysanta;



	sf::IpAddress a1 = sf::IpAddress::getLocalAddress(); //creating the server,  setting ip address on of it to your local computers ip


	sf::TcpSocket Santa; // creating a socket which will be needed to recieve data
	sf::TcpSocket Elf;
	std::size_t recieved;

		sf::TcpListener SantaListener; // creating a listener 
		SantaListener.listen(4000); //  setting a port number of the listener
		SantaListener.accept(Santa);// if the listener recives data it willa accept the socket
		SantaListener.setBlocking(false);

		sf::TcpListener ElfListener;
		ElfListener.listen(5000); //  setting a port number of the listener
		ElfListener.accept(Elf);// if the listener recives data it willa accept the socket
		ElfListener.setBlocking(false);

		
		// Data extracted successfully...
		
		while (true) {

			if (Elf.getRemoteAddress() != sf::IpAddress::None) {
					Packet packet;
					Elf.receive(packet);

				int elfXpos, elfYpos;

				packet >> elfXpos >> elfYpos;
				std::cout << elfXpos << std::endl;
				std::cout << elfYpos << std::endl;
				packet.clear();

				
			


			}
		}
	

		
	
			
		










	}




