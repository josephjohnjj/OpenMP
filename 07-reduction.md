The reduction clause performs a reduction operation on the variables that appear in its list. A private copy for each list variable is created and initialized for each thread. At the end of the reduction, the reduction variable is applied to all private copies of the shared variable, and the final result is written to the global shared variable. 

#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void main(){

        int a[4]={1,2,3,4}, sum;


        omp_set_num_threads(4);
        
        #pragma omp parallel
        {
                int i;
                int id = omp_get_thread_num();


                #pragma omp for reduction(+:sum)
                for(i=0;i<4;i++){
                        sum += a[id];
                }

                #pragma omp single
                printf("The sum is %d\n", sum);
        }




