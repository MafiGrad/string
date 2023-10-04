#include "String.h"
#include <iostream>

int main()
{

    std::cout << "Hello \n";
    String str;

    for (int i = 0; i < 10; i++)
    {
        str.push_back(i + 65);
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << str[i] << std::endl;
    }

    return 0;
}