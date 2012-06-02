#include <mpi.h>
#include <stdlib.h>
#include <iostream>
#include "MPIBase.h"

using namespace COSP;
using std::cout;
using std::cin;
using std::endl;

int main(int argc,char *argv[])
{
	MPI::Init(argc,argv);

	int NOP,
		PID,
		namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

	double start = MPI::Wtime();

	NOP		= MPI::COMM_WORLD.Get_size();
    PID     = MPI::COMM_WORLD.Get_rank();

	MPI::Get_processor_name(processor_name,namelen);

	cout << "Process #" << PID << "/" << NOP << " is on " << processor_name << endl;

	double end = MPI::Wtime();

	cout << "time #" << end - start;

	MPI::Finalize();

	return EXIT_SUCCESS;
}