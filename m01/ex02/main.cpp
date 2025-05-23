
#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    //print addresses
    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    //print values (string)
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    return 0;
}
