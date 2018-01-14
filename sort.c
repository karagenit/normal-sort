#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R_SAMPLES 1000
#define R_MAX 1000
#define ELEMS 100 //make 10k

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int generateNormal()
{
    int sum = 0;
    for (int i = 0; i < R_SAMPLES; i++)
    {
        sum += rand() % R_MAX;
    }
    return sum / R_SAMPLES;
}

void fillGaussian(int arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        arr[i] = generateNormal();
    }
}

void main()
{
    int arr[ELEMS];
    fillGaussian(arr, ELEMS);
    insertionSort(arr, ELEMS);

    for (int i = 0; i < ELEMS; i++)
    {
        printf("%d\n", arr[i]);
    }
}
