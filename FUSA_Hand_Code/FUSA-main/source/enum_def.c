#include <stdio.h>
#include "enum_def.h"

/**
 * @brief Performs a specified arithmetic operation on two input variables.
 *
 * This function takes an `OperationType` enum value and two floating-point operands,
 * and performs the corresponding arithmetic operation:
 * - **ADDITION**       → `f_var1 + f_var2`
 * - **SUBTRACTION**    → `f_var1 - f_var2`
 * - **MULTIPLICATION** → `f_var1 * f_var2`
 * - **DIVISION**       → `f_var1 / f_var2` (only if `f_var2` is not zero)
 *
 * If division by zero is attempted or an invalid operation type is passed,
 * the function returns `0` as a safe fallback.
 *
 * @param opType The type of arithmetic operation to perform (enum: ADDITION, SUBTRACTION, etc.).
 * @param f_var1 The first operand.
 * @param f_var2 The second operand.
 * @return double The result of the arithmetic operation. Returns 0 in case of invalid operation or division by zero.
 *
 * @note
 * Ensure that `opType` is valid and `f_var2` is non-zero when performing division to avoid default result.
 */

/* fucntion performs a specified arithmetic operation(addition, subtraction, multiplication, or division).*/
double performOperation(OperationType opType, double f_var1, double f_var2) 
{
    double l_result;
switch (opType) 
	{
        case ADDITION:
            l_result = f_var1 + f_var2;
            break;
        case SUBTRACTION:
            l_result = f_var1 - f_var2;
            break;
        case MULTIPLICATION:
            l_result = f_var1 * f_var2;
            break;
        case DIVISION:
            if (f_var2 != 0) 
			{
				l_result = f_var1 / f_var2;
            } 
			else 
			{
              
                l_result = 0;
            }
            break;
			default:
        
            l_result = 0;
            break;
	}
    return l_result;
}
