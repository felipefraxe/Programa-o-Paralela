#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 7
#define NUM_THREADS 12

int **mat1, **mat2, **res;

typedef struct
{
    int start_row;
    int end_row;
}
ThreadData;


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


void *multiply_matrix_part(void *arg)
{
    ThreadData *data = (ThreadData *) arg;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for(int i = start_row; i < end_row; i++)
    {
        for(int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for(int k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    return NULL;
}

int main(void)
{
    mat1 = gen_matrix();
    populate_matrix(mat1, 42);
    
    mat2 = gen_matrix();
    populate_matrix(mat2, 12);
    
    res = gen_matrix();

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int rows_per_thread = N / NUM_THREADS;

    clock_t t = clock();

    for(int i = 0; i < NUM_THREADS; i++)
    {
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = i == NUM_THREADS - 1 ? N : (i + 1) * rows_per_thread;
        pthread_create(&threads[i], NULL, multiply_matrix_part, &thread_data[i]);
    }

    t = clock() - t;

    for(int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
    printf("Tempo de execução %lf segundos\n", (double) t / CLOCKS_PER_SEC);

    // print_matrix(mat1);
    // print_matrix(mat2);
    print_matrix(res);

    return 0;
}
