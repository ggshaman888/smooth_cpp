#include "ReadArg.h"
#include <string>
#include <cstring>
#include <iostream>
#include <locale>

ReadArg::ReadArg(std::string p, std::string m)
{
    pathFile = p;
    smoothM = std::atoi(m.c_str());

    if (smoothM==0){
        std::cout << "Bad 2 argument. Оnly odd " << m.c_str() << std::endl;
        exit(0);
    }
    if (smoothM % 2 == 0){
        std::cout << "Bad 2 argument. Оnly odd " << m.c_str() << std::endl;
        exit(0);
    }
    std::cout << "Path to file: ./" << pathFile << std::endl;
    std::cout << "Smooth: " << smoothM << std::endl;
}
