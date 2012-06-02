#include "SortBase.h"
#include <time.h>
#include <algorithm>

COSP::SortBase::SortBase(void){}
COSP::SortBase::~SortBase(void){}

//void COSP::SortBase::Sort(IO::File_IO& file){

//	if( !_outputFile.IsOpen() ){
//		string fileName =  file.GetFilePath() +"output_"+ file.GetFileNameWithExtension();
//		_outputFile.Open(fileName , IO::WRITE_ONLY);
//	}

//	std::vector<int> numbers;

//	int nr;

//	while( file >> nr )
//	{
//		numbers.push_back(nr);

//	}

//	SortBase::Sort(numbers);
//}

//void COSP::SortBase::Sort(std::vector<int>& numbers){

//	if( !_outputFile.IsOpen() ){
//		string fileName =  GetCurrentDir() +"\\output_vector_size"+ ItoS(numbers.size())+".txt";
//		_outputFile.Open(fileName , IO::WRITE_ONLY);
//	}

//	long start = clock(); // start stopwatch

//	SortAlgorithm(numbers);

//	double total_time = ((double)clock() - start) / CLOCKS_PER_SEC; //stop stopwatch
//	//LOG::ARRAY_INT(numbers);

//	//write the sorted elements
//	if( _outputFile.IsOpen() ){
//		_outputFile << "sorted in ~" << DtoS( total_time ) << "'s." << endl;
//		for(int i = 0; i < numbers.size(); i++){
//			_outputFile << numbers.at(i) << endl;
//		};
//	}
//}