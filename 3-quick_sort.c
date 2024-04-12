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
 *
 * Return: the pivot index after paritioning
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	/* Choosing a pivot - last element */
	pivot = array[high];

	i = (low - 1);

	j = low;
	while (j <= high - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Swap if smaller than pivot */
			swap(&array[i], &array[j]);

			if (array[i] != array[j])
			{
				/* print the array after swap */
				print_array(array, size);
			}
		}
		j++;
	}
	/* Swap with pivot */
	swap(&array[i + 1], &array[high]);

	/* Check if element after pivot is not equal to the pivot */
	if (array[i + 1] != array[high])
	{
		/* print the array after placing pivot in correct position */
		print_array(array, size);
	}
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
	/* pivot index */
	int pindex;

	if (low < high)
	{
		pindex = partition(array, low, high, size);

		/* Sort the lower half */
		sort(array, low, pindex - 1, size);

		/* Sort the higher half */
		sort(array, pindex + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the quick sort algorithm
 *
 * @array: the array of integers to be sorted
 * @size: the size of the array
 *
 * Return: nothing if the array doesn't exist or if the size is 0
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size == 0)
		return;

	low = 0; /* index of first element 0 */
	high = size - 1; /* index of last element */

	sort(array, low, high, size);
}
