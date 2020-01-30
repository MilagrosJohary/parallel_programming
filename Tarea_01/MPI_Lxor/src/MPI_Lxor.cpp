/*
 ============================================================================
 Name        : MPI_Lxor.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : Lógica Exclusiva O
 ============================================================================
 */
#include <math.h> 
#include "mpi.h" 
#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int size, rank, comparacion;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int root_rank = 0;
    comparacion=rank*2;
    bool valor = comparacion;
    bool reduction_result = false;

    MPI_Reduce(&valor, &reduction_result, 1, MPI_C_BOOL, MPI_LOR, root_rank, MPI_COMM_WORLD);

    if(rank == root_rank)
    {
        printf("La lógica de los valores es %s.\n", reduction_result ? "verdadero" : "falso");
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}

