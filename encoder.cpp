#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "encoder.h"
#include "huffman.h"

using namespace std;
using namespace PLLKIA010;

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
        //std::shared_ptr<HuffmanNode> node = make_shared<HuffmanNode>(itr->first,itr->second, nullptr, nullptr);
        HuffmanNode n(itr->first,itr->second, nullptr, nullptr);
        queue.push(n);
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


