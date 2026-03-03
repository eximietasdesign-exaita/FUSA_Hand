#include "data_processing.h"

// Function prototypes
static int computeg_initiall_result(int f_input);

// Global variables
static int g_modifiedInput;
static int g_initiall_result;

/**
 * @brief Computes an adjusted result based on the input value with conditional transformations.
 *
 * This function processes the input integer (`f_input`) and computes an intermediate result (`l_result`)
 * based on a set of range-specific rules. It then further modifies the result based on divisibility
 * by specific numbers (2, 3, 5, and 7).
 *
 * ### Input Range-Based Transformations:
 * - If `f_input` < -100: `l_result = f_input * 3`
 * - If -100 ≤ `f_input` < 0: `l_result = f_input * 2`
 * - If `f_input` == 0: `l_result = 0`
 * - If 1 ≤ `f_input` ≤ 10: `l_result = f_input * f_input`
 * - If 11 ≤ `f_input` ≤ 50: `l_result = f_input + 100`
 * - If 51 ≤ `f_input` ≤ 100: `l_result = f_input - 10`
 * - If 101 ≤ `f_input` ≤ 500:
 *     - If `f_input` > 200: divide by 3
 *     - Else: divide by 2
 * - If `f_input` > 500: `l_result = f_input * 2`
 *
 * ### Post-Processing Based on Divisibility:
 * - If `l_result` is divisible by 2, add 5.
 * - If divisible by 3, subtract 7.
 * - If divisible by 5, multiply by 2.
 * - If divisible by 7, divide by 2.
 *
 * @param f_input The input integer value to be processed.
 * @return int The final adjusted result after applying all conditions.
 *
 * @note This function is static and private to the source file.
 */

#include "data_processing.h"

static int computeg_initiall_result(int f_input) {
    int l_result;

    if (f_input < -100) {
        l_result = f_input * 3;
    } 
  
    else if (f_input < 0) {
        l_result = f_input * 2;
    } 
  
    else if (f_input == 0) {
        l_result = 0;
    } 

    else if (f_input <= 10) {
        l_result = f_input * f_input;
    } 

    else if (f_input <= 50) {
        l_result = f_input + 100;
    } 
  
    else if (f_input <= 100) {
        l_result = f_input - 10;
    } 

    else if (f_input <= 500) {
   
        l_result = (f_input > 200) ? f_input / 3 : f_input / 2;
    } 

    else {
        l_result = f_input * 2;
    }

    if (l_result % 2 == 0) {
        l_result += 5;
    }
    if (l_result % 3 == 0) {
        l_result -= 7;
    }

    if (l_result % 5 == 0) {
        l_result *= 2;
    }

    if (l_result % 7 == 0) {
        l_result /= 2;
    }

    return l_result;
}


/**
 * @brief Applies a series of modifications to a global variable based on switch-case logic and input.
 *
 * This function first computes an initial result using the input `f_input` via the helper function 
 * `computeg_initiall_result()`, and stores it in the global variable `g_initiall_result`.
 * It then modifies the global variable `g_modifiedInput` based on predefined case values using a 
 * `switch-case` structure. Further adjustments are applied using conditional logic to normalize the result.
 *
 * ### Switch-Case Modifications on `g_modifiedInput`:
 * - **CASE_ONE**   : Add 10
 * - **CASE_TWO**   : Multiply by 2
 * - **CASE_THREE** : Subtract 3
 * - **CASE_FOUR**  : Add 404
 * - **CASE_FIVE**  : Divide by 5
 * - **CASE_SIX**   : Modulo 6
 * - **Default**    : Add 100
 *
 * ### Additional Post-Processing on `g_modifiedInput`:
 * - If > 200     → Subtract 100
 * - If < 50      → Add 20
 * - If > 500     → Subtract 50
 * - If < 0:
 *     - If between -1 and -19  → Multiply by -2
 *     - Else                   → Divide by -2
 * - If > 1000    → Cap to 1000
 *
 * @param f_input Input value used to compute the initial result via `computeg_initiall_result()`.
 * @return int The final modified value stored in `g_modifiedInput`.
 *
 * @note 
 * - Assumes `g_modifiedInput` is initialized before the function call.
 * - Uses `g_initiall_result` to store the intermediate result, which may be used elsewhere.
 * - Macro constants such as CASE_ONE, CASE_TWO, etc., must be defined appropriately.
 */


int applySwitchModifications(int f_input) 
{
    g_initiall_result = computeg_initiall_result(f_input);

    switch (g_modifiedInput) {
        case CASE_ONE:
            g_modifiedInput += 10;
            break;

        case CASE_TWO:
            g_modifiedInput *= 2;
            break;

        case CASE_THREE:
            g_modifiedInput -= 3;
            break;

        case CASE_FOUR:
            g_modifiedInput += 404;
            break;

        case CASE_FIVE:
            g_modifiedInput /= 5;
            break;

        case CASE_SIX:
            g_modifiedInput %= 6;
            break;

        default:
        
            g_modifiedInput += 100;
            break;
    }
    if (g_modifiedInput > 200) {
        g_modifiedInput -= 100;
    } 
       else if (g_modifiedInput < 50) {
        g_modifiedInput += 20;
    } 
  
    else if (g_modifiedInput > 500) {
        g_modifiedInput -= 50;
    }

     if (g_modifiedInput < 0) {
        g_modifiedInput = (g_modifiedInput > -20) ? -g_modifiedInput * 2 : -g_modifiedInput / 2;
    } 
    else if (g_modifiedInput > 1000) {
        g_modifiedInput = 1000;
    }

    return g_modifiedInput;
}
