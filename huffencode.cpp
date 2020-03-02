#include <iostream>
#include "encoder.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3){
        cout << "Incorrect number of arguments!" << endl;
        exit(1);
    }

    PLLKIA010::Encoder e;
    e.generateMap(argv[1]);
    e.buildTree();
    return 0;
}
