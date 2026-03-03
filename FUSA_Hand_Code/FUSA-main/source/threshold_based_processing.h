#ifndef PROCESSING_H
#define PROCESSING_H

#include <stdint.h>

  // Define external variables
extern int inputValue;                       // -2147483648 0 2147483647
extern int changeThreshold;                 // 0 ........ 65535
extern int accessThreshold;                 // -32768 0 32767
extern int processStatus;                    // 0 255
void determineFinalValue(int inputValue, int changeThreshold, int accessThreshold, int processStatus);
// Global variables
extern uint16_t g_globe;                          // 0......65535
extern uint8_t  g_computedValue;                   // 0 255

// Enum
enum e { One = 1, Two };

// Structure with bitfields
typedef struct stut {
    unsigned int structMember1 : 5;  // struc_var1 uses 5 bits
    unsigned int structMember2 : 6;  // struc_var2 uses 6 bits
} s;

#endif // PROCESSING_H
