#pragma once
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

#pragma warning(disable:4996)

#include <WinSock2.h>



class ServerS
{
    SOCKET newConn;
    SOCKET sListen;

public:
    ServerS(int port);

    void send(std::string num);

    void run();
};

