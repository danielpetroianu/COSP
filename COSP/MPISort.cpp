#include "MPISort.h"
#include <mpi.h>
#include <iostream>

COSP::MPISort::MPISort(void) {}
COSP::MPISort::~MPISort(void){}

void  COSP::MPISort::SortAlgorithm(std::vector<int>& vect){
	double start = MPI::Wtime();
	
	Run(vect);

	double end = MPI::Wtime();

	std::cout << "node: #" << PID() << " finished sorting in: " << (end-start) <<"sec" <<std::endl;
}