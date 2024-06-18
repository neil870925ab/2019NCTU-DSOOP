#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include "main.h"
using namespace std;



int main(int argc, char*argv[]){

	float r=stof(argv[3]);
	ReadBMP(argv[1],argv[2],r);
	
	return 0;
} 
