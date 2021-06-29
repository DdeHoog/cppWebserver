#include "HttpRequest.hpp"
#include "HttpParser.hpp"
#include "gtest/gtest.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <fstream>

#define MOCK_REQUEST_FILE "test/mocks/mock_get_request.txt"

TEST(ReceiverTests, HttpParserVersionTest){
    const std::string expectedVersion = "HTTP/1.1";

    ifstream infile { MOCK_REQUEST_FILE };
    string data { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };
    
    std::string version = HttpParser::GetVersion(data);

    bool correctVersion;
    if (version == expectedVersion)
    {
        correctVersion = true;
    }else{
        correctVersion = false;
    }
    EXPECT_TRUE(correctVersion);
}

TEST(ReceiverTests, HttpParserCreationTest){
    ifstream infile { MOCK_REQUEST_FILE };
    string data { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };
    
    std::string version = HttpParser::GetVersion(data);
    HttpParser* parser = HttpParser::MakeParser(version);

    bool correctParserIsBuild;
    if (dynamic_cast<HttpParserV1Dot1*>(parser) == nullptr)
    {
        correctParserIsBuild = false;
    }else{
        correctParserIsBuild = true;
    }
    EXPECT_TRUE(correctParserIsBuild);
}

TEST(ReceiverTests, HttpParserParsingTest){
    ifstream infile { MOCK_REQUEST_FILE };
    string data { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };
    
    std::string version = HttpParser::GetVersion(data);
    HttpParser* parser = HttpParser::MakeParser(version);

    HttpV1Dot1GetRequest* request = (HttpV1Dot1GetRequest*)parser->Parse(data);
    HttpV1Dot1GetRequest* expectedRequest = new HttpV1Dot1GetRequest();
    expectedRequest->method = GET;
    expectedRequest->path = "/";
    expectedRequest->version = HTTPV1DOT1;
    expectedRequest->host = "localhost:27015";
    expectedRequest->connection = "keep-alive";
    expectedRequest->cacheControl = "max-age=0";
    expectedRequest->upgradeInsecureRequests = "1";
    expectedRequest->userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36";
    expectedRequest->accept = "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9";
    expectedRequest->secFetchSite = "none";
    expectedRequest->secFetchMode = "navigate";
    expectedRequest->secFetchUser = "?1";
    expectedRequest->secFetchDest = "document";
    expectedRequest->acceptEncoding = "gzip, deflate, br";
    expectedRequest->acceptLanguage = "en-US,en;q=0.9,ko-KR;q=0.8,ko;q=0.7,nl;q=0.6";

    EXPECT_EQ(request->method, expectedRequest->method);
    EXPECT_EQ(request->path, expectedRequest->path);
    EXPECT_EQ(request->version, expectedRequest->version);
    EXPECT_EQ(request->host, expectedRequest->host);
    EXPECT_EQ(request->connection, expectedRequest->connection);
    EXPECT_EQ(request->cacheControl, expectedRequest->cacheControl);
    EXPECT_EQ(request->upgradeInsecureRequests, expectedRequest->upgradeInsecureRequests);
    EXPECT_EQ(request->userAgent, expectedRequest->userAgent);
    EXPECT_EQ(request->accept, expectedRequest->accept);
    EXPECT_EQ(request->secFetchSite, expectedRequest->secFetchSite);
    EXPECT_EQ(request->secFetchMode, expectedRequest->secFetchMode);
    EXPECT_EQ(request->secFetchUser, expectedRequest->secFetchUser);
    EXPECT_EQ(request->secFetchDest, expectedRequest->secFetchDest);
    EXPECT_EQ(request->acceptLanguage, expectedRequest->acceptLanguage);
    EXPECT_EQ(request->acceptEncoding, expectedRequest->acceptEncoding);
}