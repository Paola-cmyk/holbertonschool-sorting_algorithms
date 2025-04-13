#include "sort.h"

/**
 * swap_ints - swaps two intergerd in an array
 * @a: first interger
 * @b: second interger
 */

void swap_ints(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - partitions the array using lomuto scheme
 * @array: array to partition
 * @low: starting index of partition
 * @high: ending index of the partition
 * @size: size of the full array for printing
 *
 * Return: the index of the pivot after partition
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - recursively sorts partitions of the array
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of intergers in ascending order
 * @array array to be sorted
 * @size: number of elements in the array
 */

void quick_sort(int *array,  size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_recursive(array, 0, size - 1, size);
}
