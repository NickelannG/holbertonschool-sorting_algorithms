#include "sort.h"

/**
 * partition - partitions an array of integers
 *
 * @array: the array to be partitioned
 * @high: the higher index of the partition
 * @low: the lower index of the partition
 * @size: the size of the array
 */
int partition(int *array, int high, int low, size_t size)
{
	int i, j, pivot, temp, temp2;

	/* Choosing a pivot - last element */
	pivot = array[high];

	i = (low - 1);

	j = low;
	while (j <= high)
	{
		if (array[j] < pivot)
		{
			/* Swap */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			
			/* print the array after swap */
			print_array(array, size);
			i++;
		}
		j++;
	}
	/* Swap with pivot */
	temp2 = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp2;

	/* pivot index */
	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the quick sort algorithm
 *
 * @array: the array of integers to be sorted
 * @size: the size of the array 
 *
 */
void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = size - 1;
	int pindex; /* pivot index */

	/* Base Case */
	if (size < 2)
		return;

	while (low < high)
	{
		pindex = partition(array, low, high, size);

		/* Sort lower sub-array */
		quick_sort(array, pindex - low);
		
		/* Update for next iteration */
		low = pindex + 1;
	}
}
