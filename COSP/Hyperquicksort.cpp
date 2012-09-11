#include "Hyperquicksort.h"
#include <iostream>
COSP::Hyperquicksort::Hyperquicksort(){}
COSP::Hyperquicksort::Hyperquicksort(int& argc, char**& argv) { Init(argc,argv); }
COSP::Hyperquicksort::~Hyperquicksort(void){}

void COSP::Hyperquicksort::RunMaster(std::vector<int>& vnr){
	std::cout << "HQS - M - Run #" << GetPID() << std::endl;
}
void COSP::Hyperquicksort::RunSlave(std::vector<int>& vnr){
	std::cout << "HQS - S - Run #" << GetPID() << std::endl; 
}