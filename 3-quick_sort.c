#include "sort.h"

/**
 * swap - Swaps two elements
 * @a: pointer to the first elements to be swapped
 * @b: pointer to the second elements to be swapped
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
	while (j <= high)
	{
		if (array[j] < pivot)
		{
			/* Swap */
			swap(&array[i], &array[j]);
			
			/* print the array after swap */
			print_array(array, size);
			i++;
		}
		j++;
	}
	/* Swap with pivot */
	swap(&array[i + 1], &array[high]);

	/* Pivot index */
	return (i + 1);
}

/**
 * sort - Helper recursive function to do the sorting
 *
 * @array: The array to be sorted
 * @low: the lower index
 * @high: the higher index
 * @size: the size of the array
 */
void sort(int *array, int low, int high, size_t size)
{
	int pindex;

	pindex = partition(array, low, high, size);

	low = sort(array, low, pindex - 1);
	high = sort(array, high, pindex + 1);
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
	size_t low, high;

	low = sort(array, low, size);
	high = sort(array, high, size);

	if (low < high)
	{
		pindex = parition(arr, low, high);

		quick_sort(array, low);
		quick_sort(arr, high);
	}
}
