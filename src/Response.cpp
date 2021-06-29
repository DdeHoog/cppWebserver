#include "Response.hpp"



HttpV1Dot1GetResponse* BuildReponse(HttpV1Dot1GetRequest* req){

    std::string file = req->path;
    std::string version = "HTTP/1.1";
    std::string statuscode; //maak class voor. moet aangemaakt worden.
    std::string statusmessage; //maak class voor. moet aangemaakt worden.
    std::string type; //maak class voor. moet aangemaakt worden.
    std::string message = ContentsOf(file); 
    int size = SizeOf(file);
    char buffer[size + size];
    //Build the http response header and include the message
    sprintf(buffer, "%s %s %s\nContent-Type: %s\nContent-Length: %i\n%s",
                version, statuscode, statusmessage, type, size, message);
    std::stringstream ss;
    std::string response;
    ss << buffer;
    ss >> response;

    HttpV1Dot1GetResponse* expectedResponse = new HttpV1Dot1GetResponse();
    expectedResponse->version = HTTPV1DOT1;
    expectedResponse->statuscode = "200";
    expectedResponse->statusmessage = "OK";
    expectedResponse->type = "text/html";
    expectedResponse->size = sender->SizeOf("/");
    expectedResponse->message = sender->ContentsOf("/");

    return expectedResponse;

}

HttpV1Dot1GetResponse* ContentsOf(std::string path){

    std::string contents; 
    std::ifstream fs;
    std::string file;

    if(path == "/"){
        file = "/html/index.html";
    }
    else if (path == "/about.html"){
        file = "/html/about.html";
    }
    else if(path != "/" && path !="/about.html"){
        std::cout<<"Error in path handling..!!";
    }

    fs.open(file); 
    if(!fs)
	{
		std::cout<<"Error in opening source file..!!";
		getch();
		exit(1);
	}
    
    fs >> contents;
    fs.close();

    return contents;

}

HttpV1Dot1GetResponse* SizeOf(std::string file){

    std::ifstream contents(file, std::ios::binary);
    contents.seekg(0, std::ios::end);
    int size = contents.tellg();
    contents.close();
    return size;

} 