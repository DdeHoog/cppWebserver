#include "HttpParser.hpp"

#include <vector>
#include <sstream>
#include <stdio.h> 
#include <string.h>

template<> EnumParser<Method>::EnumParser()
{
    enumMap["GET"] = GET;
    enumMap["PUT"] = PUT;
    enumMap["POST"] = PUT;
}

template<> EnumParser<Version>::EnumParser()
{
    enumMap["HTTP/1.0"] = HTTPV1DOT0;
    enumMap["HTTP/1.1"] = HTTPV1DOT1;
    enumMap["HTTP/2.0"] = HTTPV2DOT0;
}

HttpRequest *HttpParserV1Dot0::Parse(char* req)
{
    std::cout << "HTTP/1.0\n";
    HttpRequest* request = new HttpRequest();
    return request;
}

HttpRequest *HttpParserV1Dot1::Parse(char* req)
{
    HttpV1Dot1GetRequest* request = new HttpV1Dot1GetRequest();

    EnumParser<Method> methodParser;
    EnumParser<Version> versionParser;

    //TODO: Use a map that maps each HTTP header to its corresponding property
    request->method = methodParser.ParseSomeEnum(strtok(req, " "));
    request->path = strtok(NULL, " ");
    request->version = versionParser.ParseSomeEnum(strtok(NULL, " "));
    strtok(NULL, " ");
    request->host = strtok(NULL, " ");
    strtok(NULL, " ");
    request->accept = strtok(NULL, " ");
    strtok(NULL, " ");
    request->acceptLanguage = strtok(NULL, " ");
    strtok(NULL, " ");
    request->acceptEncoding = strtok(NULL, " ");
    strtok(NULL, " ");
    request->userAgent = strtok(NULL, " ");

    return request;
}

HttpRequest *HttpParserV2Dot0::Parse(char* req)
{
    std::cout << "HTTP/2.0\n";
    HttpRequest* request = new HttpRequest();
    return request;
}

char* HttpParser::GetVersion(char* data){
    strtok(data, " ");
    strtok(NULL, " ");
    return strtok(NULL, " ");
}

HttpParser *HttpParser::MakeParser(char* version)
{
    EnumParser<Version> versionParser;
    Version _version = versionParser.ParseSomeEnum(version);

    if(_version == HTTPV1DOT0){
        return new HttpParserV1Dot0();
    }else if(_version == HTTPV1DOT1){
        return new HttpParserV1Dot1();
    }else if(_version == HTTPV2DOT0){
        return new HttpParserV2Dot0();
    }
    return NULL;
}