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

    bool vectorSmoothMerg();
    bool vectorSmoothSMA();
    bool readFile();
    bool writeFile();
    double arithmeticMean (int, int);
    bool numberTrue(std::string);
    ReadArg *arguments;

    double nowNumber;
    int windowSize(int, int, int);
    std::vector<double> window_mass;
    void addQueueWindow(double, int);

    int iterator;
    double summWindow;
    void setWindow();
    double arithmeticMeanFast ();
    bool vectorSmoothSMAFast();

};

#endif // READMASS_H
