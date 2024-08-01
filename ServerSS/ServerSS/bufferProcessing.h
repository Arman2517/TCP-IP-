#pragma once
#include <iostream>
#include "buffer.h"
#include "ServerSS.h"


class BufferProcessing {
	Sbuffer<std::string>& buffer;
public:
	BufferProcessing(Sbuffer<std::string>& buffer);
	void readFromBuffer(ServerS& server);
private:
	int calculateSum(std::string s);
};