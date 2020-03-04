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