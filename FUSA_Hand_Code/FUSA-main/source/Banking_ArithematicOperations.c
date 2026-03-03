#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "switchcase_performing_AO.h"

//Function Prototypes
static void* my_malloc(size_t size);
static void my_free(void* ptr);
static int addition_Function(int f_add1, int f_add2);
static int subtract_Function(int f_sub1, int f_sub2);
static int multiplication_Function(int f_mul1, int f_mul2);
static int division_Function(int f_div1, int f_div2);
static bool logicalAndOr_Function(int f_value1, int f_value2, int f_value3);
static bool conditional_Function(int f_conditional_value1, int f_conditional_value2);

//Global Variables
bool g_result2 = false;
bool g_result1 = false;

//Memory allocation function
static void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        exit(1); 
    }
    return ptr;
}

//Memory deallocation function
static void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL; 
    }
    
}

// Inline function for addition
static int addition_Function(int f_add1, int f_add2) {
    return f_add1 + f_add2;
}

// Inline function for subtraction
static int subtract_Function(int f_sub1, int f_sub2) {
    return f_sub1 - f_sub2;
}

// Inline function for multiplication
static int multiplication_Function(int f_mul1, int f_mul2) {
    return f_mul1 * f_mul2;
}

// Inline function for division with zero check
static int division_Function(int f_div1, int f_div2) {
    if (f_div2 == 0) {
        return 0; // Return 0 to indicate an error; you might want to handle this differently
    }
    return f_div1 / f_div2;
}

// Inline function for logical operations based on given conditions
static bool logicalAndOr_Function(int f_value1, int f_value2, int f_value3) {
	int l_logical_return = 0;
    if ((f_value1 > f_value2 && f_value1 > f_value3) || (f_value2 > f_value1 && f_value2 > f_value3) || (f_value3 > f_value1 && f_value3 > f_value2)) {
        l_logical_return = 1;
    } else if (f_value1 > 20 || f_value2 < 10 || f_value3 == 30) {
        l_logical_return = 1;
    } else {
        l_logical_return = 0;
    }
    return l_logical_return;
}

// Inline function for conditional check with dynamic memory allocation
static bool conditional_Function(int f_conditional_value1, int f_conditional_value2) {
    int* l_localValue = (int*)my_malloc(sizeof(int));
    int l_return_value = 0;
    if (f_conditional_value1 <= 100) {
        *l_localValue = f_conditional_value1 * 2;
        if (f_conditional_value2 == *l_localValue) {
            l_return_value = 1;
        } else {
            l_return_value = 0;
        }
    } else {
        l_return_value = 0;
    }
    my_free(l_localValue);
    return l_return_value;
}

// Function to execute arithmetic operations based on the provided enum value
void switchcase_Function(enum arithmetic_Operations f_operation, int f_operand1, int f_operand2) {
    int* l_result_ptr = (int*)my_malloc(sizeof(int)); 
	
    
	// Perform the operation based on the value of the 'operation' enum
    switch (f_operation) {
        case Addition:
            *l_result_ptr = addition_Function(f_operand1, f_operand2);
            break;
        case Subtraction:
            *l_result_ptr = subtract_Function(f_operand1, f_operand2);
            break;
        case Multiplication:
            *l_result_ptr = multiplication_Function(f_operand1, f_operand2);
            break;
        case Division:
            *l_result_ptr = division_Function(f_operand1, f_operand2);
            break;
        case Conditional:
            g_result2 = conditional_Function(f_operand1, f_operand2);
            // Handle the result of conditional function if needed
            break;
        default:
            *l_result_ptr = 0; // Default result for invalid operation
            break;
    }

    // Check the result of logical operations and call the BankAccountDetails_Function if true
    g_result1 = logicalAndOr_Function(f_operand1, f_operand2, *l_result_ptr);
    if (g_result1) {
        BankAccountDetails_Function(1);
    } else {
        // Retry with the same operation and values
        switchcase_Function(f_operation, f_operand1, f_operand2); // Retry with the same operation
    }

    // Free allocated memory
    my_free(l_result_ptr);
}

