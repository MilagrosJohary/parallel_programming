/*
 ============================================================================
 Name        : MPI_Prod.c
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
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 7)
    {
        printf("Aplicación para 7 procesos.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int suma = my_rank + 1;
    int reduction_result = 0;
    MPI_Reduce(&suma, &reduction_result, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if(my_rank == 0)
    {
        printf("El producto de valores es %d.\n", reduction_result);
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}

