# Assignment Three: PLLKIA010

## Makefile
The purpose of the Makefile is to automatically compile and link the C++ source files into a binary executable that can be run locally. Run these commands in sequence to interact with the program.
```make``` will compile the files into an executable called ```huffencode```

```make run``` will run the executable with the default arguments (```input.txt``` and ```output```)
This will encode the string "Hello World" and write it to a file ```output.txt/output.bin``` for each compression method.
The binary file contains the actual packed bits that map to the input characters.

```make clean``` will delete all object files, bin files, header (.hdr) files, and the executable. 

```make test``` compiles the unit tests into an executable called ```huffencode```
```./test "[all]"``` is the command that will run all of the unit tests. Note that the inverted commas are required. 

This is the format of arugments that can be passed into the program.
```./huffencode <input_file_name.txt> <output_file_name>```

## huffman.h

This is a header file that contains the ```HuffmanNode``` and ```HuffmanTree``` Class declarations. These classes are required to build a Huffman tree after mapping each character to it's frequency in the text. Each class implements the Big 6 special member functions, and additionally includes various accessor methods. The ```HuffmanNode``` class has four member variables, a smart pointer to a left and right node, the frequency count of the node, and it's char value. 

## huffman.cpp

This file is the actual implementation of all the methods declared in the ```huffman.h``` file. It contains the functionality for the special member functions i.e. Constructor, Destructor, Copy Constructor and relevant accessor methods. 

## encoder.h

This id the header file that cpntains the ```Encoder``` class, which encapsulates all the neccasary functions of the Huffman encoder. The class has five member variables, a unordered map for the character bitcodes and frequency counts, a pointer to a Huffman tree, which is used to encode the input text, and two integer variables that hold the size of the input file and encoded/compressed file respectively 

## encoder.cpp
This file is the actual implementation of the methods declared in the ```encoder.h``` file. It contains the primary logic for the encoder, and implements methods that: 1) Read the textfile and calculate the frequency of characters, storing them in a map. 2) Use these frequencies, along with a priority queue of type ```HuffmanNode`` to build a tree consisting of these nodes, according to the encoding algorithm. 3) Calculate the bitcodes for each character by detirmining the location of the relevant node in the tree. 4) Writes the bitcodes to a single buffer and either writes this string to file (pseudo-compression), or performs bit packing and produces a binary file that is compressed to roughly 1/8 the size of the original input. 

## huffencode.h

This file contains the main method, and provides an entry point into the program. All interaction with the program is done via a Command Line Interface, with several supported commands;  users pass in the input and desired output filename. It imports the ```encoder.h``` file in order to provide the Huffman Encoding functionality. The main method has an ```Encoder``` object, and calls all the required methods in order to fully encode a file, including compressing it into binary (not just the pseudo-compressed bitstring). The compression ratio and factor are displayed to the user.

## test.cpp

This file contains all of the defined unit tests, which test each individual method in the process of Huffman encoding i.e. character frequency mapping, tree building, encoding. The Catch framework automatically provides a main method if requested to, and all the unit tests execute seperately from the main program. See above section on how to run these unit tests.

## catch.hpp

Catch is a testing framework for C++. It is header-only, and this file provides the functionality required to create custom unit tests for the program.

