
#include <stdio.h>
#include <string.h>
#include "switchcase_performing_AO.h"
#include <assert.h>

// Assuming l_details is a struct, define it here
typedef struct {
    long long account_number;
    long long account_number2;
    int branch_number;
} BankDetails;

// Declare l_details as a global variable
BankDetails l_details;

void test_BankAccountDetails_Function() {
    int test_cases[] = {1, 2, 3, 4};  // Test cases for choice
    int expected_outputs[] = {0, 0, 0, 1};  // Expected outputs (0 for valid choice, 1 for invalid choice)

    for (int i = 0; i < 4; i++) {
        int choice = test_cases[i];
        int expected_output = expected_outputs[i];

        // Set the choice for the test case
        int l_choice = choice;

        // Call the function to be tested
        BankAccountDetails_Function(l_choice); // Corrected function name

        // Check if the function performed the expected operation
        if (expected_output == 0) {
            if (l_choice == 1) {
                // Check if account number is set
                if (l_details.account_number != 123456789012) {
                    printf("Test case failed\n");
                }
            } else if (l_choice == 2) {
                // Check if balance is set
                if (l_details.account_number2 != 234567890123) {
                    printf("Test case failed\n");
                }
            } else if (l_choice == 3) {
                // Check if branch number is set
                if (l_details.branch_number != 7453) {
                    printf("Test case failed\n");
                }
            }
        } else {
            // Check if the function performed the expected operation for invalid choice
            if (l_choice != 4) {
                printf("Test case failed\n");
            }
        }
    }
}

// int main()
// {
//     test_BankAccountDetails_Function();
//     return 0;
// }
