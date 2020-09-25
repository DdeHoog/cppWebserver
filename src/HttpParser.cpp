#include "HttpParser.hpp"

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

std::string HttpParser::GetVersion(std::string req){
    std::istringstream iss(req);
    std::string line;
    std::getline(iss, line);
    std::vector<std::string> tokens = GetTokens(line, WHITESPACE);
    return tokens[2];
}

HttpParser *HttpParser::MakeParser(std::string version)
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

std::vector<std::string> HttpParser::GetTokens(std::string header, std::string del){
    std::vector<std::string> tokens;
    std::string delimiter = del;
    size_t pos = 0;
    std::string token;
    while ((pos = header.find(delimiter)) != std::string::npos) {
        token = header.substr(0, pos);
        tokens.push_back(token);
        header.erase(0, pos + delimiter.length());
    }

    //TODO: find better way to get last element
    header.erase(remove(header.begin(), header.end(), '\r'), header.end());
    token = header.substr(0, pos);
    tokens.push_back(token);

    return tokens;
}

HttpRequest *HttpParserV1Dot0::Parse(std::string req)
{
    std::cout << "HTTP/1.0\n";
    HttpRequest* request = new HttpRequest();
    return request;
}

HttpRequest *HttpParserV1Dot1::Parse(std::string req)
{
    HttpV1Dot1GetRequest* request = new HttpV1Dot1GetRequest();

    EnumParser<Method> methodParser;
    EnumParser<Version> versionParser;

    // get all HTTP header lines
    std::istringstream iss(req);
    std::vector<std::vector<std::string>> lines;
    std::string line;
    int i = 0;
    while (std::getline(iss, line))
    {
        if(i == 0){
            lines.push_back(GetTokens(line, WHITESPACE));
        }else{
            lines.push_back(GetTokens(line, COLON));
        }
        i++;
    }

    //TODO: Use a map that maps each HTTP header to its corresponding property
    request->method = methodParser.ParseSomeEnum(lines[0][0]);
    request->path = lines[0][1];
    request->version = versionParser.ParseSomeEnum(lines[0][2]);
    request->host = lines[1][1];
    request->connection = lines[2][1];
    request->cacheControl = lines[3][1];
    request->upgradeInsecureRequests = lines[4][1];
    request->userAgent = lines[5][1];
    request->accept = lines[6][1];
    request->secFetchSite = lines[7][1];
    request->secFetchMode = lines[8][1];
    request->secFetchUser = lines[9][1];
    request->secFetchDest = lines[10][1];
    request->acceptEncoding = lines[11][1];
    request->acceptLanguage = lines[12][1];

    return request;
}

HttpRequest *HttpParserV2Dot0::Parse(std::string req)
{
    std::cout << "HTTP/2.0\n";
    HttpRequest* request = new HttpRequest();
    return request;
}