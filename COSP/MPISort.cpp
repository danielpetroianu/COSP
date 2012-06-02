#include "StdAfx.h"
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
		IO::OUTPUT::LOG::INFO("MPISort::SortAlgorithm - BEGIN @"+ DtoS(start));

		MPIBase::Run(vect);

		double end = MPI::Wtime();
		IO::OUTPUT::LOG::INFO("MPISort::SortAlgorithm - END @"+ DtoS(end) +" Total time :~"+ DtoS(end-start));
	}
}