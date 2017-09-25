All the variables declared outside the parallel construct is shared by all the threads.  While all the variables declared inside the parallel construct is private to a specific thread.  In this program while a[], i, j are shared, variable id is private 


#include <time.h>
#include<stdio.h>
#include "omp.h" // Header file for OpenMP. It is already part of GCC

void arr(int A[][10], int id){

        int i;
        
        printf("The %d row is : ", id);
        for(i=0;i<4;i++)
                printf("%d  ", A[id][i]);

        printf("\n");

}


void main(){

        int a[10][10], i, j;

        omp_set_num_threads(4);
        printf("The number of threads allocated are %d\n", omp_get_num_threads());

        for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                        a[i][j] = i+j;

        #pragma omp parallel
        {
                int id = omp_get_thread_num();
                arr(a,id);
                printf("\n");
        }
}

