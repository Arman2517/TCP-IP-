#pragma once
#include <iostream>
#include "buffer.h"


class inputCheck
{
    Sbuffer<std::string>& buffer;

public:
    inputCheck(Sbuffer<std::string>& buffer);
    std::string inStr;

    void start();

    bool verification(const std::string& s);//Проверка, что строка только из цифр и меньше 64 символов


private:

    std::string sortAndChange(std::string s);//Сортировка

};

