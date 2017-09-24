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

		#pragma omp atomic
		sum += id;

		#pragma omp barrier

		printf("The quotient for thread %d is %f \n", id, (float)sum/id);
		
	}
}


