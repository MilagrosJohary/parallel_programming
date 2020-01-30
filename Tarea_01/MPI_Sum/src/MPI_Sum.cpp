/*
 ============================================================================
 Name        : MPI_Sum.c
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
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    float cuadrado=my_rank*10;
    float suma= cuadrado+1.5;

    MPI_Reduce(&my_rank,&suma,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

    if (my_rank == 0){
    	printf("La suma es %d.\n", suma);
    }

    MPI_Finalize();

    return 0;
}
