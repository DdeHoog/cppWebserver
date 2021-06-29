#ifndef HTTPRESPONSE_HPP
#define HTTPRESPONSE_HPP

#include "Utils.hpp"

#include <stdlib.h>
#include <string>

class HttpResponse{};

class HttpV1Dot1GetResponse : public HttpResponse{
    public:
        
        Version version;
        std::string statuscode;
        std::string statusmessage;
        std::string type;
        int size;
        std::string message;

        HttpV1Dot1GetResponse(){};
};

#endif