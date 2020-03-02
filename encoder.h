#ifndef ENCODER_H
#define ENCODER_H
#include <memory>
#include <string>

namespace PLLKIA010
{
    class HuffmanNode
    {
        private: 
            std::shared_ptr<HuffmanNode> left, right;
            std::string ch;
            int frequency;
        
        public: 
            HuffmanNode(void);
            HuffmanNode(const HuffmanNode & rhs); //Copy Contructor
            HuffmanNode(HuffmanNode && rhs); //Move Contructor
            HuffmanNode & operator=(const HuffmanNode & rhs);
            HuffmanNode & operator=(HuffmanNode && rhs);
            ~HuffmanNode(void);
    };

    class HuffmanTree
    {
        private: 
            std::shared_ptr<HuffmanNode> root;
        
        public: 
            HuffmanTree(void);
            HuffmanTree(const HuffmanTree & rhs); //Copy Contructor
            HuffmanTree(HuffmanTree && rhs); //Move Contructor
            HuffmanTree & operator=(const HuffmanTree & rhs);
            HuffmanTree & operator=(HuffmanTree && rhs);
            ~HuffmanTree(void);
    };
}

#endif