Within the different threads there are certain code that needs to be executed by a single thread. This can be done either by the master thread or by the first thread that encounters the block. In the former case we use master construct (program 1) and in the latter case we use the sinlge construct (program 2).

Program 1


#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

        int sum=0, i, j;

        omp_set_num_threads(4);
               
        #pragma omp parallel
        {
                int id = omp_get_thread_num();

                #pragma omp master
                printf("-------The process is starting------- \n");
                
                #pragma omp critical    
                {
                        sum += id;
                }
		#pragma omp barrier

                printf("The quotient for thread %d is %f \n", id, (float)sum/id);

        }
}

Program 2

#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

        int sum=0, i, j;

        omp_set_num_threads(4);

        #pragma omp parallel
        {
                int id = omp_get_thread_num();

                #pragma omp master
                printf("-------The process is starting------- \n");

                #pragma omp critical                
                {
                        sum += id;
                }
                #pragma omp barrier

                printf("The quotient for thread %d is %f \n", id, (float)sum/id);

        }
}

