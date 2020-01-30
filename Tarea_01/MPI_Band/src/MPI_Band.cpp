/*
 ============================================================================
 Name        : MPI_Band.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : MPI_BAND es una operación de reducción que calculará los bits y los valores reducidos
 ============================================================================
 */
#include <math.h> 
#include "mpi.h" 
#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);


    int tam,my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &tam);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int root_rank = 0;

    char all_values[4] = {0, 2, 4, 8};
    char my_value = all_values[my_rank];
    char reduction_result = 0;

    MPI_Reduce(&my_value, &reduction_result, 1, MPI_UNSIGNED_CHAR, MPI_BAND, root_rank, MPI_COMM_WORLD);

    if(my_rank == root_rank)
    {
        printf("Los bits de los valores son %d.\n", reduction_result);
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}

