// operations.c

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "miscellaneous_tasks_def.h"
// Global Variables
// int primaryArray[NUM_ELEMENTS];
// int secondaryArray[NUM_ELEMENTS];
// int extendedArray[MAX_ARRAY_SIZE];
// uint8_t g_incrementCounter = 0;
// int g_computedTotal = 0;
static void InsertionSort(int *f_insertion_array);
static void InsertionSort(int *f_insertion_array);
static void performExternalOperationOne();
static void performExternalOperationTwo();
static void performExternalOperationThree();
static void performExternalOperationFour();
static void performExternalOperationFive();
static int subtractValues(int l_subtractValues_Var);
static int sumValues(int l_sumValues_Var);
static int multiplyValues(int l_multiplyValues_Var);
static int Check_Sum_Of_Merged_Array(int *f_arr);
static void BubbleSort(int *f_bubble_array);
static bool evaluateExternalVarCondition();
static void Merge_Two_Arrays();
// External Variables
// int16_t externalVarOne = 0;
// uint32_t externalVarTwo = 0;
// uint8_t externalVarThree = 0;
// int16_t externalVarFour = 0;
int g_primaryArray[10];    
int g_secondaryArray[10]; 

void AllMiscellaneous_Tasks_DefMakeStatic()
{
   

    performExternalOperationOne();
    performExternalOperationTwo();
    performExternalOperationThree();
    performExternalOperationFour();
    performExternalOperationFive();
    InsertionSort(g_primaryArray);
    BubbleSort(g_secondaryArray);
    Merge_Two_Arrays();
    
}
// Function Definitions
static int sumValues(int l_sumValues_Var) {
    return (l_sumValues_Var + CONST_A + CONST_B);
}

static int subtractValues(int l_subtractValues_Var) {
    return (l_subtractValues_Var + (CONST_A - CONST_B));
}

static int multiplyValues(int l_multiplyValues_Var) {
    return (l_multiplyValues_Var * CONST_B);
}

static void InsertionSort(int *f_insertion_array) {
    int i, j, l_temp;
    for (i = 0; i < NUM_ELEMENTS; i++) {
        l_temp = *(f_insertion_array + i);
        j = i - 1;
        while (j >= 0 && f_insertion_array[j] > l_temp) {
            (f_insertion_array)[j + 1] = f_insertion_array[j];
            j--;
        }
        f_insertion_array[j + 1] = l_temp;
    }
}

static void BubbleSort(int *f_bubble_array) {
    int i, j, l_temp;
    for (i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
        for (j = 0; j < MAX_ARRAY_SIZE - 1 - i; j++) {
            if (*(f_bubble_array + j) > *(f_bubble_array + j + 1)) {
                l_temp = *(f_bubble_array + j);
                *(f_bubble_array + j) = *(f_bubble_array + j + 1);
                *(f_bubble_array + j + 1) = l_temp;
            }
        }
    }
}

static bool evaluateExternalVarCondition() {
   bool l_evaluateExternalVarCondition_Var=0;
	
	if(externalVarOne==0)
	l_evaluateExternalVarCondition_Var=1;

	return l_evaluateExternalVarCondition_Var;
}

static void performExternalOperationOne(void) {
    uint8_t l_tempVariable;
    g_incrementCounter++;
    if (externalVarOne < externalVarTwo) {
        l_tempVariable = enum_FIVE;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
    } else {
        l_tempVariable = enum_TWO;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
    }
}

static void performExternalOperationTwo() {
    uint8_t l_tempVariable;
    g_incrementCounter++;
    if (externalVarTwo == CONST_ZERO) {
        l_tempVariable = enum_SEVEN;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
    } else {
        l_tempVariable = enum_TWO;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
    }
}

static void performExternalOperationThree() {
    uint8_t l_tempVariable;
    g_incrementCounter++;
    if (evaluateExternalVarCondition()) {
        l_tempVariable = enum_EIGHT;
        primaryArray[g_incrementCounter] = subtractValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = sumValues(l_tempVariable);
    } else {
        l_tempVariable = enum_ONE;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
    }
}

static void performExternalOperationFour() {
    uint8_t l_tempVariable;
    g_incrementCounter++;
    if (externalVarOne < externalVarFour) {
        if (externalVarTwo > externalVarOne) {
            if (externalVarTwo == CONST_ZERO) {
                if (externalVarFour == externalVarThree) {
                    l_tempVariable = enum_EIGHT;
                    primaryArray[g_incrementCounter] = subtractValues(l_tempVariable);
                    secondaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
                } else {
                    l_tempVariable = enum_THREE;
                    primaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
                    secondaryArray[g_incrementCounter] = sumValues(l_tempVariable);
                }
            } else {
                l_tempVariable = enum_FIVE;
                primaryArray[g_incrementCounter] = multiplyValues(l_tempVariable);
                secondaryArray[g_incrementCounter] = subtractValues(l_tempVariable);
            }
        }
    }
}

static void performExternalOperationFive() {
    uint8_t l_tempVariable;
    g_incrementCounter++;
    if (externalVarFour) {
        l_tempVariable = enum_FOUR;
        primaryArray[g_incrementCounter] = subtractValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = sumValues(l_tempVariable);
    } else {
        l_tempVariable = enum_SEVEN;
        primaryArray[g_incrementCounter] = sumValues(l_tempVariable);
        secondaryArray[g_incrementCounter] = subtractValues(l_tempVariable);
    }
}

static int Check_Sum_Of_Merged_Array(int *f_arr)
 {
    int l_Sum_Of_Array = 0;
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        l_Sum_Of_Array += *(f_arr + i);
    }
    return l_Sum_Of_Array;
}

static void Merge_Two_Arrays() 
{
    int i, j = 0;
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        if (i < NUM_ELEMENTS)
            extendedArray[i] = primaryArray[i];
        else
            extendedArray[i] = secondaryArray[j++];
    }
    g_computedTotal = Check_Sum_Of_Merged_Array(extendedArray);

}
