#include <stdio.h>
#include <omp.h>

void main() {
    int sum = 0;//This should be critical while executing 
    int n;
    printf("Enter n value \n");
    scanf("%d",&n);	
    double start=omp_get_wtime();
    #pragma omp parallel for 
    for (int i = 1; i <= n; i++) {
        #pragma omp critical
        sum += i;//Only one thread can update the value simultaneously
    }
    double end=omp_get_wtime();
    
    printf("Sum of the first 100 numbers: %d\n", sum);
    printf("Time taken to execute is %lf ",end-start);
}