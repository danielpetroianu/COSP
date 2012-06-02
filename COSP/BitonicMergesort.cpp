#include "BitonicMergesort.h"
#include <mpi.h>

COSP::BitonicMergesort::BitonicMergesort()
{
	COSP::MPIBase::Init();
}

COSP::BitonicMergesort::BitonicMergesort(int& argc, char**& argv)
{
	COSP::MPIBase::Init(argc,argv);
}

COSP::BitonicMergesort::~BitonicMergesort(void)
{
	COSP::MPIBase::Finalize();
}

void COSP::BitonicMergesort::RunMaster(std::vector<int>& vnr){
}
void COSP::BitonicMergesort::RunSlave(std::vector<int>& vnr){
}

void COSP::BitonicMergesort::Run(std::vector<int>& vnr){
	///* We will assume that the array (arr) of length SIZE, consists of random integers. */

	///* The master process must distribute the list among all available processors.  Each processor must receive the list  */
	///*  and sort it in the proper order */
	//if( MASTER ){
	//	int i;
	//	int n_p = vnr.size() / GetNOP(); /* Number of elements per processor */

	//	/* Store all needed local quantities for the master process */
	//	localSize = n_p;
	//	localUp = 1;
	//	localArr = malloc( n_p * sizeof( int ) );

	//	/* Distribute the array portions amongst all of the available processors */
	//	/* Alternating the sort orders */
	//	int up, currentIndex;
	//	for(i = 1; i <= GetNOP(); i++){
	//		up = (i + 1) % 2; //Must be 0 for even numbered sets (odds) and 1 for odds
	//		currentIndex = i * n_p;

	//		MPI::Comm::Send( &up, 1, MPI::INT, i, tag);
	//		MPI::Comm::Send( &n_p, 1, MPI::INT, i, tag );
	//		MPI::Comm::Send( &(arr[currentIndex]), n_p, MPI_INT, i, tag );
	//	}//end for : sending to all processors

	//	/* Load the first n/p elements into the master's local array */
	//	/* (This was done first to allow the other processors to begin sorting) */
	//	for(i = 0; i < n_p; i++){
	//		localArr[i] = arr[i];
	//	}//end for : Load the master's local array

	//	/* Have the master processor sort the local portion of the list */
	//	bitonic_sort( 1, localArr, 0, n_p - 1 );

	//}else{
	//	/* Receive the assignment data from the master process */
	//	int n, up;
	//	MPI::Comm::Recv( &up, 1, MPI_INT, source, tag, &status );
	//	MPI::Comm::Recv( &n, 1, MPI_INT, source, tag, &status );
	//	int arr[n];
	//	MPI::Comm::Recv( &arr, n, MPI_INT, source, tag,  &status );

	//	/* Store all values into the local variables */
	//	localSize = n;
	//	localUp = up;
	//	localArr = malloc( n * sizeof( int ) );
	//	int i;
	//	for(i = 0; i < n; i++){
	//		localArr[i] = arr[i];
	//	}//end for : load local array

	//	/* Perform the Assigned sorting task*/
	//	bitonic_sort( up, localArr, 0, n - 1 );

	//}//end if-else : sort initial lists

	///* All processors must wait for the other to complete their local sorts before */
	///* continuing the sort */
	//MPI_Barrier( MPI_COMM_WORLD );

	///* Begin inter-processor merging operations */
	//int i,j;
	//for( i = 0; i < log_p + 1 ; i++ ){
	//	for( j = i; j > 0; j-- ){
	//		/* compare and exchange elements with the processor obtained by inverting jth bit of id*/
	//		int id[p];
	//		getBinary( my_rank, id, p);
	//		int ithBit = id[i];
	//		flipBit( id, j ); /* Flip the jth bit of id to find processor to exchange with*/
	//		int partnerId = getDecimal( id, p);

	//		if( ithBit == 0 ){
	//			if( my_rank > partnerId ){
	//				swap_with( partnerId, 0);
	//			}else if( my_rank < partnerId ){
	//				swap_with( partnerId, 1);
	//			}else{
	//				bitonic_merge( 1, localArr, 0, localSize - 1 );
	//			}//end if-else
	//		}else{
	//			if( my_rank > partnerId ){
	//				swap_with( partnerId, 1);
	//			}else if( my_rank < partnerId ){
	//				swap_with( partnerId, 0);
	//			}else{
	//				bitonic_merge( 0, localArr, 0, localSize - 1 );
	//			}//end if-else
	//		}//end if-else

	//	}//end for
	//}//end for

	///* Perform 1 final local merge on all processors */
	//bitonic_merge( 1, localArr, 0, localSize - 1 );
}