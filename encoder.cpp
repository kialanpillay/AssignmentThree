#include <iostream>
#include <vector>
#include "encoder.h"

using namespace std;
using namespace PLLKIA010;

HuffmanNode::HuffmanNode(): left(nullptr), right(nullptr), ch(""), frequency(-1){}

HuffmanNode::~HuffmanNode(){
    if(frequency!=-1){
        left = nullptr;
        right = nullptr;
        ch = "";
        frequency = -1;
    }
}

HuffmanNode::HuffmanNode(const HuffmanNode::HuffmanNode & rhs): left(rhs.left), right(rhs.right), ch(rhs.ch), frequency(rhs.frequency){}
    
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

HuffmanTree::HuffmanTree():root(nullptr){}

HuffmanTree::~HuffmanTree(){
    root = nullptr;
}

HuffmanTree::HuffmanTree(const HuffmanTree::HuffmanTree & rhs): root(rhs.root){}
    
HuffmanTree::HuffmanTree(HuffmanTree::HuffmanTree && rhs): root(std::move(rhs.root)){}

HuffmanTree::HuffmanTree & HuffmanTree::operator=(const HuffmanTree & rhs){
    if(this != &rhs) { 
        root = rhs.root;
    }
    return *this;
}

HuffmanTree::HuffmanTree & HuffmanTree::operator=(HuffmanTree && rhs){
    if(this != &rhs) { 
        root = rhs.root;
    }
    return *this;
}
