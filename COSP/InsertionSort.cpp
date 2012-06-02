#include "StdAfx.h"
#include "InsertionSort.h"

namespace COSP
{
	InsertionSort::InsertionSort(void)
	{
	}

	InsertionSort::~InsertionSort(void)
	{
	}

	void InsertionSort::SortAlgorithm(std::vector<int>& numbers){
		LOG::INFO("\tInsertion::Sort - BEGIN");

		SortSubVector(numbers, 0, numbers.size());

		LOG::INFO("\tInsertion::Sort - END");
	}

	void InsertionSort::SortSubVector(std::vector<int>& numbers, int start, int length){
		LOG::INFO("\tInsertion::Sort - BEGIN - start:"+ ItoS(start) +" length:"+ ItoS(length));

		for(int i = start+1; i < length; i++){
			int key = numbers.at(i);
			int j =  i - 1;
			while(j >= 0 && numbers.at(j) > key){
				numbers.at(j+1) = numbers.at(j--);
			}

			numbers[j+1] = key;
		}

		LOG::INFO("\tInsertion::Sort - END - start:"+ ItoS(start) +" length:"+ ItoS(length));
	}
}