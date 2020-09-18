#include "gtest/gtest.h"
#include "../src/Sender.hpp"

TEST(SenderTests, Sendtest) {
    Sender* sender = new Sender();
    std::string temp = sender->Send("host", "/html/index", "type", "version", "errorcode", "statusmessage");
    EXPECT_EQ(temp, "version");
}