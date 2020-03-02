#include <iostream>
#include "encoder.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3){
        cout << "Incorrect number of arguments!" << endl;
        exit(1);
    }

    PLLKIA010::Helper h;
    h.countLetters(argv[1]);
    return 0;
}
