#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7


int **gen_matrix()
{
    int **mat = malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++)
        mat[i] = malloc(sizeof(int) * N);
    return mat;
}


void populate_matrix(int **mat, int seed)
{
    srand(seed);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            mat[i][j] = rand() % N;
    }
}


int multiply_matrix(int **mat1, int **mat2, int **res)
{
    clock_t t = clock();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for(int k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return clock() - t;
}


void print_matrix(int **mat)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int **mat1 = gen_matrix();
    populate_matrix(mat1, 42);
    // print_matrix(mat1);

    int **mat2 = gen_matrix();
    populate_matrix(mat2, 12);
    // print_matrix(mat2);

    int **res = gen_matrix();
    clock_t time = multiply_matrix(mat1, mat2, res);

    printf("Tempo de execução %lf segundos\n", (double) time / CLOCKS_PER_SEC);
    print_matrix(res);
}