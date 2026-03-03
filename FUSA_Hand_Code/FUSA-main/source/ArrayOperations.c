/**
 * @file complex_operations.c
 *
 * @brief Complex Data Manipulation and Computational Logic Framework
 *
 * This file implements a variety of operations that perform:
 *  - Conditional logic based on external input variables
 *  - Arithmetic processing via stub function pointers
 *  - Sorting and transformation of arrays
 *  - Construction and computation using 2D matrices
 *  - Memory management and pointer manipulation
 *
 * ## Key Features:
 * 1. **Global Variables:**
 *    - Various fixed-size arrays (`primaryArray`, `secondaryArray`, `extendedArray`, etc.)
 *    - 2D matrices for advanced data combinations and operations
 *    - Totals and computed variables used to store intermediate and final results
 *    - Function pointer `handleEvent_func` for dynamic arithmetic operation dispatch
 *
 * 2. **Arithmetic Functions:**
 *    - `sumValues()`, `subtractValues()`, and `multiplyValues()` perform operations using constants.
 *    - Stub equivalents (e.g., `sumValues_stu#include "globals.h"
..)`:**
 *    - Executes a multi-level decision tree using `externalVarOne` to `externalVarFour`
 *    - Applies:
 *       - Function pointer logic based on conditions
 *       - Array updates for `primaryArray` and `secondaryArray`
 *       - Various sorting algorithms: insertion sort, bubble sort
 *       - Array merging and dual-mode sorting (ascending and descending)
 *    - Computes totals and aggregates into arrays
 *    - Builds `combinedData_One` and `combinedData_Two` 2D matrices from various sources
 *    - Performs matrix operations: addition, subtraction, and multiplication
 *    - Allocates and flattens 2D matrices into 1D dynamic arrays
 *    - Converts all negative values in subtraction results to positive
 *
 * 4. **Memory Handling:**
 *    - Uses `calloc()` and `free()` to manage intermediate buffer arrays
 *
 * 5. **Helper Functions:**
 *    - `evaluateExternalVarCondition()` returns boolean based on global variable condition
 *    - Arithmetic helpers return computed results based on predefined constants
 *
 */
#include <stddef.h>
#include<stdlib.h>
#include "miscellaneous_tasks_def.h"
#include "ArrayOperations.h"

// Define global variables here
int16_t externalVarOne = 0;
uint32_t externalVarTwo = 0;
uint8_t externalVarThree = 0;
int16_t externalVarFour = 0;

uint8_t g_incrementCounter = 0;
int g_computedTotal = 0;

int primaryArray[NUM_ELEMENTS] = {0};
int secondaryArray[NUM_ELEMENTS] = {0};
int extendedArray[MAX_ARRAY_SIZE] = {0};

int AssendingextendedArray[MAX_ARRAY_SIZE];
int DecendingextendedArray[MAX_ARRAY_SIZE];
int TemporaryArray[MAX_ARRAY_SIZE];

// 2D Arrays
int combinedData_One[NUM_ELEMENTS][NUM_ELEMENTS];
int combinedData_Two[NUM_ELEMENTS][NUM_ELEMENTS];
int combinedData_ADDITION[NUM_ELEMENTS][NUM_ELEMENTS];
int combinedData_SUBTRACTION[NUM_ELEMENTS][NUM_ELEMENTS];
int combinedData_MULTIPLICATION[NUM_ELEMENTS][NUM_ELEMENTS];

int g_computedTotal_primaryArray;
int g_computedTotal_secondaryArray;
int g_computed_GRAND_total;

int (*handleEvent_func)(int);

/**
 * @brief Evaluates whether the external variable `externalVarOne` is equal to zero.
 *
 * @return bool Returns `true` if `externalVarOne == 0`, otherwise `false`.
 */
bool evaluateExternalVarCondition()
{
	bool l_evaluateExternalVarCondition_Var=0;
	
	if(externalVarOne==0)
	l_evaluateExternalVarCondition_Var=1;

	return l_evaluateExternalVarCondition_Var;
}

