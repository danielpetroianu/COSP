////http://cacs.usc.edu/education/cs653/02-3DC.pdf
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include "mpi.h"
//#define N 1024
//#define MAX 99
//int nprocs,dim,myid; /* Cube size, dimension, & my node ID */
///* Sequential mergesort (either ascending or descending) */
//void mergesort(int list[],int left,int right,int descending)
//{
//	int i,j,k,t,middle,temp[N];
//	if (left < right) {
//		middle = (left + right)/2;
//		mergesort(list,left,middle,descending);
//		mergesort(list,middle+1,right,descending);
//		k = i = left; j = middle+1;
//		if (descending)
//			while (i<=middle && j<=right)
//				temp[k++] = list[i]>list[j] ? list[i++] : list[j++];
//		else
//			while (i<=middle && j<=right)
//				temp[k++] = list[i]<list[j] ? list[i++] : list[j++];
//		t = i>middle ? j : i;
//		while (k <= right) temp[k++] = list[t++];
//		for (k=left; k<=right; k++) list[k] = temp[k];
//	} 
//}
//
///* Parallel mergesort */
//void parallel_mergesort(int myid,int list[],int n)
//{
//	int listsize, l, m, bitl = 1, bitm, partner, i;
//	MPI_Status status;
//	listsize = n/nprocs;
//	mergesort(list,0,listsize-1,myid & bitl);
//	for (l=1; l<=dim; l++) {
//		bitl = bitl << 1;
//		for (bitm=1, m=0; m<l-1; m++) bitm *= 2;
//		for (m=l-1; m>=0; m--) {
//			partner = myid ^ bitm;
//			MPI_Send(list,listsize,MPI_INT,partner,l*dim+m,MPI_COMM_WORLD);
//			MPI_Recv(&list[listsize],listsize,MPI_INT,partner,l*dim+m,
//				MPI_COMM_WORLD,&status);
//			mergesort(list,0,2*listsize-1,myid & bitl);
//			if (myid & bitm)
//				for (i=0; i<listsize; i++) list[i] = list[i+listsize];
//			bitm = bitm >> 1;
//		}
//	} 
//}
//
//int main(int argc,char *argv[])
//{
//	int list[N],n=8,i;
//	
//	MPI_Init(&argc,&argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
//	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
//	
//	if(myid == 0){
//		dim = (int)(log((double)nprocs)/log(2.0));
//
//		srand((unsigned) myid+1);
//		
//		for (i=0; i<n; i++)
//			list[i] = rand()%MAX;
//	}
//	
//	if(myid == 0) 
//		for (i=0; i<n; i++)
//			printf("%3d ",list[i]);
//
//	//printf("Before: Node %2d :",myid);
//	//for (i=0; i<n/nprocs; i++)	printf("%3d ",list[i]);
//	//printf("\n");
//	//
//	parallel_mergesort(myid,list,n);
//	if(myid == 0) {
//		printf("After:  Node %2d :",myid);
//		for (i=0; i<n/nprocs; i++)	printf("%3d ",list[i]);
//		printf("\n");
//	}
//	MPI_Finalize();
//	
//	return 0;
//}
//
//
//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//#include <math.h>
//#include <time.h>
//#include <sys/time.h>
//#include <string.h>
//
//#include "bs-util.h"
//#include "quicksort.h"
//
//#define TAG 1
//
//
///* Run this program knowing that:
// * 1) The number of cores must be a power of 2
// * 2) The length of the array to order must be a power of 2
// * 
// * Exec Example: mpirun -n 4 ./bs 1024 1024
// * */
//
//
//void exchange(FILE *log, int i, int partner, int up);
//
//int countTransfer = 0;
//
//int *myArray, *partnerArray;
//int currentPartner = -1;
//int rank, size;
//MPI_Status status;
//int verbose = 0; //this var toggles on(1) or off(0) some useful prints for debugging purpose
//int amount=0;
//
//int main(int argc, char *argv[])
//{
//    int *array;
//    int i=0;
//    int carry=0;
//    int up=1;
//    int count=0;
//
//    struct timeval tim;
//
//    FILE *log;
//
//    char logName[15] = "log/";
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    /* Time meter */
//    srand((double) time(NULL));
//    gettimeofday(&tim, NULL);
//    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
//
//    snprintf(logName+4, 10, "%d",rank);
//    log = fopen(logName,"w");
//
//    printf("Hello world from process %d of %d.\n", rank, size);
//    MPI_Barrier(MPI_COMM_WORLD);
//
//    /* INPUT */
//
//    if (rank==0) 
//    {   
//        if (argc==2) /* by file */
//        {
//            FILE *input = fopen(argv[1],"r");
//            char line[20]; 
//            count = 0;
//            while(fgets(line,20,input) != NULL)
//            {
//                count++;
//            }
//            fclose(input);
//            array = (int *)malloc(count*sizeof(int));
//            input = fopen(argv[1],"r");
//            i = 0;
//            while(fgets(line,20,input) != NULL)
//            {
//                array[i] = atoi(line);
//                i++;
//            }
//            fclose(input);
//        }
//        else
//            if (argc==3) /* by command line */
//            {
//                count = atoi(argv[1]); 
//                int max = atoi(argv[2]);
//                array = (int *)malloc(count*sizeof(int));
//                srand(time(NULL));
//                for (i=0; i<count; i++)
//                {
//                    array[i] = rand()%max;
//                }
//            }
//            else
//            {
//                printf("\n\n ----------- ERRORE NEI PARAMETRI DI INPUT ----------- \n\n");
//                return 1;
//            }
//
//        /* END OF THE INPUT */
//
//        if (verbose){
//            printf("Initial array:\n");
//            for (i=0; i<count; i++)
//            {
//                printf("%d\t", array[i]);
//            }
//            printf("\n");
//        }
//        /* Everyone wait eachother */
//        MPI_Barrier(MPI_COMM_WORLD);
//
//        carry = count%size;
//        amount = count/size + carry;
//        printf("\nParametri: amount=%d carry=%d\n\n", amount, carry);
//        up=1;
//        int startIndex = amount;
//
//
//        myArray = (int *)malloc(amount*sizeof(int));
//        /* Buffer (partner) */
//        partnerArray = (int *)malloc(amount*sizeof(int));
//
//        for (i=0; i<amount; i++)
//             myArray[i] = array[i];
//        printf("Processo %d riceve amount=%d e up=%d\n", rank, amount, up);
//        if (verbose){
//            printf("Mia porzione ---> ");
//            for (i=0; i<amount; i++)
//            {
//                printf("%d\t", myArray[i]);
//            }
//            printf("\n");
//        }
//
//        /* Sending the big array's chunks */
//        for (i=1; i<size; i++)
//        {
//            up = (i+1) % 2;
//            MPI_Send(&up, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
//            MPI_Send(&amount, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
//            MPI_Send(&carry, 1, MPI_INT, i, TAG, MPI_COMM_WORLD);
//
//            MPI_Send(array+startIndex, amount-carry, MPI_INT, i, TAG, MPI_COMM_WORLD);
//
//            startIndex += amount-carry;
//        }
//
//        MPI_Barrier(MPI_COMM_WORLD); 
//    } 
//    else
//    {
//        MPI_Barrier(MPI_COMM_WORLD);
//
//        MPI_Recv(&up, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
//        MPI_Recv(&amount, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
//        MPI_Recv(&carry, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
//        myArray = (int *)malloc(amount*sizeof(int));
//        partnerArray = (int *)malloc(amount*sizeof(int)); /* Buffer (partner) */
//        MPI_Recv(myArray, amount, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status);
//
//
//        /* Experimental padding: every chunck has the same amount of items. */
//        for (i=amount-carry; i<amount; i++)
//        {
//            myArray[i] = 0;
//        }
//
//        printf("\n");
//        printf("Processo %d riceve amount=%d e up=%d\n", rank, amount-carry, up);
//        if (verbose){
//            printf("Mia porzione ---> ");
//            for (i=0; i<amount; i++)
//            {
//                printf("%d\t", myArray[i]);
//            }
//            printf("\n");
//        }
//        MPI_Barrier(MPI_COMM_WORLD);
//    }
//
//    /* CORE */
//
//    /* Local Quicksort */
//    int result = quickSort(&myArray[0], amount); //this function is written within src/quicksort.c
//    if (verbose){
//        if (result == 1)
//            printf("Quick Sort: FAIL \n");
//        else
//        {
//            printf("\nLa mia porzione ordinata (processo %d)\n", rank);
//            for(i=0; i<amount; i++)
//            {
//                printf("%d ",myArray[i]);
//            }
//            printf ("\n");
//        }
//    }
//
//    int j;
//
//    for (up=8;up<=amount*size;up=2*up)
//    {
//        for (j=up>>1;j>0;j=j>>1)
//        {
//            for (i=0;i<amount*size;i++)
//            {
//                int partner=i^j;                
//                if ((partner)>i)
//                {   
//                    exchange(log,i,partner,i&up);
//                }
//
//            }
//        }
//    }
//
//    /* END OF THE CORE */
//
//    if (rank!=0)
//    {   
//        MPI_Send(myArray, amount, MPI_INT, 0, TAG, MPI_COMM_WORLD);
//    }
//    gettimeofday(&tim, NULL);
//    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
//    if (rank==0)
//    {
//        myArray = (int *)realloc(myArray,sizeof(int)*amount*size);
//        for (i=1; i<size; i++)
//            MPI_Recv(myArray+i*amount, amount, MPI_INT, i, TAG, MPI_COMM_WORLD, &status);
//        printf("\nTempo trascorso %6f\n", t2-t1);
//        fprintf(log,"\n\n----------> Array Iniziale <----------\n");
//        printArray(log,array,count);
//        fprintf(log,"\n\n----------> Array Finale <----------\n");
//        printArray(log,myArray+(carry*(size-1)),count);
//        /*printArray(log,myArray,newAmount*size);*/
//
//    }    
//    fprintf(log,"Numero di chunk scambiati: %d\n",countTransfer);
//    fclose(log);
//    MPI_Finalize();
//    return 0;
//}
//
//void exchange(FILE *log, int i, int partner, int up)
//{
//    int rank_i = i/amount;
//    int rank_partner = partner/amount;
//
//    int offset_i = i%amount;
//    int offset_partner = partner%amount;
//    /*if (verbose)
//        fprintf(log,"\nnewAmount = %d - Rank_i = %d - Rank_partner = %d - Offset_i = %d - Offset_partner = %d \n",amount,rank_i,rank_partner,offset_i,offset_partner);
//    */
//
//    if ((rank_i != rank) && (rank_partner != rank))
//        return;
//
//    if ((rank_i == rank) && (rank_partner == rank))
//    {   
//        if (((up==0) && (myArray[offset_i] > myArray[offset_partner])) || ((up!=0) && (myArray[offset_i] < myArray[offset_partner])))
//        {
//            int temp = myArray[offset_i];
//            myArray[offset_i] = myArray[offset_partner];
//            myArray[offset_partner] = temp;
//        }
//        return;
//    }
//
//    if (rank_i == rank && rank_partner != rank)
//    {
//        if (currentPartner != rank_partner)
//        {
//            MPI_Send(myArray, amount, MPI_INT, rank_partner, TAG, MPI_COMM_WORLD);
//            MPI_Recv(partnerArray, amount, MPI_INT, rank_partner, TAG, MPI_COMM_WORLD, &status);
//            currentPartner = rank_partner;
//            countTransfer++;
//        }
//        if (((up==0) && (myArray[offset_i] > partnerArray[offset_partner])) || ((up!=0) && (myArray[offset_i] < partnerArray[offset_partner])))
//            myArray[offset_i] = partnerArray[offset_partner];
//        return;
//    }
//
//    if (rank_i != rank && rank_partner == rank)
//    {
//        if (currentPartner != rank_i)
//        {
//            MPI_Recv(partnerArray, amount, MPI_INT, rank_i, TAG, MPI_COMM_WORLD, &status);
//            MPI_Send(myArray, amount, MPI_INT, rank_i, TAG, MPI_COMM_WORLD);
//            currentPartner = rank_i;
//            countTransfer++;
//        }
//        if (((up==0) && (partnerArray[offset_i] > myArray[offset_partner])) || ((up!=0) && (partnerArray[offset_i] < myArray[offset_partner])))
//            myArray[offset_partner] = partnerArray[offset_i];
//        return;
//    }
//
//}