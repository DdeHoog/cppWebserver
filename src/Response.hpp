#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#include <thread>
#include <sstream>
#include <vector>
#include <conio.h>
#include <stdio.h>

class Response {
    public:
        HttpV1Dot1GetResponse* BuildResponse(HttpV1Dot1GetRequest* req);
        std::string ContentsOf(std::string file);
        int SizeOf(std::string file);
};

#endif 