#ifndef ENCODER_H
#define ENCODER_H
#include <memory>
#include <string>
#include <unordered_map>
#include <queue>
#include "huffman.h"

namespace PLLKIA010
{
    class Encoder
    {
        private:
            std::unordered_map<char, int> map;
            std::unordered_map<char,std::string> codes;
            HuffmanTree *tree;
            int inputSize, bitSize;
        public: 
            Encoder(void) = default;
            ~Encoder(void);
            void generateMap(std::string input);
            void buildTree(void); 
            void generateCodes(void);
            void treeTraversal(const std::shared_ptr<HuffmanNode>, std::string bitstring);
            void compress(const std::string input, const std::string output);
            void binaryCompress(const std::string input, const std::string output);
            void extract(const std::string input, const std::string output);
            int getBitSize(void);
            int getInputSize(void);
            HuffmanTree* getTree(void);
            std::unordered_map<char, int> getMap(void);
            std::unordered_map<char, std::string> getCodes(void);
    };
}

#endif