#ifndef SENDER_HPP
#define SENDER_HPP

#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#include <thread>
#include <sstream>
#include <vector>


class Sender {
    public:
        Sender(){};
        std::string Send(std::string host, std::string file, std::string type, std::string version, std::string errorcode, std::string statusmessage);
        std::string ContentsOf(std::string file);
        int SizeOf(std::string file);
};

#endif 