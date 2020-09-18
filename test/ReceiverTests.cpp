#include "HttpRequest.hpp"
#include "HttpParser.hpp"
#include "gtest/gtest.h"

#include <vector>
#include <sstream>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

TEST(ReceiverTests, HttpParserTest){
    char data[] = "GET / HTTP/1.1 \nHost: localhost:666 \nAccept: image/gif,image/jpeg,*/* \nAccept-Language: en-us \nAccept-Encoding: gzip,deflate \nUser-Agent: Mozilla/4.0";

    // copy string, so as to not modify the original
    char* tempData = (char*)calloc(strlen(data)+1, sizeof(char));
    strcpy(tempData, data);
    
    char* version = HttpParser::GetVersion(tempData);
    HttpParser* parser = HttpParser::MakeParser(version);

    free(tempData);

    HttpV1Dot1GetRequest* request = (HttpV1Dot1GetRequest*)parser->Parse(data);
    HttpV1Dot1GetRequest* expectedRequest = new HttpV1Dot1GetRequest();
    expectedRequest->method = GET;
    expectedRequest->path = "/";
    expectedRequest->version = HTTPV1DOT1;
    expectedRequest->host = "localhost:666";
    expectedRequest->accept = "image/gif,image/jpeg,*/*";
    expectedRequest->acceptLanguage = "en-us";
    expectedRequest->acceptEncoding = "gzip,deflate";
    expectedRequest->userAgent = "Mozilla/4.0";

    EXPECT_EQ(request->method, expectedRequest->method);
    EXPECT_EQ(request->path, expectedRequest->path);
    EXPECT_EQ(request->version, expectedRequest->version);
    EXPECT_EQ(request->host, expectedRequest->host);
    EXPECT_EQ(request->userAgent, expectedRequest->userAgent);
    EXPECT_EQ(request->accept, expectedRequest->accept);
    EXPECT_EQ(request->acceptLanguage, expectedRequest->acceptLanguage);
    EXPECT_EQ(request->acceptEncoding, expectedRequest->acceptEncoding);
}