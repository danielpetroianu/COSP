#include "SortBase.h"
#include <time.h>
#include <algorithm>
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

void COSP::SortBase::Sort(std::vector<int>& numbers){

	long start = clock(); // start stopwatch

	SortAlgorithm(numbers);

	double total_time = ((double)clock() - start) / CLOCKS_PER_SEC; //stop stopwatch

	std::cout<< "done sorting in " << total_time << "s" << std::endl;
}