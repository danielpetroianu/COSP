#pragma once

#include "MPISort.h"

namespace COSP
{
	/*FINAL*/
	class BitonicMergesort : public MPISort
	{
	public:
		// Ctor
		BitonicMergesort();

		// Ctor with console arguments
		BitonicMergesort(int& argc, char**& argv);

		// Dtor
		~BitonicMergesort(void);

	private:
		void Run(std::vector<int>&);
	};
}