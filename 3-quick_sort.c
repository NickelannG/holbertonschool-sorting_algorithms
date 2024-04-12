#include "sort.h"

/**
 * partition - partitions an array of integers
 *
 * @array: the array to be partitioned
 * @high: the higher index of the partition
 * @low: the lower index of the partition
 * @size: the size of the array
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	/* Choosing a pivot - last element */
	pivot = array[high];

	i = (low - 1);

	j = low;
	while (j <= high - 1)
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
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

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
	int pindex, low, high; /* pivot index */
	if (size <= 1)
		return;

	high = size - 1;
	low = 0;
	pindex = partition(array, low, high, size);

	quick_sort(array, pindex - low);
	quick_sort(array +pindex + 1, size - pindex - 1);
}
