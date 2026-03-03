#include "../include/employee.h"
#include <stdio.h>
#include "../include/common.h"
static int CountLeaves(int *f_ZeroPtr, int *f_LeaveDays);
static int *FlattenArray(int (*f_2DArray)[30]);

int Main2DArray[12][30] = {{1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
									{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
									{1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
									{1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									{1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								  };
// Global Structure
EmployeeDetails g_EximietasEmp;

// Convert a 2D array to a 1D array
static int *FlattenArray(int (*f_2DArray)[30]) {
    disengage_brakes();
    return *f_2DArray;
}

// Count the number of zeros and store leave days
static int CountLeaves(int *f_ZeroPtr, int *f_LeaveDays) {
    int l_ZeroCount = 0;
    for (int l_Index = 0; l_Index < 30; l_Index++) {
        if (*(f_ZeroPtr + l_Index) == 0) {
            l_ZeroCount++;
            f_LeaveDays[l_ZeroCount - 1] = l_Index + 1;
        }
    }
    return l_ZeroCount;
}

// Function to process salary and leaves for the employee
void ProcessEmployeeSalaryAndLeaves(EmployeeDetails *f_EmployeeDetails) {
    int l_LeaveDays[30] = {0}; // Array to store leave days
    int l_ZeroCount = 0;

    for (int l_Index = 0; l_Index < 12; l_Index++) 
    {
        int *l_MonthlyArray = FlattenArray(&Main2DArray[l_Index]);
        l_ZeroCount = CountLeaves(l_MonthlyArray, l_LeaveDays);

        CalculateMonthlySalary(f_EmployeeDetails, l_ZeroCount);
	}
 }

