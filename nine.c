#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int i, var=5;


	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());
	
	/* If we use lastprivate the value of the last iteration seen in the parallel for
	    will be copied to the global variable */ 
	
	#pragma omp parallel for lastprivate(var)
	for(i=0;i<4;i++)
	{
		printf(" The value inside parallel is %d\n", var);
		var = var+1;
				
	}

	printf("The value outside parallel is %d\n", var);
}


