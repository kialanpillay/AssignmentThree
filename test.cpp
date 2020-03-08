#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "encoder.h"

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
	REQUIRE(e.getCodes()['e']=="1111");
	REQUIRE(e.getCodes()['r']=="1110");
	REQUIRE(e.getCodes()['l']=="10");
	REQUIRE(e.getCodes()['W']=="001");
	REQUIRE(e.getCodes()[' ']=="011");
	REQUIRE(e.getCodes()['H']=="010");
	REQUIRE(e.getCodes()['o']=="110");
	REQUIRE(e.getCodes()['d']=="000");
}

TEST_CASE("Input Size Test","[all]") {
	std::cout << "Input Size Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.compress("test.txt","output");
	REQUIRE(e.getInputSize() == 576);
}

TEST_CASE("Output Size Test","[all]") {
	std::cout << "Compressed Output Size Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.compress("test.txt","output");
	REQUIRE(e.getBitSize() == 568);
}


TEST_CASE("Compression Test","[all]") {
	std::cout << "Compression Test" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.compress("test.txt","output");
	REQUIRE((int)((double)e.getInputSize()/(double)e.getBitSize()) == 1);
}

TEST_CASE("Binary Compression Test","[all]") {
	std::cout << "Binary Compression Test (Bit Packing)" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.binaryCompress("test.txt","output");
	REQUIRE((int)((double)e.getInputSize()/(double)e.getBitSize()) == 8);
	REQUIRE((int)(1/((double)e.getInputSize()/(double)e.getBitSize()) * 100) == 12);
}

TEST_CASE("Binary Extraction Test","[all]") {
	std::cout << "Binary Extraction Test (Bit Unpacking)" << std::endl;
	PLLKIA010::Encoder e;
	e.generateMap("test.txt");
	e.buildTree();
	e.generateCodes();
	e.binaryCompress("test.txt","output");
	e.extract("output","extracted_test.txt");

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