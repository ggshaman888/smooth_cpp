#ifndef READARG_H
#define READARG_H
#include <string>
#include <cstring>

class ReadArg
{
public:
    ReadArg(std::string, std::string);
    std::string pathFile;
    int smoothM;
};

#endif // READARG_H
