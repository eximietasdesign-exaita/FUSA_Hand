

#include <stdint.h>
#include <stdbool.h>

// Constants
#define NUM_ELEMENTS 5
#define MAX_ARRAY_SIZE 10
#define CONST_A 98
#define CONST_B 63
#define CONST_ZERO 0

// Function Pointer which takes one argument
extern int (*handleEvent_func)(int);

// Arrays
extern int primaryArray[NUM_ELEMENTS];
extern int secondaryArray[NUM_ELEMENTS];
extern int extendedArray[MAX_ARRAY_SIZE];

// Global Variables
extern uint8_t g_incrementCounter;
extern int g_computedTotal;
// Extern Variables
extern int16_t externalVarOne;
extern uint32_t externalVarTwo;
extern uint8_t externalVarThree;
extern int16_t externalVarFour;

// Enums
enum OddEnum { enum_ONE = 1, enum_THREE = 3, enum_FIVE = 5, enum_SEVEN = 7, enum_NINE = 9 };
enum EvenEnum { enum_ZERO = 0, enum_TWO = 2, enum_FOUR = 4, enum_SIX = 6, enum_EIGHT = 8, enum_TEN = 10 };

void AllMiscellaneous_Tasks_DefMakeStatic();

extern int l_first_operand;
extern int l_second_operand;
//void Merge_Two_Arrays(void);
