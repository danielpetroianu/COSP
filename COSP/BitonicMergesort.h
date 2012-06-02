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
		void RunMaster(std::vector<int>&);
		void RunSlave(std::vector<int>&);
		void Run(std::vector<int>&);
	};
}