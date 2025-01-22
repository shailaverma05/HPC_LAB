#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size, data, sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    data = rank + 1; // Assign data as rank + 1
    printf("Process %d has data %d\n", rank, data);

    MPI_Allreduce(&data, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Process %d: Total sum is %d\n", rank, sum);

    MPI_Finalize();
    return 0;
}
