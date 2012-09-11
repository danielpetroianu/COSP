#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <string>
#include "MPISort.h"
#include "BitonicMergesort.h"
#include "Hyperquicksort.h"

#define BITONIC_MERGE_SORT	"BMS"
#define HYPERQUICK_SORT		"HQS"


using namespace COSP;
using std::cout;
using std::cin;
using std::endl;

MPISort* GetAlgorithm(const std::string& alg, int argc,char *argv[]);

int main(int argc,char *argv[])
{
	std::vector<int> test(10);

	MPISort* sortAlg = nullptr;
	try{

		char* _alg = argv[1];
		if(_alg == nullptr) _alg = BITONIC_MERGE_SORT;
		
		std::string alg(_alg);
		
		sortAlg = GetAlgorithm(alg,argc,argv);
		sortAlg->Sort(test);

	} catch(std::exception& e) {
		std::cout << "EXCEPTION:\t" << e.what() << std::endl;
	}

	if(sortAlg != nullptr)
		delete sortAlg;

	return EXIT_SUCCESS;
}


MPISort* GetAlgorithm(const std::string& alg, int argc,char *argv[]){
	if(alg == BITONIC_MERGE_SORT){
		return new BitonicMergesort(argc,argv);
	}
	if(alg == HYPERQUICK_SORT){
		return new Hyperquicksort(argc,argv);
	}

	return nullptr;
}