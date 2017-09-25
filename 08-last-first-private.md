When a variable is declared as private, each thread gets a unique memory address of where to store values for that variable while in the parallel region. When the parallel region ends, the memory is freed and these variables no longer exist.

Lastprivate keeps  the last value of a variable after the parallel region. The last value is the last private value held by the iteration that finishes last. 

Firstprivate Specifies that each thread should have its own instance of a variable, and that the variable should be initialized with the value of the variable, because it exists before the parallel construct. 

Program 1

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
 
void main(){
	int i, x=10;

	#pragma omp parallel for private(x)
	for(i=0;i<=10;i++){
		x=i;
		printf("Thread number: %d     x: %d\n",omp_get_thread_num(),x);
	}

	printf("x is %d\n", x); 
}


Program 2

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
 
void main(){
        int i, x=10;

        #pragma omp parallel for firstprivate(x)
        for(i=0;i<=10;i++){
                x=i;
                printf("Thread number: %d     x: %d\n",omp_get_thread_num(),x);
        }

        printf("x is %d\n", x);
}



Program 3

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
 
void main(){
        int i, x=10;

        #pragma omp parallel for lastprivate(x)
        for(i=0;i<=10;i++){
                x=i;
                printf("Thread number: %d     x: %d\n",omp_get_thread_num(),x);
        }

        printf("x is %d\n", x);
}
