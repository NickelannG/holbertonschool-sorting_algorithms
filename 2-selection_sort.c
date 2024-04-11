#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * selection sort alogirthm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_indx;
	int temp;

	while (i < size - 1) /* loop through array */
	{
		min_indx = i;
		j = i + 1;
		while (j < size) /* find the minimum element */
		{
			if (array[j] < array[min_indx])
			{
				min_indx = j;
			}
			j++;
		}
		if (min_indx != i)
		{
			/* Swap the min element with the first element */
			temp = array[i];
			array[i] = array[min_indx];
			array[min_indx] = temp;

			print_array(array, size);
		}
		i++;
	}
}
