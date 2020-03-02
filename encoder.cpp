#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "encoder.h"

using namespace std;
using namespace PLLKIA010;

HuffmanNode::HuffmanNode(char ch, int frequency, shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r): left(l), right(r), ch(ch), frequency(frequency){}

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

HuffmanTree::HuffmanTree(shared_ptr<HuffmanNode> root):root(root){}

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

shared_ptr<HuffmanNode> HuffmanTree::getRoot(){
    return root;
}

struct Compare {
    bool operator()(HuffmanNode& a, HuffmanNode& b)
    {
      return a.frequency > b.frequency;
    }
};

bool compare(const HuffmanNode& a, const HuffmanNode& b)
{
    return (&a>&b); // or > if the algorithm requires that ordering
}


bool operator<(const HuffmanNode& a, const HuffmanNode& b){
    if(a.frequency > b.frequency){
        return true;
    }
    return false;
}

void Encoder::generateMap(string input){

    ifstream file(input); 
    char c;

    while (file >> c)
    {   
        std::unordered_map<char,int>::iterator it = map.find(c);
        if(it != map.end()){
            it -> second++;
        }
        else{
            map.insert({c, 1});
        }
    }
}

void HuffmanTree::traversal(std::shared_ptr<HuffmanNode> node)  
{ 
    if (node == nullptr) 
        return; 

    cout << node->frequency << endl; 
    traversal(node->left);  
    traversal(node->right); 
} 

void Encoder::buildTree(){
    
    std::priority_queue<HuffmanNode,vector<HuffmanNode>,Compare> queue;
    for (auto itr = map.begin(); itr != map.end(); ++itr) { 
        std::shared_ptr<HuffmanNode> node = make_shared<HuffmanNode>(itr->first,itr->second, nullptr, nullptr);
        queue.push((*node));
    } 

    while(queue.size() > 1){
        HuffmanNode a = queue.top();
        queue.pop();
        HuffmanNode b = queue.top();
        queue.pop();

        std::shared_ptr<HuffmanNode> n1 = make_shared<HuffmanNode>(a);
        std::shared_ptr<HuffmanNode> n2 = make_shared<HuffmanNode>(b);
        std::shared_ptr<HuffmanNode> parent = make_shared<HuffmanNode>('\0',a.frequency+b.frequency,n1,n2);

        queue.push(*parent);
    }
    std::shared_ptr<HuffmanNode> root = make_shared<HuffmanNode>(queue.top());

    HuffmanTree tree(root);
    tree.traversal(tree.getRoot());
}


