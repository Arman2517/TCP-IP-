#include <iostream>

#include "ClientCC.h"
#include "receivehandler.h"


#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#pragma warning(disable:4996)



int main() {
	WSADATA data;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &data) != 0) {
		std::cout << "ERROR library" << std::endl;
		exit(1);
	}
	ClientC client("127.0.0.1", 1111);
	client.run(&ReceiveHandler::handle);
	return 0;
}
