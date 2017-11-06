// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ws2tcpip.h>


#pragma comment (lib, "ws2_32.lib")
using namespace std;

void Server() {

	//initialize winsock
	WSADATA wsdata;
	WORD ver = MAKEWORD(2, 2);

	int wsok = WSAStartup(ver, &wsdata);
	if (wsok != 0)
	{
		cerr << "cant do shit" << endl;
		return;
	}
	//create socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "cant creat socket" << endl;
		return;
	}
	//bind the  ip adrrese and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; //can also use Inet_pton
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	//tell winsock the socket is for listening
	listen(listening, SOMAXCONN);

	//wait for connection
	sockaddr_in client;
	int clientsize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientsize);
	if (clientSocket == INVALID_SOCKET) // do something
	{
		cerr << "invalid socket" << endl;
	}
	char host[NI_MAXHOST]; //client's remote name
	char service[NI_MAXSERV]; //Service (i.e port ) the client is connect on
	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << "connected on port" << service << endl;

	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << "connected on port" <<
			ntohs(client.sin_port) << endl;
	}
	//close listening socket
	closesocket(listening);
	// while loop:accept and echo message back to client
	char buf[4096];
	while (true)
	{
		ZeroMemory(buf, 4096);
		//wait for client to send data 
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << "error in recv(). quitting" << endl;
			break;
		}
		if (bytesReceived == 0)
		{
			cout << "Client discornected" << endl;
			break;
		}
		cout << string(buf, 0, bytesReceived) << endl;

		//echo message back to client 
		send(clientSocket, buf, bytesReceived + 1, 0);


	}
	//close that shit
	closesocket(clientSocket);
	//cleanup winsock
	WSACleanup();
}