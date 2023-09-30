#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * hoare_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 *
 * Return: void
 */
size_t hoare_partition(int *array, ssize_t size, ssize_t low, ssize_t high)
{
	ssize_t i = low - 1, j = high + 1;
	int pivot = array[high];

	while (i < size)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i < j)
			swap(array, size, &array[i], &array[j]);
		else if (i >= j)
			break;
	}
	return (i);
}

/**
 * quicksort - quicksorts via hoare partitioning scheme
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
		size_t p = hoare_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p, high);
	}
}

/**
 * quick_sort_hoare - calls quicksort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
