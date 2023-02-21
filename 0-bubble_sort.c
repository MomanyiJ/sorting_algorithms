#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm in ascending order
 * @array: the array of integers
 * @size: the size of the array
 * Description: You’re expected to print the array
 * after each time you swap two elements
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp, flag;
	size_t i, j;

	if (size > 1)
	{
		/*loop to access each element of array*/
		for (i = 0; i < size - 1; i++)
		{
			flag = 0;
			/*loop to compare elements of the array*/
			for (j = 0; j < size - i - 1; j++)
			{
				/*comparing two adjacent elements of the array*/
				if (array[j] > array[j + 1])
				{
					/*Swap*/
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					/*Increment flag if swaping happens*/
					flag++;
					/*printing after each swap*/
					print_array(array, size);
				}
			}
			if (flag == 0)
				break;
		}
	}
}
