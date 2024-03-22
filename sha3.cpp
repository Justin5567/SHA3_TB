#include <stdio.h>
#include <stdint.h>
#include "sha3.h"
#include "compiler.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring> // for memcpy
#include <iomanip> // for std::setw, std::setfill
int main(){

	std::ofstream myWrite("goldenPattern.txt");
	if(!myWrite.is_open()){
		printf("[Error] goldenPattern could not be opened.\n");
		return 0;
	}

	std::ifstream myFile;
	myFile.open("testPattern.txt");
	if(!myFile.is_open()){ //check if myFile could be opened
		printf("[Error] testPattern could not be opened. Please check file exist\n");
		return 0;
	}

	std::string myString;
	while(std::getline(myFile,myString)){
		
		std::cout<<myString<<std::endl;
	
		unsigned char* input = new unsigned char[myString.size()];
		std::memcpy(input,myString.c_str(),myString.size());
		unsigned char output[SHA3_256_DIGEST_SIZE] __aligned(8);
		sha3ONE(input, myString.size(), output);
		for(int i = 0; i < SHA3_256_DIGEST_SIZE; i++){
	      	printf("%02x",output[i]);
		}
		printf("\n");
		std::stringstream hexStream;
        	for (int i = 0; i < SHA3_256_DIGEST_SIZE; ++i) {
         	   hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(output[i]);
        	}
        	std::string hexString = hexStream.str();
		myWrite << input<<std::endl;	
		myWrite << hexString<<std::endl<<std::endl;
	}
	myFile.close();
	myWrite.close();
		
	

	return 0;
}
