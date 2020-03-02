CC=g++         
CCFLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer

volimage: driver.o vol_image.o
	$(CC) $(CCFLAGS) driver.o vol_image.o -o volimage

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

vol_image.o: vol_image.cpp vol_image.h
	$(CC) $(CCFLAGS) -c vol_image.cpp
  
clean:
	@rm -f *.o && rm -f volimage
	@rm -f *.raw && rm -f *.data
   
run:
	@./volimage brain_mri_raws/MRI

