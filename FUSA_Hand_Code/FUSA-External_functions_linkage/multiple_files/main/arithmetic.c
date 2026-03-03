
// Include the header file
//#include "../include/parking_sensor.h"
#include "../include/arithmetic.h" 
#include "../include/p_sensor.h"
#include <stdio.h>
#include "../bcm/bodyControlModule.h"
#include "../include/common.h"
#include "../include/sensor.h"
#include "../include/employee.h"
#include "../ccm/ClimateControlModule.h"
#include "../include/engine_management.h"
uint8_t g_resultOfMultiply;
uint8_t g_resultOfAdd;  // Global variable
//static float divide(uint8_t f_var1, uint8_t f_var_2);
// Function definitions
int g_final_speed = 0;
int g_resultOfDivide=0;
//float g_humidity_level=12;
static void add(uint8_t f_var1, uint8_t f_var_2);
static void multiply(uint8_t f_var1, uint8_t f_var_2);
int main()
{
   static int g_resultOfDivide=0;
   EmployeeDetails l_employeeSalary1;
    int l_var1 = 2, l_var2= 6;
    add(l_var1, l_var2);
    subtract(l_var1, l_var2);
    multiply(l_var1, l_var2);
    g_resultOfDivide=divide(l_var1, l_var2);
    //reading all function from readingSensorData function
    readingSensorData();//sencor.c
    
    //employee leaves
    ProcessEmployeeSalaryAndLeaves(&g_EximietasEmp);
    // Function to monitor engine temperature and take action
    monitor_temperature();
    // Function to heat up the engine (simulate temperature increase)
    heat_engine();
    // Calculate total salary
    CalculateTotalSalary(&l_employeeSalary1);
    
    // Function to check if vehicle is within speed limit
    check_speed_limit();// module is Speed_Control

    // Function to adjust cabin temperature
    adjust_cabin_temperature(20);

   //f_LeftfrontTire, float f_LeftBackTire ,float f_RightfrontTire, float f_RightbackTire)
    float l_LeftfrontTire = 30.0;
    float l_LeftBackTire = 34.0;
    float l_RightfrontTire = 32.05;
    float l_RightbackTire = 36.0;
    //function calling to monitor tire air pressure
    monitor_tireAir_pressure(l_LeftfrontTire, l_LeftBackTire, l_RightfrontTire, l_RightbackTire);
    // Example of using the functions
    detect_humidity_level(20);//detect_humidity_level is declared as a global varibale
}
static void add(uint8_t f_var1, uint8_t f_var_2) 
{
    g_resultOfAdd = f_var1 + f_var_2;  // Using global variable
}

static void multiply(uint8_t f_var1, uint8_t f_var_2) 
{
    
    g_resultOfMultiply = f_var1 * f_var_2;
    // initilizing sessor values
    initialize_sensor(g_resultOfAdd,g_resultOfDivide);
}

float divide(uint8_t f_var1, uint8_t f_var_2) 
{
   int g_resultOfDivide ;
    if (f_var_2 != 0) 
    {
        g_resultOfDivide = (float)f_var1 / f_var_2;
    } 
    else 
    {
        g_resultOfDivide = 0;  // Return 0.0 if division by zero
    }
    return g_resultOfDivide;
}
