#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;

	while (i < size - 1) /* loop through elements */
	{
		j = 0;
		while (j < size - i - 1) /* loop through adjacent elements */
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print array after every swap */
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
