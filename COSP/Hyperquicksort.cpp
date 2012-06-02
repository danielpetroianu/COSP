#include "StdAfx.h"
#include "Hyperquicksort.h"

namespace COSP
{
	Hyperquicksort::Hyperquicksort()
	{
		MPIBase::Init();
	}

	Hyperquicksort::Hyperquicksort(int& argc, char**& argv)
	{
		MPIBase::Init(argc,argv);
	}

	Hyperquicksort::~Hyperquicksort(void)
	{
		MPIBase::Finalize();
	}

	void Hyperquicksort::RunMaster(std::vector<int>& vnr){
	}
	void Hyperquicksort::RunSlave(std::vector<int>& vnr){
	}

}