#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdint.h>
#include <stdbool.h>

// Constants
#define PRE_LIMIT 10
#define POST_LIMIT 20

void operation_function_pointer(uint8_t f_input);

// Global variables
extern uint8_t g_limit_value; // 0........255   
extern int g_result_value;      
extern int g_cond_a, g_cond_b, g_operand1, g_operand2; 

// Function declarations

// int calculate_modulus_square(int f_value);
// int add(int f_var1, int f_var2);
// int subtract(int f_var1, int f_var2);
// int multiply(int f_var1, int f_var2);
// int divide(int f_var1, int f_var2);


#endif // OPERATIONS_H
