#include <time.h>
#include<stdio.h>
#include<omp.h> // Header file for OpenMP. It is already part of GCC

void main(){

	int a[10][10], i, j;

	
	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("The id is %d \n", id);
	}
}


