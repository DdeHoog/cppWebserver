//tutorial source: https://www.youtube.com/watch?v=XZ15UEu3FzE
#include<iostream>
#include<WS2tcpip.h>
#include<thread>
#include<sstream>
#include<vector>

int main() {
    int number = 666;

    //intialising winsock
    WSADATA someData; //init variable
    WSAStartup(MAKEWORD(2, 2), &someData); //startup function, params: WS version (2) and the WSAData variable

    //CREATING SERVER SOCKET
    sockaddr_in listen_address;
    listen_address.sin_family = AF_INET; //specify family of the socket. Type of adress, for ipv4 use AF_INET.
    listen_address.sin_port = htons(number); //set the port for the socket address. Use the htons function to do this.
    listen_address.sin_addr.S_un.S_addr = INADDR_ANY;
    /*specifies which clients can connect to the server. 
    * using INADDR_ANY = in adress any, anyone can connect.
    * see https://stackoverflow.com/questions/23187496/what-is-the-meaning-of-sin-addr-s-addr-and-inet-addr 
    * for more info on this.*/

   SOCKET listen_socket = socket(AF_INET, SOCK_STREAM, 0); //creates the socket
   //params: Adress family AF_INET, tcp protocol SOCK_STREAM, and the 0 for protocols.

   bind(listen_socket, (sockaddr*)&listen_address, sizeof(listen_address));
   //combine the data, params: the socket (listen_socket), the address(sockaddr*) and the size of the adress.

   listen(listen_socket, SOMAXCONN);
   //listen function, params: socket and  the amount of connections the socket will take. SOMAXCONN makes this unlimited.

   //WAIT FOR CONNECTION
   SOCKET client = accept(listen_socket, NULL, NULL); //creates a client socket. can replace 'SOCKET client' with 'listen_socket' for single client.
   /* accept function params: the socket, adress of the socket, size of the socket address. 
    * leaving this as null if you dont need this information.
    * the 2nd param takes the address as a parameter because it stores client information in there.*/

   //RECEIVE MESSAGE
   char buffer[1024]{0}; //message buffer to store the received message
   //1024 max size char of message, {0} reset the buffer to empty.

   recv(listen_socket, buffer, sizeof(buffer), 0);
   //params: your socket, the buffer, size of buffer and the flags set to 0

   std::cout << buffer << std::endl; //prints out the received message

   //PAUSE AND CLEANUP
   system("pause");
   closesocket(listen_socket);
   WSACleanup();

    return 0;
}