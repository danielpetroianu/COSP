#include "MPIBase.h"
#include <mpi.h>


COSP::MPIBase::MPIBase(void) : _NOP(-1), _PID(-1){
	Init();
}

COSP::MPIBase::~MPIBase(void)	{
	Finalize();
}

void COSP::MPIBase::Init(){
	if(!MPI::Is_initialized()){
		MPI::Init();
	}
	_NOP = MPI::COMM_WORLD.Get_size();
	_PID = MPI::COMM_WORLD.Get_rank();

}

void COSP::MPIBase::Init(int& argc, char**& argv){
	if(!MPI::Is_initialized()){
		MPI::Init(argc,argv);
	}

	_NOP = MPI::COMM_WORLD.Get_size();
	_PID = MPI::COMM_WORLD.Get_rank();
}

void COSP::MPIBase::Finalize(void){
	if(!MPI::Is_finalized()){
		MPI::Finalize();
	}

	_NOP = _PID = -1;
}

void COSP::MPIBase::Run(std::vector<int>& numbers){
	IsMaster() ? RunMaster(numbers) : RunSlave(numbers);
}

void COSP::MPIBase::RunMaster(std::vector<int>& vnr) {}
void COSP::MPIBase::RunSlave(std::vector<int>& vnr)  {}

int  COSP::MPIBase::GetPID() {return _PID; }
int  COSP::MPIBase::GetNOP() {return _NOP; }

bool COSP::MPIBase::IsMaster(){ return _PID == MASTER; }
bool COSP::MPIBase::IsSlave() { return _PID != MASTER; }

