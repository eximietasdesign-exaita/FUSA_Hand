#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mem_allocation.h"

/*Adds corresponding elements of two integer arrays and returns the resulting array.
 This function takes two integer arrays `f_array1` and `f_array2` along with their size `f_size`,
 and returns a new dynamically allocated array where each element is the sum of the corresponding
 elements from the input arrays. The function allocates memory
*/
int* add_arrays(int* f_array1, int* f_array2, int f_size) 
{
    int* l_result = (int*)malloc(f_size * sizeof(int));
    // Add corresponding elements of the two arrays
    for (int i = 0; i < f_size; i++)
	{
        l_result[i] = f_array1[i] + f_array2[i];
			
    }
    return l_result;
}