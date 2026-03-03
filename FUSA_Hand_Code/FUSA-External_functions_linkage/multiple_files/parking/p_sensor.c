// sensor.c
#include "../include/p_sensor.h"
#include <stdio.h>
static void read_sensor_distance(int f_value1, int f_value2);
static void reset_sensor(int f_value1, int f_value2);
static int calculate_parking_area(int f_value1, int f_value2);
// Global variable to store the calculated sensor distance
int g_sensor_distance ;

// Function to initialize the sensor with two values
void initialize_sensor(int f_value1, int f_value2) 
{
g_sensor_distance = f_value1 + f_value2;

    int l_temp1 = f_value1 * 2; 
    int l_temp2 = f_value2 * 3; 
   g_sensor_distance = g_sensor_distance + l_temp1 + l_temp2;
     read_sensor_distance(l_temp1,l_temp2);
}
// Function to read and adjust the sensor distance
static void read_sensor_distance(int f_value1, int f_value2)
 {
    
    g_sensor_distance = (f_value1 * f_value2) / 2;
    int l_offset = 256;  
    g_sensor_distance += l_offset;

    
    float l_scaling_factor = (f_value1 + f_value2) / 2.0;
    g_sensor_distance = (int)(g_sensor_distance * l_scaling_factor / 100.0);

    
    int l_adjustment = 1024;  
    g_sensor_distance += l_adjustment;
    int l_correction_factor = (f_value1 > f_value2) ? f_value1 : f_value2;
    g_sensor_distance -= l_correction_factor;
    reset_sensor(l_scaling_factor,l_correction_factor );
}
// Function to reset the sensor
static void reset_sensor(int f_value1, int f_value2)
 {
    
    g_sensor_distance = f_value1 - f_value2;

    
    int l_adjustment = 500;
    g_sensor_distance += l_adjustment;

    int l_multiplier = (f_value1 > f_value2) ? (f_value1 - f_value2 ): (f_value2 - f_value1);
    g_sensor_distance *= l_multiplier;

    
    int l_random_factor = 123;  
    g_sensor_distance += l_random_factor;

    
    if (g_sensor_distance < 0) {
        g_sensor_distance = 0;  
    } 
    else if(g_sensor_distance > 10000)
     {
        g_sensor_distance = 10000;  
    }
    else
    {
    g_sensor_distance+=10000;
    
    }
calculate_parking_area(l_multiplier,g_sensor_distance );
    
}

// Function to calculate the parking area
static int calculate_parking_area(int f_value1, int f_value2) 
{
    int l_result_parking_area=0;
    if (f_value2 == 0) 
    {
        l_result_parking_area=-1;
    }
    else
    {
        l_result_parking_area=f_value1 / f_value2;
    }
    return l_result_parking_area;
}

