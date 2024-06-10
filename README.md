## Multithreaded Sorting Application (Starter Code is on the bottom)

Names: Elizabeth Fassler (6336712), Khalid Fatani (6363026), and Asja Jennings

Operating Systems Principles

Programming Assignment 2

1245-FIU01-COP-4610-SECRVDC-52544

Professor Kiavash Bahreini

-------------------------------------------------------------------------------------------------------------
Elizabeth Fassler: Created team project repository and readme file on Github
-------------------------------------------------------------------------------------------------------------
Khalid Fatani: Added the basic pseudocode to the github project
-------------------------------------------------------------------------------------------------------------



Write a multithreaded sorting program in C that works as follows: A list of integers is divided into two smaller lists of equal size. Two separate threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged by a third thread—a merging thread—which merges the two sublists into a single sorted list.

Because global data are shared across all threads, perhaps the easiest way to set up the data is to create a global array. Each sorting thread will work on one-half of this array. A second global array of the same size as the unsorted integer array will also be established. The merging thread will then merge the two sublists into this second array. Graphically, this program is structured as in the figure below.

Figure 1: Multithreaded Sorting.

![69d5e8c4-4ca7-4e46-a1e1-4ccf80639ecc](https://github.com/Operating-Systems-Group/Multithreaded-Sorting-Application/assets/128157075/403d8a27-c6eb-41ce-a420-19480d7cdcd6)

This programming project will require passing parameters to each of the sorting threads. In particular, it will be necessary to identify the starting index from which each thread is to begin sorting. Refer to the instructions in Project 1 for details on passing parameters to a thread.
Once all sorting threads have exited, the parent thread will output the sorted array.

### Notes

- Create your application using the C programming language on the FIU Ocelot server for the UNIX operating system.
- Create a short video of a maximum of 6 minutes of your running application and source codes.
- Create a text or Word file called Instructions.txt and write down the steps to run your application (your source codes should be error-free).
- Add the recorded video file, the text/Word files, and your project, including the source codes, Makefile, etc., into a zip file.
- Upload the zip file to Canvas before the deadline.




### Code
/******************************************************************************
Basic pseudocode:

Declare two global int arrays "unsorted" and "sorted".
Create two sorting threads each with their own function "sort1" and "sort2".
Create a merging thread with its own function "merge".

In the main function: 
Fill unsorted array with random integers (can be hardcoded to have a full array).
Call both sorting functions, passing the global unsorted array, they will each return with a shorter sorted array.
Call the merging function, passing the two sorted arrays to be put into the global sorted array.
Output the sorted array to the console.
*******************************************************************************/

#include <stdio.h>
#include <pthread.h>

//declaring global arrays
int unsorted[] = {6, 2, 0, 3, 8, 1, 7, 5, 9, 4};
int sorted[10];


int* sort1(int* array){
    
}

int* sort2(int* array){
    
}

int* merge(int* array1, int* array2 /*<-- these will be replaced by a struct parameter*/){
    
}


int main()
{
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

