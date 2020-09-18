//as seen at the tutorial: https://www.youtube.com/watch?v=XZ15UEu3FzE

#include<iostream>
#include<WS2tcpip.h>
#include<thread>
#include<sstream>
#include<vector>

int client() {
	//INITIALIZE WINSOCK
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//CREATE CONNECTION SOCKET
	sockaddr_in connect_adress;
	connect_adress.sin_family = AF_INET; //specifying address family ipv4
	connect_adress.sin_port = htons(666); //server port
    connect_adress.sin_addr.s_addr = inet_addr("127.0.0.1"); //server ip


	SOCKET cSocket = socket(AF_INET, SOCK_STREAM, 0);

	connect(cSocket, (sockaddr*)&connect_adress, sizeof(connect_adress));

	std::string message = "hello from the other side"; // string to send

	send(cSocket, message.c_str(), message.size()+1, 0); //sends string 

	//CLEAN UP
	closesocket(cSocket);
	WSACleanup();

	return 0;
}



