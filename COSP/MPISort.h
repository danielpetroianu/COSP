#pragma once

#include "MPIBase.h"
#include "SortBase.h"

namespace COSP
{
	// Abstract class used as  base by the parallel sorting algorithms
	class MPISort : public MPIBase, public SortBase
	{
	public:
		// Ctor
		MPISort(void);

		// Dtor
		virtual ~MPISort(void);

	protected:
		// Parallel sorting algorithm logic
		void SortAlgorithm(std::vector<int>&);
	};
}