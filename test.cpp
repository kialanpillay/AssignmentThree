#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "encoder.h"
#include <fstream>



TEST_CASE("Map Generation","[all]") {
	std::cout << "Frequency Map Generation Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	REQUIRE(e.getMap()['H']==1);
	REQUIRE(e.getMap()['e']==1);
	REQUIRE(e.getMap()['l']==3);
	REQUIRE(e.getMap()['o']==2);
	REQUIRE(e.getMap()['W']==1);
	REQUIRE(e.getMap()['r']==1);
	REQUIRE(e.getMap()['d']==1);
}

TEST_CASE("Build Tree","[all]") {
	std::cout << "Huffman Tree Build Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	REQUIRE(e.getTree()->getRoot()->frequency == 11);
}

TEST_CASE("Generate Codes","[all]") {
	std::cout << "Generate Codes Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	REQUIRE(e.getCodes()['l']=="10");
}

TEST_CASE("Input Size Test","[all]") {
	std::cout << "Input Size Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.compress("test.txt","test_output");
	std::ifstream i("test.txt");
	REQUIRE(e.getInputSize() == sizeof(i));
}


TEST_CASE("Compression Test","[all]") {
	std::cout << "Compression Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.compress("test.txt","test_output");
	REQUIRE((int)((double)e.getInputSize()/(double)e.getBitSize()) == 1);
}

TEST_CASE("Binary Compression Test","[all]") {
	std::cout << "Binary Compression Test (Bit Packing)" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.binaryCompress("test.txt","test_output");
	REQUIRE((int)((double)e.getInputSize()/(double)e.getBitSize()) == 8);
	REQUIRE((int)(1/((double)e.getInputSize()/(double)e.getBitSize()) * 100) == 12);
}

TEST_CASE("Binary Extraction Test","[all]") {
	std::cout << "Binary Extraction Test (Bit Unpacking)" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.binaryCompress("test.txt","test_output");
	e.extract("test_output","extracted_test.txt");

	std::ifstream in("test.txt"); 
    in >> std::noskipws; 
    std::string input;
	char c;
    while (in >> c)
    {   
        input+=c;
    }

	std::ifstream extract("extracted_test.txt"); 
    extract >> std::noskipws; 
    std::string output;
    while (extract >> c)
    {   
        output+=c;
    }
	REQUIRE(input == output);
}

TEST_CASE("Huffman Node Copy Constructor","[all]") {
	std::cout << "Huffman Node Copy Constructor" << std::endl;
	PLLKIA010::HuffmanNode n1('a', 1, nullptr, nullptr);
	PLLKIA010::HuffmanNode n2 = n1;
	REQUIRE(n1.frequency == 1);
	REQUIRE(n2.frequency == 1);
}


TEST_CASE("Huffman Node Move Constructor","[all]") {
	std::cout << "Huffman Node Move Constructor" << std::endl;
	PLLKIA010::HuffmanNode n1('a', 1, nullptr, nullptr);
	PLLKIA010::HuffmanNode n2 = std::move(n1);
	REQUIRE(n2.frequency == 1);
	REQUIRE(n1.frequency == -1);
}


TEST_CASE("Huffman Node Copy Assignment Operator","[all]") {
	std::cout << "Huffman Node Copy Assignment Operator" << std::endl;
	PLLKIA010::HuffmanNode n1('a', 1, nullptr, nullptr);
	PLLKIA010::HuffmanNode n2('b', 1, nullptr, nullptr);
	n2 = n1;
	REQUIRE(n1.frequency == 1);
	REQUIRE(n2.frequency == 1);
}


TEST_CASE("Huffman Node Move Assignment Operator","[all]") {
	std::cout << "Huffman Node Move Assignment Operator" << std::endl;
	PLLKIA010::HuffmanNode n1('a', 1, nullptr, nullptr);
	PLLKIA010::HuffmanNode n2('b', 2, nullptr, nullptr);
	REQUIRE(n2.frequency == 2);
	n2 = std::move(n1);
	REQUIRE(n2.frequency == 1);
	REQUIRE(n1.frequency == -1);
}