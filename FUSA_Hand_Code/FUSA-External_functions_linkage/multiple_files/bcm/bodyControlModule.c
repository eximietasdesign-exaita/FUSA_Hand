//
#include "../bcm/bodyControlModule.h"
#include "../include/sensor.h"
#include "../include/common.h"
//this function is calling from sensor.c
// Function to monitor tire pressure, receiving pressures for all four tires
float monitor_tireAir_pressure(float f_LeftfrontTire, float f_LeftBackTire, float f_RightfrontTire, float f_RightbackTire) {
    // Variable to store the result of pressure checks
   static int l_all_tires_ok = 1;  // 1 = OK, 0 = Not OK

    // Check Left Front Tire
    if (f_LeftfrontTire < MIN_PRESSURE || f_LeftfrontTire > MAX_PRESSURE)
    {
        
        l_all_tires_ok = 0;
    }
    if (f_LeftBackTire < MIN_PRESSURE || f_LeftBackTire > MAX_PRESSURE) 
    {
        l_all_tires_ok = 0;
    }
    
    if (f_RightfrontTire < MIN_PRESSURE || f_RightfrontTire > MAX_PRESSURE)
     {
        l_all_tires_ok = 0;
    }

    if (f_RightbackTire < MIN_PRESSURE || f_RightbackTire > MAX_PRESSURE) 
    {
        l_all_tires_ok = 0;
    }

    if(l_all_tires_ok) 
    {
        l_all_tires_ok = 1;
    } 
    else 
    {
        l_all_tires_ok = 0;
    }
    
    engage_brakes();
    
    return l_all_tires_ok;
}
