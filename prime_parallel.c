#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n){
  if(n == 0 || n == 1){
    return 0;
  }
  for(int i = 2; i <= n/2; i++){
    if(n%i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){

  int x = 1,n;

  printf("enter the number of elements \n");
  scanf("%d",&n);

  int primes[n];

  double start = omp_get_wtime();
  #pragma omp parallel for
  for(int i = 1; i <= n;i++){
    if(isPrime(i)){
      int t = omp_get_thread_num();
      printf("Thread : %d , %d \n",t,i);
    }
  }
  double end = omp_get_wtime();
  printf("The time taken for parallel execution is %lf \n ",end - start);

  double start2 = omp_get_wtime();
  for(int i = 1; i <= n;i++){
    if(isPrime(i)){
      int t = omp_get_thread_num();
      printf("Thread : %d , %d \n",t,i);
    }
  }
  double end2 = omp_get_wtime();
  printf("The time taken for serial execution is %lf ",end2 - start2);
  
}