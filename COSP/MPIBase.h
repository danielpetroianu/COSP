#pragma once

#include <vector>

namespace COSP 
{
	// Abstract class that wraps the MPICH2 implementation.
	class MPIBase
	{
	public:
		// Ctor
		MPIBase(void);

		// Dtor
		virtual ~MPIBase(void);

	protected:
		// Main execution method
		virtual void Run(std::vector<int>& );

		// Execute the code for Master (PID = 0)
		virtual void RunMaster(std::vector<int>& ) = 0;

		// Execute the code for the SLAVES (PID != 0)
		virtual void RunSlave(std::vector<int>& )  = 0;

		// Initialize the MPI
		void Init();

		// Initialize the MPI with the the console arguments
		void Init(int& , char**& );

		// Terminate the MPI
		void Finalize(void);

		// Get the Process ID
		int GetPID();

		// Get the number or processes
		int GetNOP();

		// Check if the current process is Master
		bool IsMaster();

		// Check if the current process is Slave
		bool IsSlave();

	private:
		int PID; // process ID
		int NOP; // number of processes/node
	};
}
