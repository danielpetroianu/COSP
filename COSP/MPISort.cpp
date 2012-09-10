#include "MPISort.h"
#include <mpi.h>

COSP::MPISort::MPISort(void) {}
COSP::MPISort::~MPISort(void){}

void  COSP::MPISort::SortAlgorithm(std::vector<int>& vect){
	Run(vect);
}