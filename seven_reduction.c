#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int a[4]={1,2,3,4}, sum;


	omp_set_num_threads(4);
	printf("The number of threads allocated are %d\n", omp_get_num_threads());

	
	#pragma omp parallel
	{
		int i;
		int id = omp_get_thread_num();

		
		/* Using pargma omp for will enable each iteration to be done by a different thread*/

		#pragma omp for reduction(+:sum)
		for(i=0;i<4;i++){
			sum += a[id];	
		}
		
		#pragma omp single
		printf("The sum is %d\n", sum);
	}

 

}


