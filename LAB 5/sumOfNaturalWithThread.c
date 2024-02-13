#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *sum_numbers(void *args)
{
    /* Calculates the sum of numbers from start to end (inclusive) and returns the result as a void pointer. */
    int start = ((int *)args)[0];
    int end = ((int *)args)[1];
    int *result = malloc(sizeof(int));
    *result = 0;
    for (int i = start; i <= end; i++)
    {
        *result += i;
    }
    return (void *)result;
}
int main()
{
    int n, k;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Enter the number of threads: ");
    scanf("%d", &k);
    int chunk_size = n / k;
    pthread_t threads[k];
    int thread_args[k][2];
    int *results[k];
    int total_sum = 0;
    // Create k threads and divide the calculation among them
    for (int i = 0; i < k; i++)
    {
        thread_args[i][0] = i * chunk_size + 1;
        thread_args[i][1] = i < k - 1 ? (i + 1) * chunk_size : n;
        pthread_create(&threads[i], NULL, sum_numbers, (void *)thread_args[i]);
    }
    // Wait for all threads to finish and collect the results
    for (int i = 0; i < k; i++)
    {
        pthread_join(threads[i], (void **)&results[i]);
        total_sum += *results[i];
        free(results[i]);
    }
    printf("The sum of numbers up to %d is %d\n", n, total_sum);
    return 0;
}