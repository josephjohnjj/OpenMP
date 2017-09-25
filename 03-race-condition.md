Race condition is a situation where multiple threads try to write to the same variable simultaneously. Race condition will lead to data inconsistency.In the below example every thread is trying to write to the variable sum. This will result in data inconsistency in sum. 

#include <time.h>
#include<stdio.h>
#include<omp.h> // Header file for OpenMP. It is already part of GCC

void main(){

        int sum=0, i, j;

        omp_set_num_threads(4);
        

        #pragma omp parallel 
        {
                int id = omp_get_thread_num();
                sum += id;

        }

        printf("The sum is %d\n",sum);
}

