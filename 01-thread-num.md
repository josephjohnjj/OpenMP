In OpenMP we can ask the compiler for the number of threads. The function to set the number of threads is omp_set_num_threads(). It is not necessary that the compiler allocates the number of threads requested by the user. To get the number of threads actually allocated by the user we can use the function omp_get_thread_num().

In program 1 the number of threads is printed outside the parallel block. Outside the parallel block there is only thread. So the thread number will be set as one. In program 2 the number of theads is printed inside the parallel block. In thiss case we will get the actual number of threads that allocated. 

Each thread will be allocated a thread number starting from 0. The thread id of each thread can be found using the function omp_get_thread_num()

Program 1

#include <time.h>
#include<stdio.h>
#include<omp.h> // Header file for OpenMP. It is already part of GCC

void main(){

        int i, j;

        
        omp_set_num_threads(4);
        printf("The number of threads allocated are %d\n", omp_get_num_threads()); 

        #pragma omp parallel
        {
                int id = omp_get_thread_num();
                printf("The id is %d \n", id);
        }
}

Program 2

#include <time.h>
#include<stdio.h>
#include<omp.h> 

void main(){

        int i, j;


        omp_set_num_threads(4);
       
        #pragma omp parallel
        {
		printf("The number of threads allocated are %d\n", omp_get_num_threads());
                int id = omp_get_thread_num();
                printf("The id is %d \n", id);
        }
}


