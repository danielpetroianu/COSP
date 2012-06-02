#include "Hyperquicksort.h"

COSP::Hyperquicksort::Hyperquicksort()
{
	MPIBase::Init();
}

COSP::Hyperquicksort::Hyperquicksort(int& argc, char**& argv)
{
	MPIBase::Init(argc,argv);
}

COSP::Hyperquicksort::~Hyperquicksort(void)
{
	MPIBase::Finalize();
}

void COSP::Hyperquicksort::RunMaster(std::vector<int>& vnr){
}
void COSP::Hyperquicksort::RunSlave(std::vector<int>& vnr){
}