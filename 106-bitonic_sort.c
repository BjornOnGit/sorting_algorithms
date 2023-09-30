#include "sort.h"

/**
 * swap - swaps 2 int values
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}

/**
 * bitonic_compare - compares bitonically
 * @top: true if UP sorting
 * @array: the array pointer
 * @start: the start index
 * @bottom: the stop index
 */
void bitonic_compare(int top, int *array, size_t start, size_t bottom)
{
	size_t half = (bottom - start + 1) / 2, i;

	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == top)
			swap(&array[i], &array[i + half]);
}

/**
 * bitonic_merge - merges bitonically
 * @top: true if UP sorting
 * @array: the array pointer
 * @start: the start index
 * @bottom: the stop index
 */
void bitonic_merge(int top, int *array, size_t start, size_t bottom)
{
	size_t mid = (start + bottom) / 2;

	if (bottom - start < 1)
		return;
	bitonic_compare(top, array, start, bottom);
	bitonic_merge(top, array, start, mid);
	bitonic_merge(top, array, mid + 1, bottom);
}

/**
 * _bitonic_sort - sorts bitonically by recursion
 * @top: true if UP sorting
 * @array: the array pointer
 * @size: the length of the array
 * @start: the start index
 * @bottom: the stop index
 */
void _bitonic_sort(int top, int *array, size_t size, size_t start, size_t bottom)
{
	size_t mid = (start + bottom) / 2;

	if (bottom - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", bottom - start + 1, size,
		top ? "UP" : "DOWN");
	print_array(array + start, bottom - start + 1);
	_bitonic_sort(1, array, size, start, mid);
	_bitonic_sort(0, array, size, mid + 1, bottom);
	bitonic_merge(top, array, start, bottom);
	printf("Result [%lu/%lu] (%s):\n", bottom - start + 1, size,
		top ? "UP" : "DOWN");
	print_array(array + start, bottom - start + 1);
}

/**
 * bitonic_sort - sorts bitonically
 * @array: the array pointer
 * @size: the length of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}
