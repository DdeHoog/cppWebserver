#include "gtest/gtest.h"
#include "Sender.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

TEST(SenderTests, Sendtest) {
    
    Sender* sender = new Sender();

    HttpV1Dot1GetResponse* expectedResponse = new HttpV1Dot1GetResponse();
    expectedResponse->version = HTTPV1DOT1;
    expectedResponse->statuscode = "200";
    expectedResponse->statusmessage = "OK";
    expectedResponse->type = "text/html";
    expectedResponse->size = sender->SizeOf("/");
    expectedResponse->message = sender->ContentsOf("/");

    EXPECT_EQ(request->version, expectedRequest->version);
    EXPECT_EQ(request->statuscode, expectedRequest->statuscode);
    EXPECT_EQ(request->statusmessage, expectedRequest->statusmessage);
    EXPECT_EQ(request->type, expectedRequest->type);
    EXPECT_EQ(request->size, expectedRequest->size);
    EXPECT_EQ(request->message, expectedRequest->message);
    
}