#include <mpi.h>
#include <stdlib.h>
#include <iostream>
#include "MPISort.h"
#include "BitonicMergesort.h"

using namespace COSP;
using std::cout;
using std::cin;
using std::endl;

int main(int argc,char *argv[])
{
    MPI::Init(argc,argv);
	
	std::vector<int> test(10);

	MPISort *sortAlg = new BitonicMergesort();

	sortAlg->Sort(test);
	
	//cout << "Process #" << sortAlg->GetPID() << "/" << sortAlg->GetNOP() << endl;

   

    MPI::Finalize();

    return EXIT_SUCCESS;
}