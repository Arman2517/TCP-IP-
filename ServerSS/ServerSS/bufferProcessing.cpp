#include "buffer.h"
#include "bufferProcessing.h"
#include <string>
#include <algorithm>
#include <numeric>



BufferProcessing::BufferProcessing(Sbuffer<std::string>& buffer) :buffer(buffer)
{}

void BufferProcessing::readFromBuffer(ServerS& server)
{
	while (true) {
		std::string data = buffer.readB();
		std::cout << data << std::endl;
		int sum = calculateSum(std::move(data));
		server.send(std::move(std::to_string(sum)));
	}
}

int BufferProcessing::calculateSum(std::string s)
{
	int sum = 0;
	for (auto ch : s)
	{
		char zn = ch - '0';
		if (zn<10 && zn>-1) sum += (::isdigit(ch) ? ch - '0' : 0);

	}
	return sum;
}