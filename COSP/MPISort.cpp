#include "MPISort.h"
#include <mpi.h>

namespace COSP
{
	MPISort::MPISort(void){
	}

	MPISort::~MPISort(void){
	}

	void  MPISort::SortAlgorithm(std::vector<int>& vect){
		Run(vect);
	}
}