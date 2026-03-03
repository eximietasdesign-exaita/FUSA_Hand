#include "../include/parking_sensor.h"
#include "../include/p_sensor.h"
#include "../include/common.h"
int g_parkingplace=1;
static float parkingPlaceCalculating(float f_parking_length, float f_parking_width);
static float g_readometerUpdating;

// Function to calculate the parking place area
static float parkingPlaceCalculating(float f_parking_length, float f_parking_width)
{
    float l_requiredPlace;
    l_requiredPlace = f_parking_length * f_parking_width;
      disengage_brakes();  
    return l_requiredPlace;
}
// Main function to handle the parking logic
void park_car_in_single_function(GearMode f_current_mode, float f_parking_length, float f_parking_width, float f_required_parking_size)
{
    // Initialize gear mode (car starts in DRIVE mode)
    if (f_current_mode == REVERSE) 
    {
        g_readometerUpdating+=10;
    }
    else if (f_current_mode == DRIVE) 
    {
        g_readometerUpdating += 20;
    }
    else if (f_current_mode == PARK) 
    {
        float g_parkingplace = parkingPlaceCalculating(f_parking_length, f_parking_width);
        
        if (g_parkingplace > f_required_parking_size) 
        {
           g_parkingplace+=5;
        } 
        else 
        {
            g_parkingplace+=50;
        }

    } 
    else 
    {
        g_parkingplace=0;
    }
    
}
