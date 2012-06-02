#pragma once

#include "SortBase.h"
#include <memory>
#include "InsertionSort.h"

namespace COSP
{
	/*FINAL*/
	template<class T>
	class Quicksort : public SortBase
	{
	public:
		//Ctor
		Quicksort(void);

		//Dtor
		~Quicksort(void);

		//Quicksort algorithm
		void QSort(T start, T end);

		//Quicksort algorithm used on a section of a vector
		static void QSortSubVector(std::vector<T>&, int start, int length);

	private:
		void SortAlgorithm(std::vector<T>&);
	};
}