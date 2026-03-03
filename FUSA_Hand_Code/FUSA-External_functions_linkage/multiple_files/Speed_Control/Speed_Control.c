#include "../include/common.h"

// Global variable definitions
int g_vehicle_speed = 0;
int g_engine_status = 0;
int g_engine_temperature = 80;
int g_brake_status = 0;

//Function Prototypes
static void increase_speed();

// Function to increase vehicle speed
static void increase_speed() 
{
	static int l_speed_data = 0;
	l_speed_data = g_vehicle_speed +10;
    if (g_engine_status == 1) 
	{                                                           
        if (l_speed_data < 180) 
		{                                                     
            l_speed_data += 10;
        }
		else {
                                                             
            l_speed_data = 180;
        }
    } 
	else {
                                                              
        l_speed_data = 0;
    }
	g_vehicle_speed = l_speed_data;
}

// Function to decrease vehicle speed
void decrease_speed() 
{
    if (g_vehicle_speed > 0) 
	{
        g_vehicle_speed -= 10;
        if (g_vehicle_speed < 0) 
		{
            g_vehicle_speed = 0;  
        }
    } 
	else 
    {
        g_vehicle_speed = 0;  
    }
}

// Function to check if vehicle is within speed limit
void check_speed_limit() 
{
    if (g_vehicle_speed > 120) 
	{                                                             
        decrease_speed();
        if (g_vehicle_speed < 100) 
		{
             cool_engine();                                    
        }
    } 
	else if (g_vehicle_speed < 60) 
    {
        if (g_engine_status == 1)
         {
            increase_speed();                           
        }
    }
}

// Function to engage brakes
void engage_brakes() 
{
    if (g_brake_status == 0) 
	{
        g_brake_status = 1;                        
        if (g_vehicle_speed > 0) 
		{
            g_vehicle_speed = 0;                           
        }
    }
	else
	{
        //do nothing
	}
   
}

// Function to disengage brakes
void disengage_brakes() 
{
    if (g_brake_status == 1) 
	{
        g_brake_status = 0;                               
    } 
	else {
                                                                                 
        if (g_vehicle_speed == 0 && g_engine_status == 1) 
		{
            increase_speed();                                       
        }
    }
}
