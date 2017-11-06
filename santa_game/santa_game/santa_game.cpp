// santa_game.cpp : Defines the entry point for the console application.
//

#pragma comment (lib, "ws2_32.lib")
#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <SFML\Graphics.hpp>
#include <ws2tcpip.h>
#include <WinSock2.h> 
using namespace std;
using namespace cv;
using namespace sf;

int main()
{
	//Winsock startup 
	WSAData wsadata;
	WORD ver = MAKEWORD(2, 2);
	if (WSAStartup(ver, &wsadata) != 0) // if WSAStarup returns anything other than 0 
	{
		cerr << "Error" << endl;
		return;
	}
	//Create socket 
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "cant create socket, err #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}
	SOCKADDR_IN addr; //Address that will bind the listening socket to 
	int addrlen = sizeof(addr); //length of the anddress 
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local broadcast
	addr.sin_port = htons(54000); // the port 
	addr.sin_family = AF_INET; //iPv4 socket

	int connResult = connect(sock, (sockaddr*)&addr, sizeof(addr));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "cant connect to server, err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
	std::cout << "connected to Server" << std::endl;

	/*
	std::vector<int> mylist;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		mylist.push_back(myint);
		std::cin >> myint;
		mylist.push_back(myint);
		break;
	} while (myint);

	std::cout << "mylist stores " << mylist.size() << " numbers.\n" << endl;
	for (int i = 0; i < mylist.size();i++) {
		std::cout << mylist[i] << endl;
	}
	//getchar;
	*/
	RenderWindow renderWindow(sf::VideoMode(1280, 720), "My window");

	sf::Texture texture;
	if (texture.loadFromFile("maxresdefault.jpg") != true)
	{
		return 0;
	}

	sf::Sprite sprite(texture);
	while (true) {
		renderWindow.clear();
		sprite.setPosition(200, 200);
		renderWindow.draw(sprite, sf::RenderStates::Default);
		renderWindow.display();
	}
	return 0;
}

