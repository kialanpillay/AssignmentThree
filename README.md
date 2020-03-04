# Assignment Three: PLLKIA010

## Makefile
The purpose of the Makefile is to automatically compile and link the C++ source files into a binary executable that can be run locally. Run these commands in sequence to interact with the program.
```make``` will compile the files into an executable called ```volimage```

```make run``` will run the executable with the default arguments (with "MRI" as the image base)

```make clean``` will delete all object files, raw files, header (.data) files, and the executable. 

This is the format of arugments that can be passed into the program.
```./volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]```
Note that operations are mutually exlusive. Furthermore, the ```<imageBase>``` arugment must include the name of the folder that the raw files are located in i.e. ```folder/base``` 

Example Commands
```./volimage brain_mri_raws/MRI -d 0 10 output```
```./volimage brain_mri_raws/MRI -x 10 output```
```./volimage brain_mri_raws/MRI -g 10 output```


## vol_image.h

This is a header file that contains the ```VolImage``` Class declaration, which consists of three private member variables: a ```vector<unsigned char **>``` to store the image slices and two ints for the dimension of a slice. and six public methods declarations for the main functionality of the program, as well as a Contructor and Destructor to initialise and release memory resources. 

## vol_image.cpp

This file is the actual implementation of the method definitions declared in the ```vol_image.h``` file. It contains the logic for the program, and implements various methods that correspond to program functions: reading in binary data into the Vector, in essence creating a 3D representation of the data which can be manipulated, extracting a slice in the stack and writing the data to file, computing the difference between two image slices in the stack, and extracting a particular row across all slices, and writing this to file (extra-credit, and essentially a top-down scan view). THere are also methods to return the number of images in the stack, and the total memory allocation required to store it.

## driver.cpp

This file contains the main method, and provides an entry point into the program. All interaction with the program is done via a Command Line Interface, with several supported commands;  users passing in various required and optional arguments, depending on the desired action. It imports the vol_image.h file in order to provide program functionality. 

