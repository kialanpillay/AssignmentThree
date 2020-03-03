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
    e.generateCodes();
    e.compress(argv[1], argv[2]);
    e.binaryCompress(argv[1], argv[2]);
    double factor = (double)e.getInputSize()/(double)e.getBitSize();
    double percentage = 1/factor;
    cout << "Compression Factor: " << factor << "x " << std::endl;
    cout << "Compression Percentage: " << percentage * 100 << "% of original size." << std::endl;
    return 0;
}
