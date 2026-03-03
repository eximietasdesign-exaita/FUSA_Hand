#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define maximum and minimum thresholds
#define MAX_TEMP 120.0
#define MIN_TEMP 20.0
#define MAX_FUEL 100.0
#define MIN_FUEL 10.0
#define MAX_SPEED 200.0
#define MIN_SPEED 0.0
extern float g_throttle_position;

// Structure to hold sensor data
typedef struct 
{
    float engine_temp;  // Engine temperature in Celsius
    float fuel_level;   // Fuel level percentage
    float speed;        // Speed in km/h
    bool brake_status;  // Brake engaged or not
} SensorData;


