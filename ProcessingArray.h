#ifndef READMASS_H
#define READMASS_H
#include <string>
#include <cstring>
#include <ReadArg.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

class ProcessingArray
{
public:
    ProcessingArray(ReadArg *);

private:
    std::vector<double> mass;

    bool vectorSmoothMerg();
    bool vectorSmoothSMA();
    bool readFile();
    bool writeFile();
    int windowSize(int, int, int);
    double arithmeticMean (int, int);
    bool numberTrue(std::string);
    double nowNumber;
    ReadArg *arguments;
};

#endif // READMASS_H
