#include "stdafx.h"
#include "SortBase.h"
#include <time.h>
#include <algorithm>

namespace COSP
{
	SortBase::SortBase(void){}
	SortBase::~SortBase(void){}

	void SortBase::Sort(IO::File_IO& file){
		LOG::INFO("SortBase::Sort - BEGIN ( file name:"+ file.GetFileNameWithExtension() +" )");

		if( !_outputFile.IsOpen() ){
			string fileName =  file.GetFilePath() +"output_"+ file.GetFileNameWithExtension();
			_outputFile.Open(fileName , IO::WRITE_ONLY);
		}

		std::vector<int> numbers;

		int nr;

		while( file >> nr )
		{
			numbers.push_back(nr);
			LOG::INFO("SortBase::Sort - read " + ItoS(nr));
		}

		SortBase::Sort(numbers);
		LOG::INFO("SortBase::Sort - END");
	}

	void SortBase::Sort(std::vector<int>& numbers){
		LOG::INFO("SortBase::Sort - BEGIN ( vector size:"+ ItoS(numbers.size()) +" )");

		if( !_outputFile.IsOpen() ){
			string fileName =  GetCurrentDir() +"\\output_vector_size"+ ItoS(numbers.size())+".txt";
			_outputFile.Open(fileName , IO::WRITE_ONLY);
		}

		long start = clock(); // start stopwatch

		SortAlgorithm(numbers);

		double total_time = ((double)clock() - start) / CLOCKS_PER_SEC; //stop stopwatch

		LOG::INFO("SortBase::Sort - END time spent: ~"+ DtoS( total_time ) +"'s.");
		//LOG::ARRAY_INT(numbers);

		//write the sorted elements
		if( _outputFile.IsOpen() ){
			_outputFile << "sorted in ~" << DtoS( total_time ) << "'s." << endl;
			for(int i = 0; i < numbers.size(); i++){
				_outputFile << numbers.at(i) << endl;
			};
		}
	}
}