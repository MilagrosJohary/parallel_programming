/*
 ============================================================================
 Name        : MPI_MAX.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : MPI_MAX es una operación de reducción predefinida que calculará el valor máximo de los valores reducidos
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
using namespace std;
 
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 4)
    {
        printf("This application is meant to be run with 4 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    // Determine root's rank
    int root_rank = 0;

    // Get my rank
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Each MPI process sends its rank to r reduction, root MPI process collects the result
    int reduction_result = 0;
    MPI_Reduce(&my_rank, &reduction_result, 1, MPI_INT, MPI_MAX, root_rank, MPI_COMM_WORLD);

    if(my_rank == root_rank)
    {
        printf("The max of all ranks is %d.\n", reduction_result);
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}
