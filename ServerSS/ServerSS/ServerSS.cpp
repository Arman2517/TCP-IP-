#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include "ServerSS.h"
#include <iostream>
#include <thread>
#pragma warning(disable:4996)




ServerS::ServerS(int port) {
	SOCKADDR_IN addr;
	int size = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, 1);

}

void ServerS::send(std::string num)
{
	::send(newConn, num.c_str(), num.size(), 0);
}


void ServerS::run()
{
	newConn = accept(sListen, NULL, NULL);
	std::thread reconnectionThread([&]() {
		char buffer[1024];
		while (true)
		{
			if (recv(newConn, buffer, 1023, NULL) <= 0)
			{
				newConn = accept(sListen, NULL, NULL);
			}
		}
		});
	reconnectionThread.detach();
}