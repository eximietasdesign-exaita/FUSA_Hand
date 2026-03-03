// macro.c
#include <stdio.h>
#include "macro_def.h"
int g_vehicle_speed = 10;

/**
 * @brief Manages vehicle component behavior based on the current operation mode.
 *
 * This function determines the behavior of vehicle components (such as speed-related systems)
 * using a switch-case logic based on the provided operation mode.
 * It performs different numerical operations depending on the mode:
 * 
 * - **MODE_DRIVE**: Increases vehicle speed by a defined high threshold if the current speed is greater than zero.
 * - **MODE_PARK**: Computes the difference between a low-speed threshold and current vehicle speed; result is clamped to zero if negative.
 * - **MODE_REVERSE**: Reduces vehicle speed by half if the vehicle is moving (speed > 0).
 * - **Default**: Ignores invalid modes.
 * 
 * The computed threshold result is returned to the caller. If the mode or speed is invalid,
 * a default value `COMPONENT_OFF` is returned.
 *
 * @param f_mode Operation mode input. Valid modes include MODE_DRIVE, MODE_PARK, and MODE_REVERSE.
 * @return int Threshold-based result depending on the mode logic.
 *
 * @note
 * - Uses the global variable `g_vehicle_speed` as the current speed input.
 * - Constants used: `SPEED_THRESHOLD_HIGH`, `SPEED_THRESHOLD_LOW`, and `COMPONENT_OFF`.
 */

int manageVehicleComponents(int f_mode) 
{
	int l_speed_factor;
    int l_threshold_result;

    // Use switch-case to handle different operation modes
    switch (f_mode) 
	{
        case MODE_DRIVE:
           
            if (g_vehicle_speed > 0)
				{
               // Numerical operation: Calculate adjusted speed
                l_speed_factor = g_vehicle_speed + SPEED_THRESHOLD_HIGH;
                l_threshold_result=l_speed_factor;
            } 
			else 
			{
               l_threshold_result=COMPONENT_OFF;
            }
            break;

        case MODE_PARK:
            // Numerical operation: Check if speed is below threshold
            l_speed_factor = SPEED_THRESHOLD_LOW - g_vehicle_speed;
            l_threshold_result = (l_speed_factor > 0) ? l_speed_factor : 0;
             
            break;

        case MODE_REVERSE:
            
            if (g_vehicle_speed > 0)
				{
               
                l_speed_factor = g_vehicle_speed / 2;
                l_threshold_result=l_speed_factor;
            } 
			else 
			{
                l_threshold_result=COMPONENT_OFF;
            }
            break;

        default:
            //printf("Error: Invalid operation mode %d.\n", f_mode);
            break;
    }

 return l_threshold_result;
}

int addfunction(int f_varA, int f_varB) {
    return f_varA + f_varB;
}