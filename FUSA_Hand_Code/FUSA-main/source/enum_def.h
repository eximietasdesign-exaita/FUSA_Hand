#ifndef ENUM_H
#define ENUM_H

// Macro definitions
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define DEFAULT 5
// Enum for operation types
typedef enum {
    ADDITION = ADD,
    SUBTRACTION = SUBTRACT,
    MULTIPLICATION = MULTIPLY,
    DIVISION = DIVIDE ,
    DEFA= DEFAULT
} OperationType;

// Function declaration
double performOperation(OperationType opType, double f_var1, double f_var2);

#endif // ENUM_H
