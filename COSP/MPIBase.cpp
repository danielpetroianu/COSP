#include "MPIBase.h"
#include <mpi.h>


COSP::MPIBase::MPIBase(void) : NOP(-1), PID(-1){
	Init();
}

COSP::MPIBase::~MPIBase(void)	{
	Finalize();
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

	NOP = PID = -1;
}

void COSP::MPIBase::Run(std::vector<int>& numbers){
	IsMaster() ? RunMaster(numbers) : RunSlave(numbers);
}

int COSP::MPIBase::GetPID(){
	return PID;
}

int COSP::MPIBase::GetNOP(){
	return NOP;
}

bool COSP::MPIBase::IsMaster(){
	return PID == MASTER;
}

bool COSP::MPIBase::IsSlave(){
	return PID != MASTER;
}