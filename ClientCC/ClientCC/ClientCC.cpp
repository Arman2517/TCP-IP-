
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)
#include <Windows.h>
#include "ClientCC.h"
#include <WS2tcpip.h>



ClientC::ClientC(const std::string& serverIP, int serverPort)
	: serverIP_(serverIP), serverPort_(serverPort) {}


void ClientC::run(void (*handler)(std::string)) {
	while (true) {
		if (!connectToServer()) {
			Sleep(1000);
			continue;
		}
		receiveData(handler);
		//close(socket_);
	}
}


bool ClientC::connectToServer() {
	socket_ = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_ < 0) {
		std::cout << "Ошибка при создании сокета." << std::endl;
		return false;
	}

	sockaddr_in serverAddress{};
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(serverPort_);

	if (inet_pton(AF_INET, serverIP_.c_str(), &(serverAddress.sin_addr)) <= 0) {
		std::cout << "Ошибка в адресе сервера." << std::endl;
		//close(socket_);
		return false;
	}

	if (connect(socket_, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) < 0) {
		//close(socket_);
		return false;
	}
	return true;
}


void ClientC::receiveData(void (*handler)(std::string)) {
	char buffer[BUFFER_SIZE];
	while (true) {
		memset(buffer, 0, BUFFER_SIZE);
		if (recv(socket_, buffer, BUFFER_SIZE - 1, NULL) <= 0) {
			break;
		}
		std::string data(buffer);
		handler(std::move(data));
	}
}
