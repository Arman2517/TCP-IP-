#include "inputCheck.h"
#include "buffer.h"
#include <string>
#include <algorithm>


inputCheck::inputCheck(Sbuffer<std::string>& buffer) :buffer(buffer)
{
}

void inputCheck::start()
{
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (verification(input))
        {
            input = sortAndChange(input);
            buffer.writeB(std::move(input));
        }
        std::cout << input;
    }
}
std::string inputCheck::sortAndChange(std::string s)
{
    std::sort(s.rbegin(), s.rend());
    std::string sKV;
    for (auto ch : s)
    {
        if (ch % 2 == 0)
        {
            sKV += "КВ";
        }
        else
        {
            sKV += ch;
        }
    }
    return sKV;

}
bool inputCheck::verification(const std::string& s)
{
    return  std::all_of(s.begin(), s.end(), ::isdigit) && s.size() < 64 && !s.empty();
}