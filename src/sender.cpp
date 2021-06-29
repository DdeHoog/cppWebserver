#include "Sender.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <WS2tcpip.h>
#include <thread>
#include <sstream>
#include <vector>
#include <stdio.h>


std::string Sender::Send(std::string host, std::string file, std::string type, std::string version, std::string errorcode, std::string statusmessage){

    std::string message = ContentsOf(file); 
    int size = SizeOf(file);
    char buffer[size + size];
    sprintf(buffer, "%s %s %s\nContent-Type: %s\nContent-Length: %i\n%s",version, errorcode, statusmessage, type, size, message);
    std::stringstream ss;
    std::string response;
    ss << buffer;
    ss >> response;
    return response;

}

std::string Sender::ContentsOf(std::string file){

    std::string contents; 
    std::ifstream fs;

    fs.open(file); 
    if(!fs)
	{
		std::cout<<"Error in opening source file..!!";
		getch();
		exit(1);
	}
    fs >> contents;
    fs.close();

    return contents;

}

int Sender::SizeOf(std::string file){

    std::ifstream contents(file, std::ios::binary);
    contents.seekg(0, std::ios::end);
    int size = contents.tellg();
    contents.close();
    return size;

} 