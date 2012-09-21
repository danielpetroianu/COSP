#include "BitonicMergesort.h"
#include <mpi.h>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;


COSP::BitonicMergesort::BitonicMergesort(){ }
COSP::BitonicMergesort::BitonicMergesort(int& argc, char**& argv){ 
	Init(argc, argv);
}
COSP::BitonicMergesort::~BitonicMergesort(void){ }

void COSP::BitonicMergesort::Run(vector<int>& numbers)
{
	if(numbers.empty()) return;

	cout << "BMS - Run #" << PID() << " vector size: " << numbers.size() << endl;

	int dim = log(NOP()+1e-10)/log(2.0);

	if (IsMaster()) {
		int number = -1;
		MPI::COMM_WORLD.Send(&number, 1, MPI::INT, 1, 0);
	} else if (PID() == 1) {
		int number;
		MPI::COMM_WORLD.Recv(&number, 1, MPI::INT, 0, 0);
		cout<< "Process 1 received number "<< number <<" from process 0\n";
	} else{
		cout<<"dim: "<< dim << endl;
	}

	/*int listsize, l, m, bitl = 1, bitm, partner, i;
	MPI::Status status;

	listsize = numbers.size()/NOP();

	mergesort(numbers, 0, (listsize-1), (PID() & bitl) );

	for (l=1; l<=dim; l++) {
	bitl = bitl << 1;
	for (bitm=1, m=0; m<l-1; m++) bitm *= 2;
	for (m=l-1; m>=0; m--) {
	partner = PID() ^ bitm;
	MPI::COMM_WORLD.Send(&numbers.front(), listsize, MPI::INTEGER, partner, l*dim+m);
	MPI::COMM_WORLD.Recv(&numbers[listsize],listsize,MPI::INTEGER,partner, l*dim+m, &status);
	mergesort(numbers,0,2*listsize-1,PID() & bitl);
	if (PID() & bitm)
	for (i=0; i<listsize; i++) numbers[i] = numbers[i+listsize];
	bitm = bitm >> 1;
	}
	} */
}

/* Sequential mergesort (either ascending or descending) */
void COSP::BitonicMergesort::mergesort(vector<int>& list,const int left, const int right, const int descending)
{
	int i,j,k,t,middle,temp[1024];
	if (left < right) {
		middle = (left + right)/2;
		mergesort(list,left,middle,descending);
		mergesort(list,middle+1,right,descending);
		k = i = left; j = middle+1;
		if (descending)
			while (i<=middle && j<=right)
				temp[k++] = list[i]>list[j] ? list[i++] : list[j++];
		else
			while (i<=middle && j<=right)
				temp[k++] = list[i]<list[j] ? list[i++] : list[j++];
		t = i>middle ? j : i;
		while (k <= right) temp[k++] = list[t++];
		for (k=left; k<=right; k++) list[k] = temp[k];
	}
}

