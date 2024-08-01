#pragma once
#include <iostream>


class ClientC {
    std::string serverIP_;
    int serverPort_;
    int socket_;
    static const int BUFFER_SIZE = 1024;

public:
    ClientC(const std::string& serverIP, int serverPort);

    void run(void (*handler) (std::string));

private:
    bool connectToServer();

    void receiveData(void (*handler)(std::string));
};
