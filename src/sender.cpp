#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#include <thread>
#include <sstream>
#include <vector>

string Sender(string host, string file, string type, string version, string errorcode, string statusmessage){

    string message = ContentsOf(file); //add file content naar de message variable instead of title
    int size = SizeOf(file);
    char *response = "%s %s %s\nContent-Type: %s\nContent-Length: %i\n%s",version, errorcode, statusmessage type, size, message;

}

string ContentsOf(string file){

    string contents; 
    ifstream fs;

    fs.open(file); 
    if(!fs)
	{
		cout<<"Error in opening source file..!!";
		getch();
		exit(1);
	}
    fs >> contents;
    fs.close();

    return contents;

}

int SizeOf(string file){

    ifstream contents(file, ios::binary);
    contents.seekg(0, ios::end);
    int size = contents.tellg();
    contents.close();
    return size;

}