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
  
clean:
	@rm -f *.o && rm -f huffencode
   
run:
	@./huffencode input.txt output.txt

