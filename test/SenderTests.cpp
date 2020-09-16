#include "gtest/gtest.h"
#include "../src/Sender.hpp"

TEST(SenderTests, Sendtest) {
   
    EXPECT_EQ (Sender::Send("host", "/html/index", "type", "version", "errorcode", "statusmessage")
     "version errorcode statusmessage\nContent-Type: type\nContent-Length: 777\n<html>
    <head>
    <title>Home</title>
    </head>
    <body>
    <h1>Home page</h1>
    </body>
    </html>"); 
    
}