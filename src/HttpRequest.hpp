#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Utils.hpp"

#include <stdlib.h>
#include <string>

enum Method { GET, PUT, POST };
enum Version{ HTTPV1DOT0, HTTPV1DOT1, HTTPV2DOT0 };

class HttpRequest{};

class HttpV1Dot1GetRequest : public HttpRequest{
    public:
        Method method;
        std::string path;
        Version version;
        std::string host;
        std::string connection;
        std::string cacheControl;
        std::string upgradeInsecureRequests;
        std::string userAgent;
        std::string accept;
        std::string secFetchSite;
        std::string secFetchMode;
        std::string secFetchUser;
        std::string secFetchDest;
        std::string acceptLanguage;
        std::string acceptEncoding;

        HttpV1Dot1GetRequest(){};
};

#endif