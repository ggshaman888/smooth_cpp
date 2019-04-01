#include "ProcessingArray.h"
#include <fstream>
#include <iomanip>
#include <cmath>

ProcessingArray::ProcessingArray(ReadArg *args):arguments(args)
{
    summWindow=0;
    readFile();

    if (vectorSmoothSMAFast())
        writeFile();
}

bool ProcessingArray::vectorSmoothSMA() // Simple Movig Average с динамически изменяемым окном
{

    if (arguments->smoothM >= mass.size()){
        std::cout << "2 argument very big! Count elements: " << mass.size() << std::endl;
        return 0;
    }

    std::vector<double> massBuff;

    for (int index=0; index < mass.size();index++){
        massBuff.push_back(arithmeticMean(windowSize(arguments->smoothM, index, mass.size()),index));
    }

    mass.clear();
    massBuff.swap(mass);

    return 1;
}

bool ProcessingArray::vectorSmoothSMAFast()
{

    if (arguments->smoothM >= mass.size()){
        std::cout << "2 argument very big! Count elements: " << mass.size() << std::endl;
        return 0;
    }

    std::vector<double> massBuff;

    for (iterator=0; iterator < mass.size();iterator++){
        massBuff.push_back(arithmeticMeanFast());
    }

    mass.clear();
    massBuff.swap(mass);

    return 1;
}

int ProcessingArray::windowSize(int M, int n, int max)
{
    int flank_max = (M-1)/2;
    int flank = flank_max;
    n++;
    if (flank_max >= n)
        flank = n - 1;
    if ((n-max)*-1 <= flank_max)
        flank = (n - max)*-1;

    if (flank < flank_max)
        return flank*2+1; // window size
    else
        return flank_max*2+1;

}

double ProcessingArray::arithmeticMean(int window, int n)
{
    int flank, i=0, j=0;
    int buff_win = window;
    double summ = mass.at(n);
    flank = (window-1)/2;
    while (--window) {
        summ +=mass.at(n+flank);
        flank--;
    }
    return summ/buff_win;
}

double ProcessingArray::arithmeticMeanFast()
{
    setWindow();
    return summWindow/window_mass.size();
}
void ProcessingArray::addQueueWindow(double element, int window)
{
    while(window_mass.size()>=window)
        window_mass.erase(window_mass.begin());

    window_mass.push_back(element);
}

void ProcessingArray::setWindow()
{
    int windowSize;
    int flank = (arguments->smoothM-1)/2;
    int lengthLeft = iterator;
    int lengthRight = mass.size()-iterator-1;
    int length = lengthLeft < lengthRight ? lengthLeft : lengthRight;

    if(length <= flank)
        windowSize = length*2+1;
    else
        windowSize = flank*2+1;

    window_mass.push_back(mass.at(iterator));
    summWindow += window_mass.at(window_mass.size()-1);

    while(window_mass.size()>windowSize){
        summWindow -= window_mass.at(0);
        window_mass.erase(window_mass.begin());
    }
}

bool ProcessingArray::vectorSmoothMerg()
{
    if (arguments->smoothM >= mass.size()){
        std::cout << "2 argument very big! Count elements: " << mass.size() << std::endl;
        return 0;
    }

    std::vector<double> massBuff;
    for (int index=0; index < mass.size();){
        int summ = 0;
        double count = 0;
        for (int i=0; i < arguments->smoothM; i++) {
            summ += mass[index++];
            count++;
        }
        massBuff.push_back(summ / count);
    }
    mass.clear();
    massBuff.swap(mass);

    return 1;
}



bool ProcessingArray::readFile()
{
    setlocale(LC_ALL, "rus");
    char buff[50];
    std::ifstream fin(arguments->pathFile);

    if (!fin.is_open()){
        std::cout << arguments->pathFile << "File don't open!\n";
        return 0;
    }
    else
    {
        while (!fin.eof()){
            fin.getline(buff,500);
            if(numberTrue(buff))
                mass.push_back(nowNumber);
        }
    fin.close();
    }
    return 1;
}

bool ProcessingArray::writeFile()
{
    setlocale(LC_ALL, "rus");
    std::ofstream fout("data_types.txt", std::ios_base::out | std::ios_base::trunc);

    if (!fout.is_open())
    {
     std::cout << "File don't open\n";
     return 0;
    }
    for (int index=0; index < mass.size(); ++index){
        std::string str = std::to_string(mass[index]);
        fout << str.erase(str.length()-5, 5).append("\n");
    }
    fout.close();
    std::cout << "write to file sucsess\n";
    return 1;
}



bool ProcessingArray::numberTrue(std::string str)
{
    nowNumber = std::atof(str.c_str());

    if (nowNumber != 0)
        return true;
    return false;
}

