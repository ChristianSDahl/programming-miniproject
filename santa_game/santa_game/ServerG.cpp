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
	


		sf::IpAddress a1 = sf::IpAddress::getLocalAddress();
		sf::TcpSocket socket;
		char connectionType, mode;
		char buffer[2000];

		std::size_t recieved;
		std::string text = "connected to:";

		std::cout << "Enter (s) for server , C for client:" << std::endl;
		cin >> connectionType;

		if (connectionType == 's') {

			sf::TcpListener listener;
			listener.listen(3000);
			listener.accept(socket);
			text += "server";
			mode = 's';

			socket.send(text.c_str(), text.length() + 1);
			cin >> connectionType;





		}

		else if (connectionType == 'c')
		{

			socket.connect(a1, 3000);
			text += "client";
			mode = 'r';
			cin >> connectionType;


		}

		socket.send(text.c_str(), text.length() + 1);

		socket.receive(buffer, sizeof(buffer), recieved);
	std:cout << buffer << std::endl;
		std::getline(cin, text);




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
				cout << "received" << buffer << endl;
					mode = 's';

				}
			}

		}
		system("pause");
		return 0;

	}

};
