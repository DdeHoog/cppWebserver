#include "gtest/gtest.h"
#include "../src/Sender.hpp"

TEST(SenderTests, Sendtest) {
   
    EXPECT_EQ (Sender::Send(std::string "host", std::string "/html/index", std::string "type", std::string "version", std::string "errorcode", std::string "statusmessage"),
     "version errorcode statusmessage\nContent-Type: type\nContent-Length: 777\n"); //class::method
    //change params with values
}