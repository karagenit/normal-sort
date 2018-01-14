#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R_SAMPLES 1000
#define R_MAX 1000
#define ELEMS 10000

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

//probability density function, BECAUSE C DOESN'T HAVE THIS
double percentile(int x, double mean, double sd)
{
    return pow(M_E, -(pow(x-mean,2)/(2*sd*sd))) / sqrt(2 * M_PI * sd * sd);
}

//Calculate approximate index of value in a normal dataset
int approxIndex(int val, int size, double mean, double sd)
{
    return percentile(val, mean, sd) * size;
}

double calcMean(int arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

double calcSD(int arr[], int n, double mean)
{
    double ssq = 0;
    for (int i = 0; i < n; i++)
    {
        ssq += pow((arr[i] - mean), 2);
    }
    return sqrt(ssq/n);
}

int *normalSort(int arr[], int n)
{
    int *out = calloc(n, sizeof(int));

    int mean =  calcMean(arr, n);
    int sd = calcSD(arr, n, mean);

    for (int i = 0; i < n; i++)
    {
        int idx;

        //sets idx to the nearest (ish) open slot
        for (idx = approxIndex(arr[i], n, mean, sd); out[idx] != 0; idx++)
        {
            if (idx == n-1)
            {
                for(idx = idx; out[idx] != 0; idx--);
            }
        }

        out[idx] = arr[i];
                
    }

    insertionSort(out, n);
    return out;
}

int generateNormal()
{
    int sum = 0;
    for (int i = 0; i < R_SAMPLES; i++)
    {
        sum += (rand() % R_MAX) + 1;
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

void printArray(int arr[], int n)
{
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void main()
{
    int arr[ELEMS];
    fillGaussian(arr, ELEMS);
    printArray(arr, ELEMS);

    insertionSort(arr, ELEMS);
    printArray(arr, ELEMS);

    fillGaussian(arr, ELEMS);
    int *norm = normalSort(arr, ELEMS);
    printArray(norm, ELEMS);
    free(norm);
}
