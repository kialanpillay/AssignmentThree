#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "huffman.h"

using namespace PLLKIA010;

HuffmanNode::HuffmanNode(char ch, int frequency, std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r): left(l), right(r), ch(ch), frequency(frequency){}

HuffmanNode::~HuffmanNode(){
    if(frequency!=-1){
        left = nullptr;
        right = nullptr;
        ch = '\0';
        frequency = -1;
    }
}

HuffmanNode::HuffmanNode(const HuffmanNode & rhs): left(rhs.left), right(rhs.right), ch(rhs.ch), frequency(rhs.frequency){}
    
HuffmanNode::HuffmanNode(HuffmanNode && rhs): left(std::move(rhs.left)), right(std::move(rhs.right)), ch(std::move(rhs.ch)), frequency(rhs.frequency) {
    rhs.frequency = -1;
}

HuffmanNode & HuffmanNode::operator=(const HuffmanNode & rhs){
    if(this != &rhs) { 
        frequency = rhs.frequency; 
        ch = rhs.ch;
        left = rhs.left;
        right = rhs.right;
    }
    return *this;
}

HuffmanNode & HuffmanNode::operator=(HuffmanNode && rhs){
    if(this != &rhs) { 
        frequency = rhs.frequency; 
        ch = std::move(rhs.ch);
        left = rhs.left;
        right = rhs.right;
    }
    return *this;
}


HuffmanTree::HuffmanTree(std::shared_ptr<HuffmanNode> root):root(root){}

HuffmanTree::HuffmanTree():root(nullptr){}

HuffmanTree::~HuffmanTree(){
    root = nullptr;
}

HuffmanTree::HuffmanTree(const HuffmanTree & rhs): root(rhs.root){}
    
HuffmanTree::HuffmanTree(HuffmanTree && rhs): root(std::move(rhs.root)){}

HuffmanTree & HuffmanTree::operator=(const HuffmanTree & rhs){
    if(this != &rhs) { 
        root = rhs.root;
    }
    return *this;
}

HuffmanTree & HuffmanTree::operator=(HuffmanTree && rhs){
    if(this != &rhs) { 
        root = rhs.root;
    }
    return *this;
}

std::shared_ptr<HuffmanNode> HuffmanTree::getRoot(){
    return root;
}



