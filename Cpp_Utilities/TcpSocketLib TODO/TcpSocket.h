#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

class Server
{
private:
    int myPort;
    int mySocket;
    int myInitSocket;
    bool myIsConnected;
    
public:
    Server() : myPort(2048), mySocket(0), myIsConnected(false)
    {}
    Server(int port) : myPort(port), mySocket(0), myIsConnected(false)
    {}

    int Connect()
    {
        int success = EXIT_SUCCESS;
        
        // Create a socket
        myInitSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (myInitSocket < 0) 
        {
            success = EXIT_FAILURE;
            printf("ERROR opening socket\n");
        }

        struct sockaddr_in myServ_addr, myCli_addr;

        // Zero out the serer address bytes from struct
        bzero((char *) &myServ_addr, sizeof(myServ_addr));

        myServ_addr.sin_family = AF_INET;
        myServ_addr.sin_addr.s_addr = INADDR_ANY;
        myServ_addr.sin_port = htons(myPort);
        if (bind(myInitSocket, (struct sockaddr *) &myServ_addr, sizeof(myServ_addr)) < 0) 
        {
            success = EXIT_FAILURE;
            printf("ERROR on binding\n");
        }

        // listen for Server
        listen(myInitSocket,5);

        // get Client length
        socklen_t clilen = sizeof(myCli_addr);

        // Get ID of new socket to exchange data
        mySocket = accept(myInitSocket, 
                    (struct sockaddr *) &myCli_addr, 
                    &clilen);

        if (mySocket < 0) 
        {
            success = EXIT_FAILURE;
            printf("ERROR on accept\n");
        }

        return success;
    }

    void Disconnect()
    {
        if (myIsConnected == true)
        {
            close(mySocket);
            close(myInitSocket);
        }
    }
};

class Client
{
private:
    int myPort;
    int mySocket;
    struct sockaddr_in myServ_addr;

    bool myIsConnected;

public:
    Client() : myPort(2048), mySocket(0), myIsConnected(false)
    {}

    Client(int port) : myPort(port), mySocket(0), myIsConnected(false)
    {}

    int Connect()
    {
        int success = EXIT_SUCCESS;
        myIsConnected = false;
        struct hostent *server;

        mySocket = socket(AF_INET, SOCK_STREAM, 0);
        if (mySocket < 0) 
        {
            printf("ERROR opening socket\n");
            success = EXIT_FAILURE;
        }
        //server = gethostbyname("localhost");
        if (server == NULL) 
        {
            printf("ERROR, no such host\n");
            success = EXIT_FAILURE;
        }

        // zero out memory of the server address
        bzero((char *) &myServ_addr, sizeof(myServ_addr));
        myServ_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, 
            (char *)&myServ_addr.sin_addr.s_addr,
            server->h_length);

        myServ_addr.sin_port = htons(myPort);
        if (connect(mySocket,(struct sockaddr *) &myServ_addr,sizeof(myServ_addr)) < 0) 
        {
            printf("ERROR connecting\n");
            success = EXIT_FAILURE;
        }

        myIsConnected = true;
        return success;
    }

    void Disconnect()
    {
        if (myIsConnected == true)
        {
            close(mySocket);
        }
    }

    int Send(char* data, const size_t & dataLength)
    {
        int success = EXIT_SUCCESS;

        int numberOfBytes = write(mySocket, data, dataLength);
        if (numberOfBytes < 0) 
        {
            printf("ERROR writing to socket\n");
            success = EXIT_FAILURE;
        }

        return success;
    }
};