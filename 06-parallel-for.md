For loop can be parallelized in OpenMP using the parallel for construct. Each iteration in the for loop will be done by a different thread. If there is a data dependence between iteration this can lead to inconsistant data. This construct is mainly useful in case of independant iterations. 

#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

	int a[4]={1,2,3,4}, b[4]={10,20,30,40}, c[4];


	omp_set_num_threads(4);
		
	#pragma omp parallel
	{
		int i;
		int id = omp_get_thread_num();

		
		/* Using pargma omp for will enable each iteration to be done by a different thread*/

	
		#pragma omp parallel for 
		for(i=0;i<4;i++){
			c[i] = a[i]+b[i];	
			printf("The sum of the cell %d is %d\n", id, c[id]); 
		} 
		#pragma omp barrier
	}

}


