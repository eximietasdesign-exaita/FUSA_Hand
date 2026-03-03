/**
 * @file function_pointer_operation.c
 *
 * @brief Implements arithmetic operations using function pointers with condition evaluation.
 *
 * This file defines a control logic that:
 * - Selects an arithmetic operation (add, subtract, multiply) using function pointers.
 * - Executes condition checks (`calculate_division`, `calculate_modulus_square`) on the result.
 * - Sets a global limit flag (`g_limit_value`) based on condition evaluations.
 *
 * Key Features:
 * - Demonstrates function pointer usage for arithmetic operations.
 * - Integrates conditional logic to evaluate computation results.
 * - Uses global variables to store intermediate results and flags.
 *
 * Constants:
 * - `PRE_LIMIT` and `POST_LIMIT` are used to flag outcomes.
 * - `g_limit_value`, `g_result_value`, `g_cond_a`, `g_cond_b` are updated globally.
 */

#include <stdio.h>
#include <stdint.h>
#include "functionPointer_operation.h"

//Function Prototype
static int calculate_division(int f_value);
static int calculate_modulus_square(int f_value);
static int add(int f_var1, int f_var2) ;
static int subtract(int f_var1, int f_var2);
static int multiply(int f_var1, int f_var2);
static int divide(int f_var1, int f_var2);

// Global Variables
uint8_t g_limit_value; // 0........255   
int g_result_value;      
int g_cond_a, g_cond_b, g_operand1, g_operand2; 

/**
 * @brief Performs a conditional division operation.
 *
 * @param f_value The input integer to evaluate.
 *
 * @return int The result after conditional division, or 0 if input > 10.
 */
static int  calculate_division(int f_value) 
{    
    if (f_value > 10)
        return 0;
    
    f_value = (f_value + f_value) / 2;   
    return f_value;          
}

/**
 * @brief Calculates the square of the input and returns the result modulo 2.
 *
 * @param f_value The input integer to square and evaluate.
 *
 * @return int f_value.
 */
 static int calculate_modulus_square(int f_value)
{
    f_value = (f_value * f_value) % 2;   
    return f_value;        
}

/**
 * @brief Performs addition of two integer values.
 *
 * @param f_var1 First operand.
 * @param f_var2 Second operand.
 *
 * @return int Sum of f_var1 and f_var2.
 */
 static int add(int f_var1, int f_var2) 
{
    return f_var1 + f_var2;
}

/**
 * @brief Performs subtraction between two integer values.
 *
 * @param f_var1 First operand (minuend).
 * @param f_var2 Second operand (subtrahend).
 *
 * @return int Result of f_var1 - f_var2.
 */
 static int subtract(int f_var1, int f_var2) 
{
    return f_var1 - f_var2;
}

/**
 * @brief Performs multiplication of two integer values.
 *
 * @param f_var1 First operand.
 * @param f_var2 Second operand.
 *
 * @return int Product of f_var1 and f_var2.
 */
static int multiply(int f_var1, int f_var2) 
{
    return f_var1 * f_var2;
}

/**
 * @brief Performs integer division between two values.
 *
 * @param f_var1 Dividend (numerator).
 * @param f_var2 Divisor (denominator).
 *
 * @return int Quotient of f_var1 divided by f_var2.
 */
 static int divide(int f_var1, int f_var2) 
{
    return f_var1 / f_var2;
}

/**
 * @brief Executes an arithmetic operation using function pointers and evaluates result conditions.
 *
 * This function:
 * - Compares the input `f_input` with a threshold (`l_var = 128`).
 * - Based on comparison:
 *     - If `f_input < 128`: performs addition.
 *     - If `f_input > 128`: performs subtraction.
 *     - If `f_input == 128`: performs multiplication.
 * - Stores the operation result in `g_result_value`.
 * - Evaluates two conditions:
 *     - `g_cond_a`: result is divided by 2 only if result ≤ 10.
 *     - `g_cond_b`: square of result modulo 2.
 * - Sets `g_limit_value` to `PRE_LIMIT` if any condition is non-zero, else `POST_LIMIT`.
 *
 * @param f_input A threshold-comparison input to decide arithmetic operation.
 *
 * @return None
 */
void operation_function_pointer(uint8_t f_input)
{
    uint8_t l_var = 128;
    int (*operation_ptr)(int, int);

    // Compare global_input with local_variable and select appropriate operation
    if (f_input < l_var)
    {
        operation_ptr = add;                    
        g_result_value = operation_ptr(g_operand1, g_operand2);  
        g_cond_a = calculate_division(g_result_value);   
        g_cond_b = calculate_modulus_square(g_result_value);   
    }
    else if (f_input > l_var) 
    {
        operation_ptr = subtract;                    
        g_result_value = operation_ptr(g_operand1, g_operand2);  
        g_cond_a = calculate_division(g_result_value);   
        g_cond_b = calculate_modulus_square(g_result_value);     
    }
    else if (f_input == l_var) 
    {
        operation_ptr = multiply;                    
        g_result_value = operation_ptr(g_operand1, g_operand2);  
        g_cond_a = calculate_division(g_result_value);   
        g_cond_b = calculate_modulus_square(g_result_value);   
    }
    else 
    {
        // Dead code block 
        operation_ptr = divide;                    
        g_result_value = operation_ptr(g_operand1, g_operand2);  
        g_cond_a = calculate_division(g_result_value);   
        g_cond_b = calculate_modulus_square(g_result_value);   
    }

    if (g_cond_a || g_cond_b) 
    {                                   
        g_limit_value = PRE_LIMIT;  
    }
    else
    {
        g_limit_value = POST_LIMIT;  
    }
}
