#include "MPISort.h"
#include <mpi.h>

namespace COSP
{
	MPISort::MPISort(void){
	}

	MPISort::~MPISort(void){
	}

	void  MPISort::SortAlgorithm(std::vector<int>& vect){
		double start = MPI::Wtime();

		MPIBase::Run(vect);

		double end = MPI::Wtime();
	}
}