#include <iostream>
#include "stdafx.h"
#include "string"
#include <opencv2/opencv.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Export.hpp>
#include <SFML/System/Time.hpp>

using namespace std;

class Server
{
public:

	int main() {



		sf::IpAddress a1 = sf::IpAddress::getLocalAddress(); //creating the server,  setting ip address on of it to your local computers ip


		sf::TcpSocket socket; // creating a socket which will be needed to recieve data

		char connectionType, mode; // connectionType will decide which of the 2 users is a server ora  a client  ,,


		char buffer[2000];// creating a char buffer which will contain the data sent from the client to the server and back

		std::size_t recieved; // the size of the data recived 
		std::string text = "connected to:"; //  this string represents the message that the cliend and the server would recieve 

		std::cout << "Enter (s) for server , C for client:" << std::endl; // this message shows on the screen to take the users input 
		cin >> connectionType; // listens for input from the user 

		if (connectionType == 's') { // this if statement will execute if the user types s for a Servere

			sf::TcpListener listener; // creating a listener 
			listener.listen(3000); //  setting a port number of the listener
			listener.accept(socket);// if the listener recives data it willa accept the socket
			text += "server";  // this message extends the message that the clend and the server will recieve 
			mode = 's'; // that variable is to change the modes of them whenever they send or recieve data ( not working yet)

			socket.send(text.c_str(), text.length() + 1); // sendind the extended text to to the client 





		}

		else if (connectionType == 'c') // if the user pressed c for Client  
		{

			socket.connect(a1, 3000); //  client connecting to the socket a1 on a prot of 3000
			text += "client"; // extending the message
			mode = 'r';//  still working on it



		}

		socket.send(text.c_str(), text.length() + 1);

		socket.receive(buffer, sizeof(buffer), recieved); // the socket saves in the variable buffer the size and the content of the message that we want to send
	std:cout << buffer << std::endl;
		std::getline(cin, text);// gets the typed text into a string 




		bool done = false;
		while (!done)
		{

			if (mode == 's')
			{

				std::getline(cin, text);
				socket.send(text.c_str(), text.length() + 1);
				mode = 'r';
			}
			else if (mode == 'r') {
				socket.receive(buffer, size(buffer), recieved);
				if (recieved > 0) {
					std::cout << "received" << buffer << std::endl;
					mode = 's';

				}
			}
		}	
	
		
		system("pause");
		cin.ignore();
		return 0;

	}

};
