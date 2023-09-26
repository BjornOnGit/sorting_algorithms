#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of
 * integers using the bubble sort algorithm.
 *
 * @array: array of integers.
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
  int tez;
  size_t a, b;

 if (!array || !size)
  {
    return;
  }

    a = 0;
    while (a < size)
    {
        for (b = 0; b < size - 1; b++)
        {
            if (array[b] > array[b + 1])
            {
                tez = array[b];
                array[b] = array[b + 1];
                array[b + 1] = tez;
                print_array(array, size);
            }
            
        }
        a++;
    }
    
   
}
