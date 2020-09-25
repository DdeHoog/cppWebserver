#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>

#include "HttpParser.hpp"

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"

class Server
{
    /**
     * The Server's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    protected:
        Server(const std::string value): value_(value)
        {
        }

        static Server* Server_;

        std::string value_;

    public:

    /**
     * Servers should not be cloneable.
     */
    Server(Server &other) = delete;
    /**
     * Servers should not be assignable.
     */
    void operator=(const Server &) = delete;
    /**
     * This is the static method that controls the access to the Server
     * instance. On the first run, it creates a Server object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static Server *GetInstance(const std::string& value);
    /**
     * Finally, any Server should define some business logic, which can be
     * executed on its instance.
     */
    int StartServer();

    std::string value() const{
        return value_;
    } 
};

#endif