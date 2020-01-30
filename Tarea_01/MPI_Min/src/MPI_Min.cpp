/*
 ============================================================================
 Name        : MPI_Min.c
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

    // Obtener el número de procesos y que sólo sean 10.
    int size;
    printf("Ingrese el número de procesos: ");
    scanf("%d",size);
    if(size != 10)
    {
        printf("Ésta aplicación está diseñada para 10 procesos.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    // Determine el rango de la raiz
    int root_rank = 0;
    // Obtener mi rango
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    // Cada proceso envía su rango a reducción
    int reduction_result = 0;
    MPI_Reduce(&my_rank, &reduction_result, 1, MPI_INT, MPI_MIN, root_rank, MPI_COMM_WORLD);
    if(my_rank == root_rank)
    {
        printf("El mínimo rango es %d.\n", reduction_result);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}

