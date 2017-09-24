#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int var=5;


	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());

	/* If we use first private the value of the global variable will
	   be copied to the private variable inside the parallel for */
	
	#pragma omp parallel  lastprivate(var)
	{
		printf(" The value inside parallel is %d\n", var);
		var = var+1;
				
	}
	

	printf("The value outside parallel is %d\n", var);
}


