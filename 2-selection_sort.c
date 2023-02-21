#include "sort.h"

/**
* swap - swaps two variables
* @i: first params, pointer to size_t
* @j: second params, pointer to size_t
*
* Return: Void
*/
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection sort algorithm
* @array: pointer to int array
* @size: array size
*
* Return: Void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, id_min;

	if (size > 1)
	{
		/*One by one move boundary of unsorted subarray*/
		for (i = 0; i < size - 1; i++)
		{
			/*find the minimum element in unsorted array */
			id_min = i;
			for (j = i + 1; j < size; j++)
			{
				/* if this element is less, then it is the new minimum */
				if (array[j] < array[id_min])
				/* found new minimum; remember its index */
					id_min = j;
			}
			/*swap the found minimum element with first element*/
			if (id_min != i)
			{
				swap(&array[id_min], &array[i]);
				/*printing an array after each sort*/
				print_array(array, size);
			}
		}
	}
}
