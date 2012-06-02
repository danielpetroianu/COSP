#include "StdAfx.h"
#include "Quicksort.h"
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

namespace COSP
{
	template<class T>
	Quicksort<T>::Quicksort(void)
	{
	}

	template<class T>
	Quicksort<T>::~Quicksort(void)
	{
	}

	template<class T>
	void Quicksort<T>::SortAlgorithm(std::vector<T>& numbers){
		LOG::INFO("Quicksort::Sort - BEGIN");

		QSort(numbers.begin(), numbers.end());

		LOG::INFO("Quicksort::Sort - END");
	}

	template<class T>
	void Quicksort<T>::QSort(T begin, T end){
		try{

			if(begin != end ){
				T middle = partition(
						begin,
						end,
						bind2nd(less<typename iterator_traits<T>::value_type>(), *begin)
					);

				QSortSubVector(begin, middle);
				QSortSubVector(max(begin+1, middle), end);
			}

		} catch(exception& e){
			LOG::EXCEPTION(e);
		}
	}

	template<class T>
	void Quicksort<T>::QSortSubVector(std::vector<T>& numbers, int low_idx, int high_idx){
		int i, j;
		try{
			if (low_idx < high_idx )
			{
				int middle_idx = (low_idx + high_idx) / 2;
				std::swap(numbers.at(low_idx), numbers.at(middle_idx));
				int pivot = numbers.at(low_idx);

				LOG::INFO("Quicksort::qsort low_idx:" + ItoS(low_idx) +" high:"+ ItoS(high_idx) +" pivot:" + ItoS(pivot));

				i = low_idx + 1;
				j = high_idx;

				while (i <= j)					// while the scan indices from left and right have not met,
				{
					while ((i <= high_idx) && (numbers.at(i) <= pivot))	// from the left, look for the first
						i++;												// element greater than the pivot
					while ((j>= low_idx) && (numbers.at(j) > pivot))	// from the right, look for the first
						j--;												// element not greater than the pivot
					if (i < j)											// if the left seekindex is still smaller than
						std::swap(numbers.at(i), numbers.at(j));			// the right index, swap the corresponding elements
				}
				std::swap(numbers.at(low_idx), numbers.at(j));

				QSortSubVector(numbers, low_idx, j - 1);	// quicksort the left partition
				QSortSubVector(numbers, j + 1, high_idx);	// quicksort the right partition
			}
		} catch(exception& e){
			LOG::EXCEPTION(e);
		}
	}
}