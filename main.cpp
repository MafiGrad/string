#include "String.h"
#include <iostream>

int main()
{
    /*
    std::cout << "---Init---\n";
    String str;

    std::cout << "Size " << str.size() << "\nLength " << str.length() << "\nIsEmpty " << str.empty() << std::endl;
    std::cin >> str;
    std::cout << "---After init---\n";
    std::cout << "Size " << str.size() << "\nLength " << str.length() << "\nIsEmpty " << str.empty() << std::endl;

    std::cout << str << std::endl;
*/

    String str1, str2;

    std::cin >> str1;
    std::cin >> str2;

    std::cout << (str1 < str2) << std::endl;
    return 0;
}