#include "../include/employee.h"
#include "../include/common.h"
// Global Variables
int g_SalaryArray[2] = {2000, 3000};
int g_GlobalIndex = 0;

// Calculate total salary
void CalculateTotalSalary(EmployeeDetails *f_EmployeeDetails) {
    f_EmployeeDetails->EachEmployeeSalary.TotalYearSalary = 0;
    for (int l_Index = 0; l_Index < 12; l_Index++) {
        f_EmployeeDetails->EachEmployeeSalary.TotalYearSalary += f_EmployeeDetails->EachEmployeeSalary.MonthlySalary[l_Index] + g_SalaryArray[1];
    }
}

// Calculate monthly salary
void CalculateMonthlySalary(EmployeeDetails *f_EmployeeDetails, int f_ZeroCount) {
    f_EmployeeDetails->EachEmployeeSalary.MonthlySalary[g_GlobalIndex] = (g_SalaryArray[1] * 30) - (g_SalaryArray[1] * f_ZeroCount);
}

