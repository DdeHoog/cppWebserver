#ifndef PARSER_HPP
#define PARSER_HPP

#include "Utils.hpp"
#include "HttpRequest.hpp"

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h> 
#include <string.h>
#include <string>

#define WHITESPACE " "
#define COLON ": "

class HttpParser
{
  public:
    static std::vector<std::string> GetTokens(std::string header, std::string del);
    static std::string GetVersion(std::string req);
    static HttpParser* MakeParser(std::string version);
    virtual HttpRequest* Parse(std::string req)=0;
};

class HttpParserV1Dot0 : public HttpParser {
  public:
    HttpRequest* Parse(std::string req);
};

class HttpParserV1Dot1 : public HttpParser { 
  public:
    HttpRequest* Parse(std::string req);
};

class HttpParserV2Dot0 : public HttpParser {
  public:
    HttpRequest* Parse(std::string req);
};

#endif