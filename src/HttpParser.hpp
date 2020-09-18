#ifndef PARSER_HPP
#define PARSER_HPP

#include "Utils.hpp"
#include "HttpRequest.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>

class HttpParser
{
  public:
    static char* GetVersion(char* data);
    static HttpParser* MakeParser(char* version);
    virtual HttpRequest* Parse(char* req)=0;
};

class HttpParserV1Dot0 : public HttpParser {
  public:
    HttpRequest* Parse(char* req);
};

class HttpParserV1Dot1 : public HttpParser { 
  public:
    HttpRequest* Parse(char* req);
};

class HttpParserV2Dot0 : public HttpParser {
  public:
    HttpRequest* Parse(char* req);
};

#endif