CC=g++         
CCFLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer


huffencode: huffencode.o encoder.o huffman.o
	$(CC) $(CCFLAGS) huffencode.o encoder.o huffman.o -o huffencode

huffencode.o: huffencode.cpp
	$(CC) $(CCFLAGS) -c huffencode.cpp	

encoder.o: encoder.cpp encoder.h
	$(CC) $(CCFLAGS) -c encoder.cpp

huffman.o: huffman.cpp huffman.h
	$(CC) $(CCFLAGS) -c huffman.cpp

test: test.o encoder.o huffman.o
	$(CC) $(CCFLAGS) test.o encoder.o huffman.o -o test

test.o: test.cpp
	$(CC) $(CCFLAGS) -c test.cpp

clean:
	@rm -f *.o && rm -f huffencode && rm -f test && rm -f *.bin
	@rm -f output.txt && rm -f *.hdr && rm -f extracted_test.txt && rm -f extracted.txt
   
run:
	@./huffencode input.txt output

