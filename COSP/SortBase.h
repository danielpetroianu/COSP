#pragma once

#include <vector>

namespace COSP
{
	// Abstract class used as base for sequential sorting algorithms
	class SortBase
	{
	public:

		//High layer method that calls the proper sort method, to sort data from a file
		//void Sort(IO::File_IO& );

		//High layer method that calls the proper sort method, to sort a vector
		void Sort(std::vector<int>& );

	protected:
		// Ctor
		SortBase(void);

		// Dtor
		virtual ~SortBase(void);

		//Method implemented by the derived class, and it contains the algorithm logic
		virtual void SortAlgorithm(std::vector<int>& ) = 0;

	//private:
		//File_IO _outputFile;
	};
};