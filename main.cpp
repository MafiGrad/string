#include "String.h"
#include <iostream>

int main()
{
    std::cout << "---Init---\n";
    String str;

    std::cout << "Size " << str.size() << "\nLength " << str.length() << "\nIsEmpty " << str.empty() << std::endl;
    std::cin >> str;
    std::cout << "---After init---\n";
    std::cout << "Size " << str.size() << "\nLength " << str.length() << "\nIsEmpty " << str.empty() << std::endl;

    std::cout << str << std::endl;

    return 0;
}