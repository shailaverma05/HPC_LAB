#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    int **A = malloc(n * sizeof(int *));
    int *x = malloc(n * sizeof(int));
    int *y = calloc(n, sizeof(int)); // Initialize result vector to 0

    // Allocate and input matrix A and vector x
    for (int i = 0; i < n; i++)
    {
        A[i] = malloc(n * sizeof(int));
    }

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter vector x:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

// Perform matrix-vector multiplication using OpenMP
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }

    // Print the result vector y
    printf("Result vector y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", y[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
    free(x);
    free(y);

    return 0;
}
