#define EMPLOYEE_H

// Structure Definitions
typedef struct Month_Year_Calculation {
    int MonthlySalary[12];
    float TotalYearSalary;
} Month_Year_Calculation;

typedef struct DayDateYear {
    int Day;
    int Month;
    int Year;
} DayDateYear;

typedef struct EmployeeDetails {
    char Name[10];
    int ID;
    Month_Year_Calculation EachEmployeeSalary;
    DayDateYear DateOfEmployment;
} EmployeeDetails;

// Global variable declarations
extern int Main2DArray[12][30];
extern int g_SalaryArray[2];
extern int g_GlobalIndex;
extern EmployeeDetails g_EximietasEmp;

// Function Prototypes
void CalculateTotalSalary(EmployeeDetails *f_EmployeeDetails);
void CalculateMonthlySalary(EmployeeDetails *f_EmployeeDetails, int f_ZeroCount);
void ProcessEmployeeSalaryAndLeaves(EmployeeDetails *f_EmployeeDetails);


