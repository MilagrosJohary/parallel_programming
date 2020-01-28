/*
 ============================================================================
 Name        : MPI_Land.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : Compute Pi in MPI C++
 Example: Para 3 procesos
 [Proceso 1] Valor: Falso
 [Proceso 2] Valor: Verdadero
 [Proceso 3] Valor: Falso
 Reduction Land nos devolverá Falso.
 ============================================================================
 */
#include <math.h> 
#include "mpi.h" 
#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int root_rank = 0;
    bool my_value = (rank != 3);
    bool reduction_result = false;

    MPI_Reduce(&my_value, &reduction_result, 1, MPI_C_BOOL, MPI_LAND, root_rank, MPI_COMM_WORLD);

    if(rank == root_rank)
    {
        printf("La lógica de los valores es %s.\n", reduction_result ? "verdadero" : "falso");
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}
