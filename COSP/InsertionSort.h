#pragma once

#include "SortBase.h"

namespace COSP
{
	/*FINAL*/
	class InsertionSort : public SortBase
	{
	public:
		//Ctor
		InsertionSort(void);

		//Dtor
		~InsertionSort(void);

		//Insertion sort algorithm used on a section of a vector
		void SortSubVector(std::vector<int>& vector, int start, int length);

	private:
		void SortAlgorithm(std::vector<int>& );
	};
}