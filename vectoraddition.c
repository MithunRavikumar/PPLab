#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int ops = 0;

void vector_addn(int n,int *res,int * a,int *b)
{
	#pragma omp parallel for
	for(int i=0;i<n;i++)
	{
		res[i] = a[i]+b[i];
		#pragma omp critical
		{ops+=1;}
	}
}

void main(){
	int n;
    printf("Enter n value");
    scanf("%d",&n);	
	int a[n],b[n],c[n];

	for (int i=0;i<n;i++)
	{
		a[i] = rand()%100;
		b[i] = rand()%100;
	}

      
	vector_addn(n,c,a,b);
    double start =omp_get_wtime();
    #pragma omp parallel for
	for (int i = 0; i < n; i++){
		int t = omp_get_thread_num();
        printf("%d + %d = %d for thread %d\n",a[i],b[i],c[i],t);
        }
	double end =omp_get_wtime();
	printf("Total operation is %d and total time taken is %lf\n",ops,end-start);
}