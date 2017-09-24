#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int i, var=5;


	omp_set_num_threads(3);
	
	   /* Static schedule divide the loop into equal-sized chunks or as equal as possible in the case 
		where the number of loop iterations is not evenly divisible by the number of threads multiplied 
		by the chunk size. By default, chunk size is loop_count/number_of_threads. Dynamic use the internal 
		work queue to give a chunk-sized block of loop iterations to each thread. When a thread is finished, 
		it retrieves the next block of loop iterations from the top of the work queue. By default, the chunk 
		size is 1. Be careful when using this scheduling type because of the extra overhead involved. Guided	
		is similar to dynamic scheduling, but the chunk size starts off large and decreases to better handle 
		load imbalance between iterations. In auto the decision regarding scheduling is delegated to the compiler. 
		The programmer gives the compiler the freedom to choose any possible mapping of iterations to threads in the team.
		runtime	Uses the OMP_schedule environment variable to specify which one of the three loop-scheduling 
		types should be used. OMP_SCHEDULE is a string formatted exactly the same as would appear on the parallel construct. */ 
	
	#pragma omp parallel for schedule(guided,2)
	for(i=0;i<11;i++)
	{
		printf(" This is done by %d\n",omp_get_thread_num() );
						
	}


}


