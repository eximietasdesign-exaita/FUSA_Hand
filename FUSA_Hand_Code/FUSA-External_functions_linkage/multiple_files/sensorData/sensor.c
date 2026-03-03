// Include the header file
#include "../Infotainment/audio.h"
#include "../include/sensor.h"
#include "../ccm/ClimateControlModule.h"
#include "../bcm/bodyControlModule.h"
#include "../include/arithmetic.h"
#include "../include/parking_sensor.h"

static void real_time_delay(int f_seconds);
static void read_sensor_data(SensorData* f_data);
static void process_engine_temp(SensorData* f_data);
static void process_fuel_level(SensorData* f_data);
static void process_speed(SensorData* f_data);
static void apply_brakes(SensorData* f_data);
//static void display_dashboard(SensorData* f_data);
static bool check_safety(SensorData* f_data);


float g_throttle_position = 0.0;  // Throttle position percentage
bool g_engine_on = true;          // Engine status
static void read_sensor_data(SensorData* f_data)
 {
    //Simulate f_data with random values within the valid range
    f_data->engine_temp = MIN_TEMP + (rand() % (int)(MAX_TEMP - MIN_TEMP));
    f_data->fuel_level = MIN_FUEL + (rand() % (int)(MAX_FUEL - MIN_FUEL));
    f_data->speed = MIN_SPEED + (rand() % (int)(MAX_SPEED - MIN_SPEED));
    f_data->brake_status = rand() % 2;  // Randomly simulate brake engagement
   
}

// Function to process engine temperature
static void process_engine_temp(SensorData* f_data) //sec
{
    if (f_data->engine_temp > MAX_TEMP) 
    {
    
        g_engine_on = false;  // Shut down engine for safety
    } else if (f_data->engine_temp < MIN_TEMP) 
    {
        
        g_throttle_position += 5.0;  // Increase throttle to warm up engine
    } 
	else 
	{
       f_data->engine_temp=f_data->engine_temp+10;
    }
}
//8971222222
// Function to process fuel level
static void process_fuel_level(SensorData* f_data) //sec
{
    if (f_data->fuel_level < MIN_FUEL) 
	{
        g_throttle_position = 0.0;  // Reduce throttle to conserve fuel
        g_engine_on = false;        // Optionally shut down engine for safety
    } 
	else 
	{ g_throttle_position = 1.1; // Reduce throttle to conserve fuel
        g_engine_on = true; 
    }
}

// Function to process vehicle speed
static void process_speed(SensorData* f_data) //sec
{
    if (f_data->speed > MAX_SPEED)
		{
        
        g_throttle_position -= 10.0;  // Reduce throttle to slow down the vehicle
    } 
	else 
	{
        g_throttle_position += 10.0; 
    }
}

// Function to apply brakes
static void apply_brakes(SensorData* f_data) //sec
{
    if (f_data->brake_status) 
	{
        g_throttle_position = 0.0;  // Set throttle to zero
        f_data->speed = 0.0;          // Simulate stop
    } 
	else 
	{
         g_throttle_position = 20.0; 
        f_data->speed = 10.0;
    }
}


static bool check_safety(SensorData* f_data) 
{
    bool l_engine_status;
    
    if (!g_engine_on || f_data->fuel_level < MIN_FUEL || f_data->engine_temp > MAX_TEMP) 
    {
        l_engine_status=false;
    }
    else
    {
        l_engine_status=true;
    }

    return l_engine_status;
}
//Simulate real-time delay for sensor f_data acquisition
static void real_time_delay(int f_seconds) 
{
    time_t l_start_time, l_current_time;
    time(&l_start_time);
    do 
    {
    time(&l_current_time);
    } while ((l_current_time - l_start_time) < f_seconds);
}

void readingSensorData()
{
    SensorData l_current_data;
    int l_runtime_seconds =5;  // Run the system for 5 seconds

    //srand(time(0));  // Initialize random number generator
    int l_range;
    for (l_range = 0; l_range < l_runtime_seconds; l_range++)
     {

        // Read and process sensor f_data
        read_sensor_data(&l_current_data);

        // Process the individual subsystems
        process_engine_temp(&l_current_data);
        process_fuel_level(&l_current_data);
        process_speed(&l_current_data);
        apply_brakes(&l_current_data);
       
        // // Display current system status
        // display_dashboard(&l_current_data);
        
        // Wait for real-time delay before reading new sensor f_data
      real_time_delay(1);  // Delay for 1 second
    }
    // Check for safety issues
    if (!check_safety(&l_current_data)) 
    {
    g_engine_on=0;//engine status is going to shut down 
    }
    else
    {
    //Use this key words to test  audio  PLAY PAUSE NEXT_TRACK PREVIOUS_TRACK VOLUME_UP VOLUME_DOWN
     bluetooth_audio_control(PLAY); //interacting with audio.c
    }
     

    /*This function monitors the air quality index (AQI) 
    and performs necessary actions based on the air quality level*/
    monitor_air_quality_sensor(g_resultOfAdd);//Interacting with climatecontrol and input coming from addition.ccm

    int l_current_mode=DRIVE;
    float l_parking_length=10.00;
    float l_parking_width=20.00;
    float l_required_parking_size=12.0;
    
     // Call the single function with the required parameters
     park_car_in_single_function(l_current_mode,l_parking_length,l_parking_width,l_required_parking_size);
}
