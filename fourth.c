#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int sum=0, i, j;

	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());

	
	#pragma omp parallel
	{
		int id = omp_get_thread_num();

		/* Within the different threads there are certain code that need be executed 
		   by a single thread. This can be done by the "master" thread. 
		   The directive #pragma omp master can be used for this */

		#pragma omp master
		printf("-------The process is starting------- \n");
		
		/* critical is used to define the critical section to overcome race condition.
		   If the critical section a single statement we can use #pragma omp atomic
		   Using critical involves a substantial overhead and this can be overcome by atomic */

		#pragma omp critical	
		{
			sum += id;
		}

		/* All the thread sybcrinizes at this point. Only if all the thread reach this barrier can
		   any of it move forward from this point */

		#pragma omp barrier 

		printf("The quotient for thread %d is %f \n", id, (float)sum/id);
		
	}
}


