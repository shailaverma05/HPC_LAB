#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size, mangoes_picked, total_mangoes;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    mangoes_picked = rank + 1; // Example: Robots pick mangoes proportional to their rank
    printf("Robot %d picked %d mangoes\n", rank, mangoes_picked);

    MPI_Reduce(&mangoes_picked, &total_mangoes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total mangoes picked by %d robots: %d\n", size, total_mangoes);
    }

    MPI_Finalize();
    return 0;
}
