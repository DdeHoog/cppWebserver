#include "HttpServer.hpp"

int main(){
    Server* Server = Server::GetInstance("ALPHA");
    Server->StartServer();
    return 0;
}