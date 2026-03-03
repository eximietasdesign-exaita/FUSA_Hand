/**
 * @file threshold_based_processing.c
 *
 * @brief Conditional processing of structured input data using threshold logic and enums.
 *
 * @details
 * This file implements a logic controller that adjusts and processes input parameters
 * based on various threshold comparisons. It uses structured data (`struct s`), function
 * inlining for performance, and global variables for result tracking. The core behavior
 * includes:
 * 
 * - Comparing `inputValue` against a predefined `LIMITS`.
 * - Selecting different structure members (`structMember1` or `structMember2`)
 *   based on `changeThreshold`, `accessThreshold`, and `processStatus`.
 * - Processing values using helper functions `processStructOne` and `processStructTwo`.
 * - Dynamically updating the result with `processCaseValue`, which alters the global
 *   variable `g_computedValue` using switch-case logic.
 *
 */

#include <stdio.h>
#include "threshold_based_processing.h"

#define LIMITS 2147483646
#define ZERO 0

// Global Variables
int inputValue = 0;             // -2147483648 0 2147483647
int changeThreshold = 0;        // 0 ........ 65535
int accessThreshold = 0;        // -32768 0 32767
int processStatus = 0;          // 0....255
uint16_t g_globe = 0;           // 0......65535
uint8_t  g_computedValue = 0;   // 0....255

static inline void processCaseValue(int f_caseValue);
static inline int processStructOne(s myStruct);
static inline int processStructTwo(s myStruct);

// Default initialization of a structure
s myStruct = {0, 0};

/**
 * @brief Processes the first member of a structure and updates a global enum-based variable.
 *
 * @param myStruct A structure containing `structMember1`, used in the computation.
 *
 * @return int The result of adding `myStruct.structMember1` and the enum value `One`.
 */
static inline int processStructOne(s myStruct) {
    g_globe = One;
    return myStruct.structMember1 + g_globe;
}

/**
 * @brief Processes the second member of a structure and updates a global enum-based variable.
 *
 * @param myStruct A structure containing `structMember2`, used in the computation.
 *
 * @return int The result of adding `myStruct.structMember2` and the enum value `Two`.
 */
static inline int processStructTwo(s myStruct) {
    g_globe = Two;
    return myStruct.structMember2 + g_globe;
}

/**
 * @brief Computes value based on input conditions and updates global output.
 *
 * @param inputValue        Integer input to evaluate (range: -2,147,483,648 to 2,147,483,647)
 * @param changeThreshold   Threshold for deciding update logic (range: 0 to 65535)
 * @param accessThreshold   Access control threshold (range: -32,768 to 32,767)
 * @param processStatus     Process execution flag (e.g., 0 or 255)
 *
 * @return None
 */
void determineFinalValue(int inputValue, int changeThreshold, int accessThreshold, int processStatus) 
{
    if (inputValue < LIMITS) {
        if (changeThreshold <= accessThreshold) {
            if (inputValue == ZERO) {
                myStruct.structMember1 = 0;
                g_computedValue = processStructOne(myStruct);
            } else {
                myStruct.structMember1 = 1;
                g_computedValue = processStructOne(myStruct);
            }
        } else if (processStatus == ZERO) {
            myStruct.structMember2 = 2;
            g_computedValue = processStructTwo(myStruct);
        } else {
            myStruct.structMember2 = 3;
            g_computedValue = processStructTwo(myStruct);
        }
    } else {
        g_computedValue = 0;
    }

    processCaseValue(g_computedValue);
}

/**
 * @brief Updates the global computed value based on specific case logic.
 *
 * @param f_caseValue The input value used to determine the computed result.
 * 
 * @return None
 */

static inline void processCaseValue(int f_caseValue) {
    switch (f_caseValue) {
        case 1:
            g_computedValue = f_caseValue + f_caseValue + 1;
            break;
        case 2:
            g_computedValue = f_caseValue + f_caseValue + 2;
            break;
        case 4:
            g_computedValue = f_caseValue + f_caseValue + 3;
            break;
        case 5:
            g_computedValue = f_caseValue + f_caseValue + 4;
            break;
        default:
            g_computedValue = f_caseValue + f_caseValue;
    }
}