/**
 * @brief Calculates the sum of a given value and two predefined constants.
 *
 * @param l_sumValues_Var The input integer value to be added.
 *
 * @return int The result of (l_sumValues_Var + CONST_A + CONST_B).
 */
int sumValues(int l_sumValues_Var)
{
	return (l_sumValues_Var + CONST_A + CONST_B);
}

/**
 * @brief Computes the result of adding a value to the difference of two constants.
 *
 * @param l_subtractValues_Var The input integer value to be added.
 *
 * @return int The result of (l_subtractValues_Var + (CONST_A - CONST_B)).
 */
int subtractValues(int l_subtractValues_Var)
{
	return (l_subtractValues_Var + (CONST_A - CONST_B));
}

/**
 * @brief Multiplies the input value with a predefined constant.
 *
 * @param l_multiplyValues_Var The input integer to be multiplied.
 *
 * @return int The result of (l_multiplyValues_Var * CONST_B).
 */
int multiplyValues(int l_multiplyValues_Var)
{
	return (l_multiplyValues_Var * CONST_B);
}

/**
 * @brief Determines the computational complexity by evaluating and transforming input variables.
 *
 * @param externalVarOne   Signed 16-bit integer input used for comparisons.
 * @param externalVarTwo   Unsigned 32-bit integer input used for control flow and validation.
 * @param externalVarThree Unsigned 8-bit integer input involved in comparison and processing.
 * @param externalVarFour  Signed 16-bit integer input used in multi-level decision trees.
 *
 * @return None
 */
