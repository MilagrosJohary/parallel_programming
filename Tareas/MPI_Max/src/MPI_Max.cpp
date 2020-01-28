/*
 ============================================================================
 Name        : MPI_Max.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : Compute Pi in MPI C++
 ============================================================================
 */
#include <math.h> 
#include "mpi.h" 
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int sum,x,rank,i,size,suma,maximo;
    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for (i = rank + 1; i <= 10; i += size) {
    		x = x + 2;
    		sum += x * x;
    	}
    suma = sum+1;

    MPI_Reduce(&suma, &maximo, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if(rank == 0)
    {
        printf("El valor maximo es %d.\n", maximo);
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}

