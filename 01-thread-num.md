In OpenMP we can ask the compiler for the number of threads. The function to set the number of threads is omp_set_num_threads(). It is not necessary that the compiler allocates the number of threads requested by the user. To get the number of threads actually allocated by the user we can use the function omp_get_thread_num().



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


