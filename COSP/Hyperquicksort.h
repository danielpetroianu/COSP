#pragma once

#include "MPISort.h"

namespace COSP
{
	/*FINAL*/
	class Hyperquicksort : public MPISort
	{
	public:
		// Ctor
		Hyperquicksort();

		// Ctor with console arguments
		Hyperquicksort(int& argc, char**& argv);

		// Dtor
		~Hyperquicksort(void);

	private:
		void RunMaster(std::vector<int>&);
		void RunSlave(std::vector<int>&);
	};
}