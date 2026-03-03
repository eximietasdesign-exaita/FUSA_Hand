#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>  // For sleep function (simulates real-time delay)
#include "../include/engine_management.h"

//Global Variables
bool g_initialized = false;

//Function Prototypes
static void initialize_engine(Engine *f_engine);
static void start_engine(Engine *f_engine);
 
static void set_idle_speed(Engine *f_engine, int f_speed);
static void log_idle_speed(int f_idle_speed);

// Global Variables
int g_idle_speed = 0;

// Simple custom pseudo-random number generator
unsigned int pseudo_random(unsigned int f_seed) {
    // Linear Congruential Generator parameters
    const unsigned int l_generator_a = 100;
    const unsigned int l_generator_c = 200;
    const unsigned int l_generator_m = 300; // 2^32
    return (l_generator_a * f_seed + l_generator_c) % l_generator_m;
}

// Function to initialize the engine with default settings
static void initialize_engine(Engine *f_engine) {
    f_engine->idle_speed = 800;  // Default idle speed in RPM
    f_engine->is_running = false;
}

// Function to start the engine
static void start_engine(Engine *f_engine)
{
    f_engine->is_running = true;
}

// Function to stop the engine
void stop_engine(Engine *f_engine) 
{
    f_engine->is_running = false;
}

// Function to set a new idle speed
static void set_idle_speed(Engine *f_engine, int f_speed)
 {
    if (f_engine->is_running) 
    {
        f_engine->idle_speed = f_speed;
    } else {
        f_engine->idle_speed = f_speed;
    }
}

// Function to log the current idle speed
static void log_idle_speed(int f_idle_speed)
{
    g_idle_speed = f_idle_speed;
}

// Simulate dynamic condition changes that might affect idle speed
int simulate_conditions(unsigned int *f_seed) 
{
    // Generate a pseudo-random idle speed between 800 and 1000 RPM
    int l_min_speed = 800;
    int l_max_speed = 1000;
    unsigned int l_rand_val = *f_seed;
    *f_seed = l_rand_val;  // Update seed
    return (l_rand_val % (l_max_speed - l_min_speed + 1)) + l_min_speed;
}
// Simulate managing the idle speed in real-time
int manage_engine_idle_speed() 
{
    static Engine l_engine;
    if (!g_initialized) 
    {
        initialize_engine(&l_engine);
        start_engine(&l_engine);
        set_idle_speed(&l_engine, 900); // Set initial idle speed to 900 RPM
        g_initialized = true;
    }
    if (l_engine.is_running)
    {
        // Manage idle speed in a loop
        for (int l_i = 0; l_i < 5; ++l_i)
        {
            int l_new_idle_speed = simulate_conditions(&g_seed);
            set_idle_speed(&l_engine, l_new_idle_speed);  // Adjust idle speed based on simulated conditions
            log_idle_speed(l_engine.idle_speed);           // Log the current idle speed
            sleep(1); // Simulate a real-time delay
            // Simulate a potential error condition
            if (g_seed % 10 == 0) {  // Custom error condition based on pseudo-random number
                stop_engine(&l_engine);
            }
        }
        
        g_initialized = false; // Reset initialization status for future calls
    } 
    else
    {
        g_initialized = false;
    }
    return l_engine.idle_speed; // Return the final idle speed
}
void start_transmission_control_simulation()
 {
    VehicleStatus l_vehicleStatus = {0};
    TransmissionState l_transmissionState = {PARK, ON};

    // Call simulateRealTimeUpdate from transmission_control.c
    simulateRealTimeUpdate(&l_vehicleStatus, &l_transmissionState);
}
