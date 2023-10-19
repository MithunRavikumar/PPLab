#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int t_c=strtol(argv[1],NULL,10);
	double sum=0;
    double start=omp_get_wtime();
#pragma omp parallel for num_threads(t_c) reduction(+:sum)
	for(int i=0;i<strtol(argv[2],NULL,10);i++)
		sum+=(pow(-1,i)/(2*i+1));
    double end=omp_get_wtime();

	printf("Sum=%f",4*sum);
    printf("Time taken is %lf",end-start);
}

// VERY IMPORTANT: GIVE ARGUMENT AS 8 100000 while executing
//Make sure value is closer to 3.14 u change arguments according to that(sum of limit plays a crucial role)
// Here 8 signifies the number of thread and 10000 limit of the sum