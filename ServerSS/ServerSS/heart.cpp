#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include "ServerSS.h"
#include "inputCheck.h"
#include "bufferProcessing.h"
#include "buffer.h"
#include <iostream>
#include <thread>
#pragma warning(disable:4996)

int main(int argc, char* argv[]) {

	WSADATA data;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &data) != 0) {
		std::cout << "ERROR library" << std::endl;
		exit(1);
	}
	ServerS server(1111);
	server.run();

	Sbuffer<std::string> buffer;

	inputCheck Check(buffer);
	BufferProcessing bp(buffer);

	std::thread inputThread(&inputCheck::start, Check);
	std::thread processingThread(&BufferProcessing::readFromBuffer, bp, std::ref(server));


	inputThread.join();
	processingThread.join();

	system("pause");

}



