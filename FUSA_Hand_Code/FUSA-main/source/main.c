#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macro_def.h"
#include "salaryrange.h"
#include "mem_allocation.h"
#include "bool.h"
#include "enum_def.h"
#include "data_processing.h"
#include "threshold_based_processing.h"
#include "functionPointer_operation.h"
#include "switchcase_performing_AO.h"
#include "miscellaneous_tasks_def.h"
#include "MyString.h"
#include "ArrayOperations.h"
#define BONUS 10016
#define ARRAYMEMBERS 4
#define NUM_ELEMENTS 5

#define DEBUG_MODE 1

#if DEBUG_MODE
#define LOGGING_ENABLED addfunction(2, 2)
#else
#define LOGGING_DISABLED subfunction(111, 11)
#endif
int g_thresholdReturnResult;
uint8_t g_var1=10;
uint8_t g_var2=10;
int employe_salary;
double g_result;
int g_employe_salary;
int g_bignumber;
extern void performExternalOperationOne(void) ;
extern void performExternalOperationTwo();
extern void performExternalOperationThree();
extern void  performExternalOperationFour();
extern void performExternalOperationFive();
//extern void InsertionSort(l_primaryArray);
//extern void InsertionSort(l_secondaryArray);
/* This function compares two uint8_t values, var1 and var2
 and updates a static variable var_sum according to the comparison result:*/
 
 int l_first_operand = 10, l_second_operand = 20;
 
static void compare_numbers(uint8_t f_var1, uint8_t f_var2) 
{
	static int l_var_sum=0;
    if (f_var1 > f_var2)
	{
        l_var_sum+=f_var2;
    } 
	else if (f_var1 < f_var2) 
	{
		l_var_sum=f_var1+f_var2;
    } 
	else 
	{
		l_var_sum=f_var1-f_var2;
	}

}
/*function calculates the salary range of an employee based on their age and grade. It uses the 
employeeSalaryRange function to obtain the salary range and then return a message based on the calculated .
salary.*/
static int employe_id_and_details(int f_age, int f_employe_grade) 
{
    int l_salary = employeeSalaryRange(f_age, f_employe_grade);
	int l_salaryUpdate;
    if (l_salary >= 15000) 
	{
		l_salaryUpdate=l_salary+BONUS;
		//printf("\n--> Salary range is less than :%d ", salary);
    }
	else
	{
		l_salaryUpdate=l_salary+BONUS;
        //printf("\n--> Salary range is less than :%d ", salary);
    }
    return l_salaryUpdate;
}

int main() 
{

uint8_t l_input=10;  
    // Comparing the two numbers with the given inputs
   compare_numbers(g_var1, g_var2);// 
	
    // Based on the employee's grade and age validating the CTC
	int l_age = 19, l_employe_grade = 2;
	g_employe_salary=employe_id_and_details(l_age, l_employe_grade);
	 
    int num1=10 , num2=12 ;
   //this function is comparing  the numbers
	g_bignumber=checkBigNumber(num1, num2);
    double enum_var1 = 10.0, enum_var2 = 5.0;
    
	// performs addition operation using enums
    g_result = performOperation(ADDITION, enum_var1, enum_var2);
    // performs substarction operation using enums
    g_result = performOperation(SUBTRACTION, enum_var1, enum_var2);
	// performs multiplication operation using enums
    g_result = performOperation(MULTIPLICATION, enum_var1, enum_var2);
    // performs division operation using enums
    g_result = performOperation(DIVISION, enum_var1, enum_var2);
	// performs division operation using 0 
    // Test division by zero
    g_result = performOperation(DIVISION, enum_var1, 0);
   


	 //Array inputs 
	int array1[ARRAYMEMBERS]={1,2,3,4};
	int array2[ARRAYMEMBERS]={1,2,3,4};
    add_arrays(array1, array2, ARRAYMEMBERS);

	for (int i = 0; i < ARRAYMEMBERS; i++) 
	{
      array1[0]=array1[0]+array1[i];
    }
	signed int  configFlags;

#if DEBUG_MODE
    configFlags = LOGGING_ENABLED;
#else
    configFlags = LOGGING_DISABLED;
#endif

    if (configFlags>=0 && configFlags <= 5)
	{
       g_thresholdReturnResult=manageVehicleComponents(MODE_PARK);
    //printf("%d \n",g_thresholdReturnResult);
    } 
	else if (configFlags >= 6 && configFlags <= 10) 
	{
       g_thresholdReturnResult=manageVehicleComponents(MODE_DRIVE);
    //	printf("%d \n",g_thresholdReturnResult);
    } 
	else
	{
   g_thresholdReturnResult=manageVehicleComponents(MODE_REVERSE);
	//printf("%d \n",g_thresholdReturnResult);
    }
  /*Surya*/
  applySwitchModifications(l_input);
/*Nisha*/
    // Initialize operands
    g_operand1 = 50; 
    g_operand2 = 25; 

    // Call the function to process the global variable
    operation_function_pointer(l_input); 
	
/* Jinesh*/
    determineFinalValue(590, 370, 120, 460);
    AllMiscellaneous_Tasks_DefMakeStatic();
    CallingAllfunctionsToMakeStaic();//strcpy and memcpy
    determineComplexity(100, 650, 250, 450);//Complexcity function

/*Navya*/
    enum arithmetic_Operations l_operation = Addition; 
    // Call the switchcase_Function with the provided operation and values
    switchcase_Function(l_operation, l_first_operand, l_second_operand);
    

return 0;
}
