#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <memory>
#include <string>
#include <unordered_map>
#include <queue>

namespace PLLKIA010
{
    class HuffmanNode
    {
        public: 
            std::shared_ptr<HuffmanNode> left, right;
            char ch;
            int frequency;
        
        public: 
            HuffmanNode(char ch, int frequency, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r);
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
            HuffmanTree(std::shared_ptr<HuffmanNode>);
            HuffmanTree(const HuffmanTree & rhs); //Copy Contructor
            HuffmanTree(HuffmanTree && rhs); //Move Contructor
            HuffmanTree & operator=(const HuffmanTree & rhs);
            HuffmanTree & operator=(HuffmanTree && rhs);
            ~HuffmanTree(void);
            std::shared_ptr<HuffmanNode> getRoot(void);
            void traversal(std::shared_ptr<HuffmanNode>);
    };
}

#endif