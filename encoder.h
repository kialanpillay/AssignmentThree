#ifndef ENCODER_H
#define ENCODER_H
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
            HuffmanNode(char ch, int frequency);
            HuffmanNode(const HuffmanNode & rhs); //Copy Contructor
            HuffmanNode(HuffmanNode && rhs); //Move Contructor
            HuffmanNode & operator=(const HuffmanNode & rhs);
            HuffmanNode & operator=(HuffmanNode && rhs);
            bool compare(const HuffmanNode& a, const HuffmanNode& b);
            ~HuffmanNode(void);
    };

    class HuffmanTree
    {
        private: 
            std::shared_ptr<HuffmanNode> root;
            std::priority_queue<HuffmanNode> queue;
        
        public: 
            HuffmanTree(void);
            HuffmanTree(const HuffmanTree & rhs); //Copy Contructor
            HuffmanTree(HuffmanTree && rhs); //Move Contructor
            HuffmanTree & operator=(const HuffmanTree & rhs);
            HuffmanTree & operator=(HuffmanTree && rhs);
            ~HuffmanTree(void);
    };

    class Helper
    {
        private:
            std::unordered_map<char, int> map;
            friend class HuffmanTree; 
        public: 
            Helper(void) = default;
            ~Helper(void) = default;
            void countLetters(std::string input);
    };
}

#endif