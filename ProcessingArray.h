#ifndef READMASS_H
#define READMASS_H
#include <string>
#include <cstring>
#include <ReadArg.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

class ProcessingArray
{
public:
    ProcessingArray(ReadArg *);

private:
    std::vector<double> mass;

    double nowNumber;
    std::vector<double> window_mass;
    ReadArg *arguments;
    int iterator;
    double summWindow;
    void setWindow();
    double arithmeticMeanFast ();
    bool vectorSmoothSMAFast();
    bool readFile();
    bool numberTrue(std::string);
    bool writeFile();

//    bool vectorSmoothMerg();
//    bool vectorSmoothSMA();
//    double arithmeticMean (int, int);

//    int windowSize(int, int, int);
//    void addQueueWindow(double, int);
};

#endif // READMASS_H
