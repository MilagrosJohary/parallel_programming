/*
 ============================================================================
 Name        : Suma_Vectores.c
 Author      : Mili
 Version     :
 Copyright   : Your copyright notice
 Description : Compute Pi in MPI C++
 ============================================================================
 */
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

#define MASTER 0
#define RECIBE 1
#define SUMA 2


void lVector(int VECTOR[], int MAX);
void imVector(int VECTOR[], int MAX);

int main(int argc, char *argv[])
{
	int rank, size;
	int MAX = atoi(argv[1]);
	int VECTOR__A[MAX], VECTOR__B[MAX];
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == MASTER)
	{

		lVector(VECTOR__A, MAX);
		lVector(VECTOR__B, MAX);
		MPI_Send(VECTOR__A, MAX, MPI_INT, RECIBE, 2, MPI_COMM_WORLD);
		MPI_Send(VECTOR__B, MAX, MPI_INT, RECIBE, 3, MPI_COMM_WORLD);
	}
	else
	{
		if (rank == RECIBE)
		{
			MPI_Recv(VECTOR__A, MAX, MPI_INT, MASTER, 2, MPI_COMM_WORLD, &status);
			MPI_Recv(VECTOR__B, MAX, MPI_INT, MASTER, 3, MPI_COMM_WORLD, &status);
			printf("Vector A\n");
			imVector(VECTOR__A, MAX);
			printf("Vector B\n");
			imVector(VECTOR__B, MAX);
			MPI_Send(VECTOR__A, MAX, MPI_INT, SUMA, 2, MPI_COMM_WORLD);
			MPI_Send(VECTOR__B, MAX, MPI_INT, SUMA, 3, MPI_COMM_WORLD);
		}
		else
		{
			if (rank == SUMA)
			{
				MPI_Recv(VECTOR__A, MAX, MPI_INT, RECIBE, 2, MPI_COMM_WORLD, &status);
				MPI_Recv(VECTOR__B, MAX, MPI_INT, RECIBE, 3, MPI_COMM_WORLD, &status);
				int VECTOR__RES[MAX];
				int i;
				for(i = 0; i < MAX; i++)
				{
					VECTOR__RES[i] = (VECTOR__A[i] + VECTOR__B[i]);
				}
				printf("VECTOR RESULTANTE\n",VECTOR__RES);
				/*imprime__vectores(VECTOR__RES,i);*/
			}
		}
	}
	MPI_Finalize();
	return 0;
}

void lVector(int VECTOR[], int MAX)
{
	srand(time(NULL));
	int i;
	for(i = 0; i < MAX; i++)
	{
		VECTOR[i] = (rand()%150) + 1;
	}
}

void imVector(int VECTOR[], int MAX)
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		printf("%d\n", VECTOR[i]);
	}
}
