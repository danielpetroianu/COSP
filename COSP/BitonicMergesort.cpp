#include "BitonicMergesort.h"
#include <mpi.h>
#include <iostream>

COSP::BitonicMergesort::BitonicMergesort(){ }
COSP::BitonicMergesort::BitonicMergesort(int& argc, char**& argv){ 
	Init(argc, argv);
}
COSP::BitonicMergesort::~BitonicMergesort(void){ }

void COSP::BitonicMergesort::Run(std::vector<int>& numbers)
{
	if(numbers.empty()) return;
	
	std::cout << "BMS - Run #" << GetPID() << " vector size: " << numbers.size() << std::endl;


    
}