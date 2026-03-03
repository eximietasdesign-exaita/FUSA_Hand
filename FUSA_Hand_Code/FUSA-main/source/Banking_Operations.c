/**
 * @file switchcase_performing_AO.c
 *
 * @brief Implements operations on bank account details using union and switch-case logic.
 *
 * This file provides functionality to:
 * - Select and process a specific bank account field (account number, balance, or branch number)
 *   using a union and corresponding enum.
 * - Validate and perform simulated banking operations like balance update.
 * - Store and print the processed results using global variables for further use.
 *
 * Key Functions:
 * - BankAccountDetails_Function(): Main entry point for triggering a specific operation.
 * - performOperations(): Executes logic based on the active union member.
 * - printDetails(): Stores and logs non-zero values into global state.
 *
 * Data Structures Used:
 * - union BankAccountDetails: Stores one of the bank fields.
 * - enum UnionMember: Indicates which union member is currently active.
 * - struct AccountInfo: Holds complete details of a bank account.
 *
 * Global Variables:
 * - g_account_details, g_balance_details, g_branch_details: Store processed output.
 * - g_invalid_branch_number: Stores invalid branch number for error tracking.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "switchcase_performing_AO.h"

//Function Prototypes
static void performOperations(union BankAccountDetails details, enum UnionMember active_member);
static void printDetails(long storeAccount_details, double storeBalance_details, int storeBranch_details);

// Define the accounts array
struct AccountInfo accounts[NUM_ACCOUNTS] = {
    {123456789012, 1000.00, 7453},
    {234567890123, 1500.50, 7454},
    {345678901234, 2000.75, 7455},
    {456789012345, 2500.00, 7456},
    {567890123456, 3000.25, 7457}
};

//Global variables
long g_account_details = 0;
double g_balance_details = 0;
int g_branch_details = 0;
int g_invalid_branch_number = 0;

/**
 * @brief Sets and processes a selected field of a bank account using a union.
 *
 * @param l_choice An integer value indicating the field to process:
 *  1 = Account Number,
 *  2 = Balance,
 *  3 = Branch Number
 *
 * @return int 0 on success, -1 on failure (invalid input)
 */
int BankAccountDetails_Function(int l_choice) 
{
    union BankAccountDetails l_details;
    enum UnionMember l_active_member;
    bool is_valid = true;

    // Set union field and active member based on input choice
    switch (l_choice) {
        case 1:
            l_active_member = ACCOUNT_NUMBER;
            l_details.account_number = 123456789012;
            break;

        case 2:
            l_active_member = BALANCE;
            l_details.account_number = 234567890123;
            break;

        case 3:
            l_active_member = BRANCH_NUMBER;
            l_details.branch_number = 7453;
            break;

        default:
            printf("Invalid choice: %d\n", l_choice);
            is_valid = false;
            break;
    }

    // Call only if a valid choice was made
    if (is_valid) {
        performOperations(l_details, l_active_member);
        return 0; 
    } else {
        return -1;
    }
}

/**
 * @brief Performs operations based on the active member of the bank account.
 *
 * This function processes one of the bank account fields — account number, balance,
 * or branch number, depending on the value of the active union member enum.
 *
 * @param f_details The union containing the input bank account field.
 * @param f_active_member The enum indicating the active union member.
 *
 * @return None
 */
static void performOperations(union BankAccountDetails f_details, enum UnionMember f_active_member) 
{
    long l_storeAccount_details = 0;
    double l_storeBalance_details = 0.0;
    int l_storeBranch_details = 0;
    bool flag = true;

    switch (f_active_member) 
    {
        case ACCOUNT_NUMBER:
            {
                bool l_account_found = false;
                // Check if the entered account number is in the predefined list
                for (int i = 0; i < NUM_ACCOUNTS; i++) 
                {
                    if (accounts[i].account_number == f_details.account_number) 
                    {
                        l_storeAccount_details = f_details.account_number;
                        l_storeBalance_details = accounts[i].balance;
                        l_storeBranch_details = accounts[i].branch_number;
                        l_account_found = true;
                        break;
                    }
                }
                if (!l_account_found)
                {
                    l_account_found = false;
                }

            }
            break;
        case BALANCE:
            {
                bool l_account_found = false;
                // Look up the balance using the account number
                for (int i = 0; i < NUM_ACCOUNTS; i++)
                 {
                    if (accounts[i].account_number == f_details.account_number) 
                    {
                        l_storeAccount_details = accounts[i].account_number;
                        l_storeBalance_details = accounts[i].balance;
                        l_storeBranch_details = accounts[i].branch_number;
                        l_account_found = true;
                        break;
                    }
                }
                if (l_account_found) {
                    // Deposit and withdrawal amounts
                    double l_deposit_amount, l_withdrawal_amount;
                    l_deposit_amount = 50000;
                    l_withdrawal_amount = 1000;

                    // Check if the withdrawal is valid
                      if (l_withdrawal_amount <= (l_storeBalance_details + l_deposit_amount)) {
                          l_storeBalance_details += l_deposit_amount - l_withdrawal_amount;
                    // Update the accounts
						for (int i = 0; i < NUM_ACCOUNTS; i++) {
							if (accounts[i].account_number == l_storeAccount_details) {
								accounts[i].balance = l_storeBalance_details;
								break;
							}
						}
					} else {
						l_storeBalance_details += l_deposit_amount;
                }
                } else {
                    l_account_found = false;
                }
            }
            break;
        case BRANCH_NUMBER:
            // Validate and store branch number
            if (f_details.branch_number >= 7452 && f_details.branch_number <= 7460) {
                l_storeBranch_details = f_details.branch_number;
                // Check if the branch number is valid and exists in accounts
                bool l_branch_found = false;
                for (int i = 0; i < NUM_ACCOUNTS; i++) {
                    if (accounts[i].branch_number == l_storeBranch_details) {
                        l_storeAccount_details = accounts[i].account_number;
                        l_storeBalance_details = accounts[i].balance;
                        l_branch_found = true;
                        break;
                    }
                }
                if (!l_branch_found) 
				{
                    l_branch_found = false;
                }
            } else {
                g_invalid_branch_number = f_details.branch_number;
            }
            break;

        default:
            printf("Error: Invalid union member selector: %d\n", f_active_member);
            flag = false;
            break;
    }
    
    if (flag) {
        printDetails(l_storeAccount_details, l_storeBalance_details, l_storeBranch_details);
    }
}

/**
 * @brief Stores non-zero bank account details into global variables.
 *
 * This function checks each of the input parameters — account number,
 * balance, and branch number and updates the corresponding global
 * variables only if the values are non-zero.
 *
 * @param f_storeAccount_details  Account number to store
 * @param f_storeBalance_details  Balance amount to store
 * @param f_storeBranch_details   Branch number to store
 *
 * @return None
 */
static void printDetails(long f_storeAccount_details, double f_storeBalance_details, int f_storeBranch_details)
{
    
    if (f_storeAccount_details != 0) {
         g_account_details = f_storeAccount_details;
    }
    if (f_storeBalance_details != 0.0) {
       g_balance_details = f_storeBalance_details;
    }
    if (f_storeBranch_details != 0) {
        g_branch_details = f_storeBranch_details;
    }
}
