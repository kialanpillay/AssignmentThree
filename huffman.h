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
        private: 
            std::shared_ptr<HuffmanNode> left, right;
            char ch;
        
        public: 
            int frequency;
            HuffmanNode(const char ch, const int frequency, const std::shared_ptr<HuffmanNode> l, const std::shared_ptr<HuffmanNode> r);
            HuffmanNode(const HuffmanNode & rhs); //Copy Contructor
            HuffmanNode(HuffmanNode && rhs); //Move Contructor
            HuffmanNode & operator=(const HuffmanNode & rhs);
            HuffmanNode & operator=(HuffmanNode && rhs);
            ~HuffmanNode(void);
            friend class Encoder;
            friend class HuffmanTree;
    };

    class HuffmanTree
    {
        private: 
            std::shared_ptr<HuffmanNode> root;
        
        public: 
            friend class Encoder;
            HuffmanTree();
            HuffmanTree(const std::shared_ptr<HuffmanNode>);
            HuffmanTree(const HuffmanTree & rhs); //Copy Contructor
            HuffmanTree(HuffmanTree && rhs); //Move Contructor
            HuffmanTree & operator=(const HuffmanTree & rhs);
            HuffmanTree & operator=(HuffmanTree && rhs);
            ~HuffmanTree(void);
            std::shared_ptr<HuffmanNode> getRoot(void);
    };
}

#endif