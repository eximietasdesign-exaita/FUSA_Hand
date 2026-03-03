#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H
//int computeg_initiall_result(int f_input);
// Define an enum for switch cases
typedef enum {
    CASE_ONE = 1,
    CASE_TWO,
    CASE_THREE,
    CASE_FOUR,
	CASE_FIVE,
    CASE_SIX	
} CaseType;

// Structure to hold input and result
typedef struct {
    int input;
    int result;
} Data;

// Function declarations
int applySwitchModifications(int f_input);

#endif // DATA_PROCESSING_H
