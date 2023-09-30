#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @i: address of first value
 * @j: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *i, int *j)
{
	if (*i != *j)
	{
		*i = *i + *j;
		*j = *i - *j;
		*i = *i - *j;
		print_array((const int *)array, size);
	}
}

/**
 * array_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
size_t array_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int m, n, pivot = array[high];

	for (m = n = low; n < high; n++)
		if (array[n] < pivot)
			swap(array, size, &array[n], &array[m++]);
	swap(array, size, &array[m], &array[high]);

	return (m);
}

/**
 * quicksort - quicksorts via Lomuto partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = array_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