void determineComplexity(int16_t externalVarOne, uint32_t externalVarTwo, uint8_t externalVarThree, int16_t externalVarFour)
{

	//local Structure decleration
	MyStruct l_Mystruct;
	l_Mystruct.StructVar1=0;
	l_Mystruct.StructVar2=0;


	int i,j,k,l_temp;
	uint8_t l_tempVariable;
	
	if(externalVarOne < externalVarTwo)                  
	{  
		l_tempVariable = enum_FIVE;
		handleEvent_func = sumValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = multiplyValues_stub;
      secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}
	else
	{
		l_tempVariable = enum_TWO;
		handleEvent_func = subtractValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = multiplyValues_stub;
      secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}


	g_incrementCounter+=1;
	if(externalVarTwo == CONST_ZERO) 
	{
		l_tempVariable = enum_SEVEN;
		handleEvent_func = sumValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = sumValues_stub;
      secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}
	else
	{
		l_tempVariable = enum_TWO;
		handleEvent_func =  sumValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = multiplyValues_stub;
      secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}


	if(evaluateExternalVarCondition_stub())
	{
		l_tempVariable = enum_EIGHT;
		handleEvent_func = subtractValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = sumValues_stub;
	secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}
	else
	{
		l_tempVariable = enum_ONE;
		handleEvent_func = sumValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = multiplyValues_stub;
	secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}

	if (externalVarOne < externalVarFour)                             
	{
		if (externalVarTwo > externalVarOne)                                             
		{
			if (externalVarTwo == CONST_ZERO)                                
			{
				if (externalVarFour ==  externalVarThree)                      
				{
						l_tempVariable = enum_EIGHT;
						handleEvent_func = multiplyValues_stub;
						primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
						handleEvent_func = multiplyValues_stub;
					secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
				}
				else
				{
						l_tempVariable = enum_THREE;
						handleEvent_func = multiplyValues_stub;
						primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
						handleEvent_func = sumValues_stub;
					secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
				}
			}
			else if(externalVarOne == externalVarThree)                 
			{
				if(externalVarOne < externalVarTwo)     
				{
					l_tempVariable = enum_FIVE;
					handleEvent_func = multiplyValues_stub;
					primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
					handleEvent_func = subtractValues_stub;
				secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
				}
				else
				{
					l_tempVariable = enum_THREE;
					handleEvent_func = subtractValues_stub;
					primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
					handleEvent_func = multiplyValues_stub;
				secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);;
				}
			}
			else
			{
				l_tempVariable = enum_EIGHT;
				handleEvent_func = sumValues_stub;
				primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
				handleEvent_func = subtractValues_stub;
			secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
			}
		}
	}

	g_incrementCounter+=1;
	if(externalVarFour)
	{
		l_tempVariable = enum_FOUR;
		handleEvent_func = subtractValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = sumValues_stub;
	secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}
	else
	{
		l_tempVariable = enum_SEVEN;
		handleEvent_func = sumValues_stub;
		primaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
		handleEvent_func = subtractValues_stub;
	secondaryArray[g_incrementCounter] = handleEvent_func(l_tempVariable);
	}
	//insertion Sort
	//Sorted Primaray Array
	for (i = 0; i < NUM_ELEMENTS; i++)
	{
		l_temp = primaryArray[i];
		j = i - 1;
		while (j >= 0 && primaryArray[j] > l_temp) 
		{
			primaryArray[j + 1] = primaryArray[j];
			j--;
		}
		primaryArray[j + 1] = l_temp;
	}
	//Bubble Sort
	//Sorted Secondary Array   
	for (i = 0; i <  NUM_ELEMENTS- 1; i++)
	{
		for (j = 0; j < NUM_ELEMENTS - 1 - i; j++)
		{
			if (secondaryArray[j] < secondaryArray[j +1])
			{
				l_temp = secondaryArray[j];
				secondaryArray[j] = secondaryArray[j + 1];
				secondaryArray[j + 1] = l_temp;
			}
		}
	}
	//Merging Primary Array and Secondaray
	//extendedArray is Updated
	for(i=0;i<MAX_ARRAY_SIZE;i++)
	{
		if(i < NUM_ELEMENTS)
	extendedArray[i]=primaryArray[i];
		else
		{
			extendedArray[i]=secondaryArray[j];
			j++;
		}
	}
	//Bubble Sort
	//Sorting Extended Array assending order
	for (i = 0; i <  MAX_ARRAY_SIZE- 1; i++)
	{
		for (j = 0; j < MAX_ARRAY_SIZE - 1 - i; j++)
		{
			if (extendedArray[j] > extendedArray[j +1])
			{
				l_temp = extendedArray[j];
				extendedArray[j] = extendedArray[j + 1];
				extendedArray[j + 1] = l_temp;
			}
		}
	}	
		
	//Updateding AssendingextendedArray
	for(i=0;i< MAX_ARRAY_SIZE;i++)
	AssendingextendedArray[i]=extendedArray[i];
	
	//insertion Sort
	//Sorting Extended Array decending order
	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		l_temp = extendedArray[i];
		j = i - 1;
		while (j >= 0 && extendedArray[j] < l_temp) 
		{
			extendedArray[j + 1] = extendedArray[j];
			j--;
		}
		extendedArray[j + 1] = l_temp;
	}

	//Updating DecendingextendedArray	
	for(i=0;i< MAX_ARRAY_SIZE;i++)
	DecendingextendedArray[i]=extendedArray[i];

	j=0;
	for(i=0;i<NUM_ELEMENTS;i++)
	g_computedTotal_primaryArray += primaryArray[i];
	TemporaryArray[j]=g_computedTotal_primaryArray;
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	g_computedTotal_secondaryArray += secondaryArray[i];
	TemporaryArray[j]=g_computedTotal_secondaryArray;
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	l_Mystruct.StructVar1 += DecendingextendedArray[i];
	TemporaryArray[j]=l_Mystruct.StructVar1;
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	l_Mystruct.StructVar2 += AssendingextendedArray[i];
	TemporaryArray[j]=l_Mystruct.StructVar2;
	j++;

	g_computed_GRAND_total+=g_computedTotal_primaryArray+g_computedTotal_secondaryArray+l_Mystruct.StructVar1+l_Mystruct.StructVar2;
	TemporaryArray[j]=g_computed_GRAND_total;

	//creation of combinedData_One (2D array)
	j=0;
	for(i=0;i<NUM_ELEMENTS;i++)
	{
	combinedData_One[j][i]=primaryArray[i];
	j++;
	}
	
	for(i=0;i<NUM_ELEMENTS;i++)
	{
	combinedData_One[j][i]=secondaryArray[i];
	j++;
	}
	
	for(i=0;i<NUM_ELEMENTS;i++)
	combinedData_One[j][i]=DecendingextendedArray[i];
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	combinedData_One[j][i]=AssendingextendedArray[i];
	j++;

	for(i=0;i<NUM_ELEMENTS;i++){
		combinedData_One[j][i]=TemporaryArray[i];
	}
	
	//creation of combinedData_Two (2D array)
	j=0;
	for(i=0;i<NUM_ELEMENTS;i++)
	combinedData_Two[j][i]=DecendingextendedArray[i];
	j++;
	

	for(i=0;i<NUM_ELEMENTS;i++)
	combinedData_Two[j][i]=AssendingextendedArray[i];
	j++;;


	for(i=0;i<NUM_ELEMENTS;i++)
	combinedData_Two[j][i]=TemporaryArray[i];
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	{

	}
	combinedData_Two[j][i]=secondaryArray[i];
	j++;

	for(i=0;i<NUM_ELEMENTS;i++)
	{
		combinedData_Two[j][i]=primaryArray[i];
	}

	//ADDTION of 2 2D ARRAY
	for(i=0;i<NUM_ELEMENTS;i++)
	{
		for(j=0;j<NUM_ELEMENTS;j++)
		combinedData_ADDITION[i][j] = combinedData_One[i][j] + combinedData_Two[i][j];
	}

	//SUBTRACTION of 2 2D ARRAY
	for(i=0;i<NUM_ELEMENTS;i++)
	{
		for(j=0;j<NUM_ELEMENTS;j++)
		combinedData_SUBTRACTION[i][j] = combinedData_One[i][j] - combinedData_Two[i][j];
	}

		//Multiplication of 2 2D ARRAY
	for (i = 0; i <NUM_ELEMENTS; i++) 
	{
			for (j = 0; j < NUM_ELEMENTS; j++) 
			{
			for (k = 0; k < NUM_ELEMENTS; k++) 
				{
				combinedData_MULTIPLICATION[i][j] += combinedData_One[i][k] * combinedData_Two[k][j];
			}
		}
	}

	g_computedTotal_primaryArray=0;

	int *Array_ADDTION = (int*)calloc(NUM_ELEMENTS*NUM_ELEMENTS,sizeof(int));
	if (Array_ADDTION == NULL) 
	{
	exit(0);  // Exit or handle the error as appropriate
	}
	int *Array_SUBSTRACTION = (int*)calloc(NUM_ELEMENTS*NUM_ELEMENTS,sizeof(int));
	if (Array_SUBSTRACTION == NULL) 
	{
	exit(0) ;
	}

	int *Addtion_Pointer = &combinedData_ADDITION[0][0];	

	//Traversing and pushing all the 2D arrays to a 1D array!
	for(i=0,k=0;i<NUM_ELEMENTS;i++)
	for(j=0;j<NUM_ELEMENTS;j++,k++)
	Array_ADDTION[k]=*(Addtion_Pointer + i *NUM_ELEMENTS+j);
	

	//Adding the elements from 1D array and updating g_computedTotal
	for(i=0;i<NUM_ELEMENTS*NUM_ELEMENTS;i++)
	g_computedTotal_primaryArray += *(Array_ADDTION+i);

	
	//Making all the negative number's to postive Number;
	for(i=0,k=0;i<NUM_ELEMENTS;i++)
	{
		for(j=0;j<NUM_ELEMENTS;j++)
		{
			if(combinedData_SUBTRACTION[i][j] <= 0)
				combinedData_SUBTRACTION[i][j] *=(-1); 
		}
	}

	free(Array_ADDTION);
	free(Array_SUBSTRACTION);
}