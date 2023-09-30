#include "sort.h"

/**
 * get_maximum_gap - gets the a largest Knuth Sequence gap for this size
 * @size: the size of the array
 *
 * Return: the gap size
 */
size_t get_maximum_gap(size_t size)
{
	size_t x;

	x = 1;
	while (x < size)
		x = x * 3 + 1;
	return ((x - 1) / 3);
}

/**
 * shell_sort - shell_sort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, a, b;
	int tmp;

	if (!array || !size)
		return;


	for (gp = get_maximum_gap(size); gp; gp = (gp - 1) / 3)
	{
		for (a = gp; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b > gp - 1 && array[b - gp] > tmp; b -= gp)
			{
				array[b] = array[b - gp];
			}
			array[b] = tmp;
		}
		print_array(array, size);
	}
}
