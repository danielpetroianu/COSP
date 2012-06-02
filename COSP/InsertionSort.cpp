#include "InsertionSort.h"

COSP::InsertionSort::InsertionSort(void)
{
}

COSP::InsertionSort::~InsertionSort(void)
{
}

void COSP::InsertionSort::SortAlgorithm(std::vector<int>& numbers){
	SortSubVector(numbers, 0, numbers.size());
}

void COSP::InsertionSort::SortSubVector(std::vector<int>& numbers, int start, int length){
	for(int i = start+1; i < length; i++){
		int key = numbers.at(i);
		int j =  i - 1;
		while(j >= 0 && numbers.at(j) > key){
			numbers.at(j+1) = numbers.at(j--);
		}

		numbers[j+1] = key;
	}
}