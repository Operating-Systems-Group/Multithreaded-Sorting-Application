#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define SIZE				10
#define NUMBER_OF_THREADS	3

void *sorter(void *params);	/* thread that performs basic sorting algorithm */
void *merger(void *params);	/* thread that performs merging of results */

int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};

int result[SIZE];

int* sort1(int* array) {
    
}

int* sort2(int* array) {
    
}

int* merge(int* array1, int* array2 /*<-- these will be replaced by a struct parameter*/) {
    
}

int main() {
    //creating separate threads for sorting and merging
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    
    //creating threads and calling functions that each sort have of the array 
    pthread_create(&thread1, NULL, sort1, &unsorted);
    pthread_create(&thread2, NULL, sort1, &unsorted);
    
    //joining the sorting threads to ensure array is fully sorted before merge thread is used
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    //creating merge thread and calling its function
    pthread_create(&thread3, NULL, merge, /*since this function has two parameters, a struct will be needed and passed here*/);

    //joining the merge thread
    pthread_join(thread3, NULL);
    
    //printing the sorted array
    printf("The sorted array:\n");
    
    for (int i =0; i < 10; i++){
        printf("%d ", sorted[i]);
    }
    
    return 0;
}


