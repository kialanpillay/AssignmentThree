#ifndef ENCODER_H
#define ENCODER_H
#include <memory>
#include <string>
#include <unordered_map>
#include <queue>

namespace PLLKIA010
{
    class Encoder
    {
        private:
            std::unordered_map<char, int> map;
            friend class HuffmanTree; 
            friend class HuffmanNode; 

        public: 
            Encoder(void) = default;
            ~Encoder(void) = default;
            void generateMap(std::string input);
            void buildTree(void);  
    };
}

#endif