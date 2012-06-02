#include "MPIBase.h"
#include <mpi.h>


COSP::MPIBase::MPIBase(void) : NOP(-1), PID(-1){
	if(MPI::Is_initialized()){
		NOP = MPI::COMM_WORLD.Get_size();
		PID = MPI::COMM_WORLD.Get_rank();
	}
}

COSP::MPIBase::~MPIBase(void)	{
}

void COSP::MPIBase::Init(){
	if(!MPI::Is_initialized()){
		MPI::Init();
	}
	NOP = MPI::COMM_WORLD.Get_size();
	PID = MPI::COMM_WORLD.Get_rank();

}

void COSP::MPIBase::Init(int& argc, char**& argv){
	if(!MPI::Is_initialized()){
		MPI::Init(argc,argv);
	}
	NOP = MPI::COMM_WORLD.Get_size();
	PID = MPI::COMM_WORLD.Get_rank();

}

void COSP::MPIBase::Finalize(void){

	if(!MPI::Is_finalized()){
		MPI::Finalize();
	}

	NOP = 0;
	PID = 0;
}

void COSP::MPIBase::Run(std::vector<int>& numbers){
	if(IsMaster()){
		RunMaster(numbers);
	} else {
		RunSlave(numbers);
	}
}

int COSP::MPIBase::GetPID(){
	return PID;
}

int COSP::MPIBase::GetNOP(){
	return NOP;
}

bool COSP::MPIBase::IsMaster(){
	return PID == 0;
}

bool COSP::MPIBase::IsSlave(){
	return PID != 0;
}