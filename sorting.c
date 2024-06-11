#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define NUMBER_OF_THREADS 3

// Thread performs basic sorting algorithm
void *sorter(void *params);
// Thread performs merging of results
void *merger(void *params);

int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};

int result[SIZE];

typedef struct {
    int from_index;
    int to_index;
} parameters;

int main (int argc, const char * argv[]) {
    pthread_t workers[NUMBER_OF_THREADS];

    // Print unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n");

    // Call malloc to allocate parameters
    parameters *threadParameters = (parameters *) malloc (sizeof(parameters));
    // Use parameters to specify the first half of the array
    threadParameters->from_index = 0;
    threadParameters->to_index = (SIZE/2) - 1;
    // Create the first thread
    pthread_create(&workers[0], 0, sorter, threadParameters);

    // Establish the second sorting thread
    threadParameters = (parameters *) malloc (sizeof(parameters));

    threadParameters->from_index = SIZE/2;
    threadParameters->to_index = SIZE - 1;

    pthread_create(&workers[1], 0, sorter, threadParameters);

    // Wait for 2 sorting threads to finish
    pthread_join(workers[0],NULL);
    pthread_join(workers[1],NULL);

    // Establish the merge thread
    threadParameters->from_index = 0;
    threadParameters->to_index = SIZE/2;

    // Create the third thread (merge thread)
    pthread_create(&workers[2], 0, merger, threadParameters);

    // Wait for the merge thread to finish
    pthread_join(workers[2], NULL);

    // Output the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", result[i]);
    }
    printf("\n");

    return 0;
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Sorting thread
void *sorter(void *params)
{
    parameters* p = (parameters *)params;
    int start = p->from_index;
    int pSize = p->to_index + 1;

    // Finds smallest value and swaps it with the first value
    // in the unsorted part of the thread
    for (int i = start; i < pSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < pSize; j++) {
            if(list[j] < list[min])
                min = j;
        }
        swap(&list[min], &list[i]);
    }
    pthread_exit(0);
}

// Merge thread
void *merger(void *params) {
    parameters* p = (parameters *)params;

    // Merge two sorted sublists to the array result
    int firstHalfOfArray = p->from_index;
    int secondHalfOfArray = p->to_index;
    int i = 0;

    // Iterate through both arrays
    while ((firstHalfOfArray < p->to_index) && (secondHalfOfArray < SIZE)) {
        // Compare the smallest values, insert small in first half if < second half value
        if (list[firstHalfOfArray] < list[secondHalfOfArray]) {
            result[i] = list[firstHalfOfArray];
            ++firstHalfOfArray;
        }

        else {
            result[i] = list[secondHalfOfArray];
            ++secondHalfOfArray;
        }
        ++i;
    }
    // Append last values of first half since they are smaller
    while (firstHalfOfArray < p->to_index) {
        result[i] = list[firstHalfOfArray];
        ++firstHalfOfArray;
        ++i;
    }
    // Append last values of second half since they are smaller
    while (secondHalfOfArray < SIZE) {
        result[i] = list[secondHalfOfArray];
        ++secondHalfOfArray;
        ++i;
    }

    pthread_exit(0);
}


