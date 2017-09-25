To avoid race condition we have to define crtical sections. The code given inside a critical construct will be executed by only one thread at time.If there is only one line in the critical section we can use the atomic construct intead of crtical construct. It does not make the entire statement atomic, only the memory update involved in the instruction is atomic. A compiler might use special hardware instructions for better performance than when using critical construct. When a thread encounters a barrier construct, it will wait till all the threads has reached the barrier.  Critical, atomic and barrier are processes so it should be done only if it is entirely necessary. Program 1 shows the use of critical construct and program 2 shoes the use of the atomic construct. 

Program 1

include <time.h> 
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

        int sum=0, i, j;

        omp_set_num_threads(4);
        printf("The number of threads allocated are %d\n", omp_get_num_threads());

        
        #pragma omp parallel
        {
                int id = omp_get_thread_num();

                #pragma omp critical
                sum += id;

                #pragma omp barrier

                printf("The quotient for thread %d is %f \n", id, (float)sum/id);
                
        }
}



Program 2

include <time.h>
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

