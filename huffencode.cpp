#include <iostream>
#include "encoder.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3){
        cout << "Incorrect number of arguments!" << endl;
        exit(1);
    }
    cout << "Huffman Encoder" << std::endl;
    cout << "================================================" << std::endl;
    PLLKIA010::Encoder e;
    e.generateMap(argv[1]);
    e.buildTree();
    e.generateCodes();
    e.compress(argv[1], argv[2]);
    double factor = (double)e.getInputSize()/(double)e.getBitSize();
    double percentage = 1/factor;
    cout << "================================================" << std::endl;
    cout << "Pseudo Compression" << std::endl;
    cout << "Compression Factor (Original Size):     " << factor << "x " << std::endl;
    cout << "Compression Percentage (Original Size): " << percentage * 100 << "%" << std::endl;
    e.binaryCompress(argv[1], argv[2]); //Extra Credit - Binary Compression
    factor = (double)e.getInputSize()/(double)e.getBitSize();
    percentage = 1/factor;
    cout << "================================================" << std::endl;
    cout << "Binary Compression (Extra Credit)" << std::endl;
    cout << "Compression Factor (Original Size):     " << factor << "x " << std::endl;
    cout << "Compression Percentage (Original Size): " << percentage * 100 << "%" << std::endl;
    cout << "Text sucessfully compressed!" << std::endl;
    e.extract(argv[2], argv[1]);
    return 0;
}
