#include "sort.h"

/**
 * quick_sort - quick sort with Lomuto partition scheme
 * @array: the array
 * @size: array size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = size - 1;

	if (array != NULL || size > 1)
		sort_array(array, size, i, j);

}
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
 * divide - partitions the array
 * @array: the array
 * @size: size of array
 * @first: low value
 * @last: high value
 * Return: point of partition
 */
int divide(int *array, size_t size, int first, int last)
{
	int pivot, index, j;

	/*last element as pivot*/
	pivot = array[last];
	/*pointer to temporary index*/
	index = first - 1;
	/*loop to compare elements to pivot*/
	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			/*move temporary index forward*/
			index++;
			/*swap element at j with element pointed by index*/
			swap(&array[index], &array[j]);
			if (index != j)
				print_array(array, size);
		}
	}
	/*swap pivot element with greater element at index*/
	swap(&array[index + 1], &array[last]);
	if (index + 1 != j)
		print_array(array, size);

	/*return point of partition*/
	return (index + 1);
}
/**
 * sort_array - quick sort recursive calls
 * @array: the array
 * @size: array size
 * @first: low value
 * @last: high value
 * Return: nothing
 */
void sort_array(int *array, size_t size, int first, int last)
{
	int partition;


	if (first < last)
	{
		/*position pivot element with elements to the right and left*/
		partition = divide(array, size, first, last);

		/*recursively call function to repeat steps to right and left*/
		sort_array(array, size, first, partition - 1);
		sort_array(array, size, partition + 1, last);
	}
}
