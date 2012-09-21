#include "SortBase.h"
#include <iostream>

COSP::SortBase::SortBase(void){}
COSP::SortBase::~SortBase(void){}

//void COSP::SortBase::Sort(IO::File_IO& file){
//
//	if( !_outputFile.IsOpen() ){
//		string fileName =  file.GetFilePath() +"output_"+ file.GetFileNameWithExtension();
//		_outputFile.Open(fileName , IO::WRITE_ONLY);
//	}
//
//	std::vector<int> numbers;
//
//	int nr;
//
//	while( file >> nr )
//	{
//		numbers.push_back(nr);
//
//	}
//
//	SortBase::Sort(numbers);
//}

void COSP::SortBase::Sort(int arr[] ){
	std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(*arr));
	SortAlgorithm(vect);
}

void COSP::SortBase::Sort(std::vector<int>& numbers){
	SortAlgorithm(numbers);
}