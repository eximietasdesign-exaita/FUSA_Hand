#include "../include/common.h"

// Function to monitor engine temperature and take action
void monitor_temperature() 
{
    if (g_engine_temperature > 100) 
	{
        if (g_vehicle_speed > 0) 
		{
            engage_brakes();                                 // Engage brakes if the vehicle is moving and engine overheats
        }
		else
		{
		    disengage_brakes();
		}                                     
    }
	else if (g_engine_temperature > 90 && g_engine_temperature <= 100)
     {
        if (g_vehicle_speed > 100) 
		{
            decrease_speed();                                  // Slow down to cool the engine
        }
		else
		{
            g_vehicle_speed = 110;
		}			
    }
	else
	{
		g_engine_temperature = 0;
	}   
}
// Function to cool down the engine
void cool_engine() {
    if (g_engine_temperature > 90) 
	{
        g_engine_temperature -= 5;                           
    } 
	else {                                                                   
        g_engine_temperature = (g_engine_temperature < 60) ? 60 : g_engine_temperature;
    }   
}
// Function to heat up the engine (simulate temperature increase)
void heat_engine()
 {
    if (g_engine_status == 1) 
	{
        g_engine_temperature += 2;                                 
    } 
	else {
        g_engine_temperature = (g_engine_temperature > 80) ? 80 : g_engine_temperature; 
    }
}
// Function to handle diagnostics based on system state
void diagnostics() 
{
    if (g_vehicle_speed > 120) 
	{
        decrease_speed();                                                 // Reduce speed if it's too high
    }   
    if (g_brake_status == 1 && g_vehicle_speed > 0) 
	{
        g_vehicle_speed = 0;                                                    // Stop vehicle if brakes are engaged
    }
	else
	{
		g_vehicle_speed = 1;
	}
}
