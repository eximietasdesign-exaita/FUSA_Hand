#ifndef SWITCHCASE_PERFORMING_AO_H
#define SWITCHCASE_PERFORMING_AO_H
#include <stdbool.h>

// Define the union to store bank account details
union BankAccountDetails {
    long account_number;
    double balance;
    int branch_number;
};
// Define the enum for different union members
enum UnionMember {
    ACCOUNT_NUMBER,
    BALANCE,
    BRANCH_NUMBER
};
// Define the enum for arithmetic operations
enum arithmetic_Operations {
    Addition = 0,
    Subtraction = 1,
    Multiplication = 2,
    Division = 3,
    Logical = 4,
    Conditional = 5
};
//Define a struct to store account details associated with account numbers
struct AccountInfo {
    long account_number;
    double balance;
    int branch_number;
};
// Declare the accounts array as extern
extern struct AccountInfo accounts[];

// Define the number of accounts
#define NUM_ACCOUNTS 5

// Function prototypes
int BankAccountDetails_Function(int l_choice);
void switchcase_Function(enum arithmetic_Operations f_operation, int f_operand1, int f_operand2);

#endif // SWITCHCASE_PERFORMING_AO_H
