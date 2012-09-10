#pragma once

#include <vector>

namespace COSP 
{
	// Abstract class that wraps the MPICH2 implementation.
	class MPIBase
	{
	protected:
		//CONSTANTS
		static const int MASTER = 0;

		// Ctor
		MPIBase(void);

		// Dtor
		virtual ~MPIBase(void);

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

		// Main execution method
		virtual void Run(std::vector<int>& );

		// Execute the code for Master (PID = 0)
		virtual void RunMaster(std::vector<int>& );

		// Execute the code for the SLAVES (PID != 0)
		virtual void RunSlave(std::vector<int>& );

	private:
		int _PID; // process ID
		int _NOP; // number of processes/nodes
	};
}
