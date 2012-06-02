#pragma once

#include "MPIBase.h"
#include "SortBase.h"

class IO::File_IO;

namespace COSP
{
	// Abstract class used as  base by the parallel sorting algorithms
	class MPISort : public MPIBase, public SortBase
	{
	protected:
		// Ctor
		MPISort(void);

		// Dtor
		virtual ~MPISort(void);

		// Parallel sorting algorithm logic
		void SortAlgorithm(std::vector<int>&);

		// Method implemented by the derived class to execute
		// the code for Master(PID = 0)
		virtual void RunMaster(std::vector<int>&) = 0;

		// Method implemented by the derived class to execute
		// the code for Slave(PID != 0)
		virtual void RunSlave(std::vector<int>&)  = 0;
	};
}