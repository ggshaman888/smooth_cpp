#include <iostream>
#include <ReadArg.h>
#include <ProcessingArray.h>


using namespace std;

int main(int argc, char* argv[])
{

    if (argc!=3){
        cout << "Bad arguments. Enter 2 argument. Path to file and M (number)" << std::endl;
        return 0;
    }

    ReadArg *readA = new  ReadArg(argv[1],argv[2]);
    ProcessingArray *readM = new ProcessingArray(readA);


    return 0;
}
