#include <stdio.h>
#include <stdbool.h>
#include "../include/arithmetic.h" 
#include "../ccm/ClimateControlModule.h"

float g_current_temperature = 22.0; //fixed value
bool g_ac_compressor_status ;
int g_fan_speed = 0;
float g_humidity_updated;
bool g_defogger_status = false;
bool g_vent_open ;
bool g_preconditioning_status = false;
float g_air_quality_index;
int g_AcStatus=26;
bool g_rear_defrost_status = false;
float g_humidity=50;

/*Function Prototypes*/
static void control_ac_compressor(bool f_enable) ;
 static void activate_defogger(bool f_enable);
 static void set_fan_speed(int f_speed);
 //static void control_vent_position(bool f_open) ;
 //static void start_cabin_preconditioning(bool f_enable);
 static void control_rear_window_defrost(bool f_enable);


// Global variable to represent window status (1 = open, 0 = closed)
int g_window_status = 1; // Initially, windows are assumed to be open

// Function to adjust cabin temperature
 void adjust_cabin_temperature(float f_target_temp)
 {
    if (f_target_temp != g_current_temperature) 
    {
        g_current_temperature = f_target_temp;      
    } 
    else 
    {
        g_current_temperature = 0; 
    }
    activate_defogger(true);
}

// Function to control AC compressor
static void control_ac_compressor(bool f_enable) 
{
    g_ac_compressor_status = f_enable;
    if (g_ac_compressor_status)
     {
        g_ac_compressor_status+=10;
    } else {
        g_ac_compressor_status-=10;
    }
}

// Function to activate defogger
static void activate_defogger(bool f_enable)
 {
    g_defogger_status = f_enable;
    if (g_defogger_status) 
    {
        g_defogger_status=1;
    } else 
    {
        g_defogger_status=0;
    }
}

// Function to set fan speed
static void set_fan_speed(int f_speed)
 {
    if (f_speed >= 0 && f_speed <= 5)
     {
        g_fan_speed = f_speed;
    }
    else 
    {
         g_fan_speed = 0;
    }
}
// Function to detect humidity level
void detect_humidity_level(float f_humidity) 
{
    if(f_humidity<25)
    {
        g_humidity_updated = f_humidity;
        if(f_humidity<25 && g_resultOfAdd<=50)
        {
            g_humidity_updated+=10;
            set_fan_speed(3);
            control_ac_compressor(false);
        }
        else
        {
             g_humidity_updated=0;
            control_ac_compressor(true);
        }
    }
    else
    {
        control_rear_window_defrost(g_humidity);
        if(f_humidity<25 && g_air_quality_index<=50)
        {
            control_ac_compressor(true);
            
        }   
    }  
}

/*function monitors the car's air quality index (AQI)
 based on the sensor data and adjusts the vehicle's windows and ventilation */
void monitor_air_quality_sensor(float f_air_quality_index) //calling from sensor.c 170
{
    if (f_air_quality_index > 50.0)
    {
        g_air_quality_index = f_air_quality_index;
    }
    else
    {
        g_air_quality_index = f_air_quality_index+10;
    }
}

// Function to control rear window defrost
static void control_rear_window_defrost(bool f_enable) 
{
    g_rear_defrost_status = f_enable;
    if (g_rear_defrost_status)
    {
        g_rear_defrost_status+=10;
    }
    else 
    {
        g_rear_defrost_status-=10;
    }
}

