# Normal Sort

Efficient Sorting of Normal Data Sets

This sorting algorithm is designed to be used with datasets that have a large number of small numbers that are fairly normal (i.e. the data is symmetrical and unimodal). It works by making two passes over the data, in which it computes the mean and the standard deviation. Then, it places the data points in their approximate locations in the sorted array via their computed Z-score, and finally the array is sorted with a pass of insertion sort. 

In fact, with very large datasets, we could "sample" the data to compute the sample mean and standard deviation, and apply this to sort the dataset. 
