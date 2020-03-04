#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "encoder.h"
#include "huffman.h"

using namespace PLLKIA010;

Encoder::~Encoder(){
    delete tree;
}

struct Compare {
    bool operator()(const HuffmanNode& a, const HuffmanNode& b)
    {
      return a.frequency > b.frequency;
    }
};

bool compare(const HuffmanNode& a, const HuffmanNode& b)
{
    //return (a>b);
    return true;
}


bool operator>(const HuffmanNode& a, const HuffmanNode& b){
    if(a.frequency > b.frequency){
        return true;
    }
    return false;
}

int Encoder::getBitSize(){
    return bitSize;
}

int Encoder::getInputSize(){
    return inputSize;
}

HuffmanTree* Encoder::getTree(){
    return tree;
}

void Encoder::generateMap(std::string input){

    std::ifstream file(input); 
    file.unsetf(std::ios_base::skipws);
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
    if(map.size()==0){
        std::cout << "No text supplied!" << std::endl;
        exit(1);
    }
    inputSize = sizeof(file);
    file.close();
}

void Encoder::treeTraversal(std::shared_ptr<HuffmanNode> node, std::string bitstring)  
{ 
    if (node == nullptr){

        return; 
    }
    if(node->ch != '\0'){
        std::unordered_map<char,std::string>::iterator it = codes.find(node->ch);
        if(it != codes.end()){
            it->second = bitstring;
        }
        else{
            codes.insert({node->ch, bitstring});
        }

    }
    treeTraversal(node->left, bitstring + "0");  
    treeTraversal(node->right, bitstring + "1"); 
    
} 

void Encoder::buildTree(){
    std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Compare> queue;
    for (auto itr = map.begin(); itr != map.end(); ++itr) { 
        HuffmanNode n(itr->first,itr->second, nullptr, nullptr);
        queue.push(n);
    }

    while(queue.size() > 1){
        HuffmanNode a = queue.top();
        queue.pop();
        HuffmanNode b = queue.top();
        queue.pop();

        std::shared_ptr<HuffmanNode> n1 = std::make_shared<HuffmanNode>(a);
        std::shared_ptr<HuffmanNode> n2 = std::make_shared<HuffmanNode>(b);
        std::shared_ptr<HuffmanNode> parent = std::make_shared<HuffmanNode>('\0',a.frequency+b.frequency,n1,n2);

        queue.push(*parent);
    }
    std::shared_ptr<HuffmanNode> root = std::make_shared<HuffmanNode>(queue.top());
    tree = new HuffmanTree(root);
}

void Encoder::generateCodes(){
    treeTraversal(tree->getRoot(),"");
}

void Encoder::compress(std::string input, std::string output){
    std::ifstream in(input); 
    std::string buffer;
    char c;

    while (in >> c)
    {   
        std::unordered_map<char,std::string>::iterator it = codes.find(c);
        buffer+=it->second;
    }
    in.close();

    std::ofstream header(output+".hdr");
    header << "Field Count: " << codes.size() << "\n";
    for (auto itr = codes.begin(); itr != codes.end(); ++itr) { 
        header << itr->first 
             << '\t' << itr->second << '\n'; 
    }
    header.close();

    char* cstr = new char [buffer.length()+1];
    std::strcpy (cstr, buffer.c_str());
    std::ofstream out(output+".txt");
    out << cstr;
    bitSize = sizeof(out);
    out.close();
    delete [] cstr;
}

void Encoder::binaryCompress(std::string input, std::string output){
    std::ifstream in(input); 
    std::string buffer;
    char c;

    while (in >> c)
    {   
        std::unordered_map<char,std::string>::iterator it = codes.find(c);
        buffer+=it->second;
    }
    in.close();

    std::ofstream out(output+".bin",std::ios::binary);
    unsigned char byte = 0;
    int i = 0;
    std::string str = "";
    if (i + 8 < buffer.length())
        str = buffer.substr(i, i + 8);
    else
        str = buffer.substr(i, buffer.length());
    for (unsigned b = 0; b != 8; ++b)
    {
        if (b < str.length())
            byte |= (str[b] & 1) << b; 
        else
            byte |= 1 << b;
    }
    out << byte;
    bitSize = (sizeof(out)/8) + (sizeof(out)%8 ? 1 : 0);
    out.close();
}

std::unordered_map<char, int> Encoder::getMap(){
    return map;
}

std::unordered_map<char, std::string> Encoder::getCodes(){
    return codes;
}

void Encoder::extract(std::string input, std::string output){
    int i = 0,j=0,k=0;
    std::bitset<8> setByte;
    std::ifstream in(input+".bin", std::ios::binary);
    std::ofstream out("a.txt");
    std::string concat = "";
    std::string bitStr = "";
    std::string reverse = "";
    int charCount = 0;
    for (i = 0; i < 20; i++)
    {
        setByte = in.get();
        bitStr = setByte.to_string();
        reverse = "";
        for (k = 7; k>=0; k--)
            reverse += bitStr[k];
        for (j = 0; j < 8; j++)
        {   
            in.seekg (i*20);
            //in.read ((char*)setByte, 20);
            concat += reverse[j];
            char c[concat.size() + 1];
            concat.copy(c, concat.size() + 1);
            if (map[*c])
            {   

                out << map[*c];
                charCount++;
                concat = "";
                if (charCount == 20) // if we have written original amount stop
                {
                    out.close();
                }

            }
        }
    }
    out.close();

}