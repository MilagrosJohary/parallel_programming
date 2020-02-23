/*
 ============================================================================
 Name        : PromedioOMP.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : Compute Pi in MPI C++
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
  int numThreads, tid;
  int n=80;
  int A[n];
  srand(time(NULL));

  for(int i=0;i<n;i++){
	  A[i]=rand()%100;
  }
  int suma=0,prom;
  omp_set_num_threads(10);
  /* This creates a team of threads; each thread has own copy of variables  */
#pragma omp parallel private(numThreads, tid)
 {
   tid = omp_get_thread_num();
   numThreads = omp_get_num_threads();

   for(int i=tid*(n/numThreads);i<(n/numThreads)*(tid+1);i++){
	 suma=suma+A[i];
	 printf(" Numero de hilos %d : %d \n", tid,A[i]);
   }


   /* The following is executed by the master thread only (tid=0) */
   if (tid == 0)
     {
       prom=suma/numThreads;
       printf("Numero de terminos es %d\n", n);
       printf("Numero de hilos %d\n", numThreads);
       printf("EL promedio de números es %d\n", prom);
     }

 }
 return 0;
}


