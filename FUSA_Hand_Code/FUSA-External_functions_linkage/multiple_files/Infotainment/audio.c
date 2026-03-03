//audio.c
#include "../Infotainment/audio.h"
static bool send_over_bluetooth(const char* f_command, const uint8_t* f_data, size_t f_data_size);
static void send_bluetooth_command(const char* f_command);
int g_flag;
// Function to control Bluetooth audio PLAY PAUSE NEXT_TRACK PREVIOUS_TRACK VOLUME_UP VOLUME_DOWN
void bluetooth_audio_control(BluetoothAudioCommand f_command) 
{

    switch (f_command) 
    {
        case PLAY:
            send_bluetooth_command("PLAY");
            break;
        case PAUSE:
            send_bluetooth_command("PAUSE");
            break;
        case NEXT_TRACK:
            send_bluetooth_command("NEXT_TRACK");
            break;
        case PREVIOUS_TRACK:
            send_bluetooth_command("PREVIOUS_TRACK");
            break;
        case VOLUME_UP:
            send_bluetooth_command("VOLUME_UP");
            break;
        case VOLUME_DOWN:
            send_bluetooth_command("VOLUME_DOWN");
            break;
        default:
            break;
    }
}

// Mock function to simulate sending data over Bluetooth
static bool send_over_bluetooth(const char* f_command, const uint8_t* f_data, size_t f_data_size)
{
    
    for (size_t l_range = 0; l_range < f_data_size; l_range++) 
    {
        //No Operation
    }
    // Simulating success
    return true;
}

// Function to send Bluetooth commands
static void send_bluetooth_command(const char* f_command) 
{
    if (f_command == NULL) 
    {
        return ;
    }

    // Example of f_command-specific data (can be changed depending on the actual hardware setup)
    uint8_t l_command_data[6];  // Placeholder for f_command-specific data
    memset(l_command_data, 0, sizeof(l_command_data));
    // Simulating data for different commands
    if (strcmp(f_command, "PLAY") == 0) 
    {
        l_command_data[0] = 0x01;  // Example: PLAY f_command byte
    } 
    else if (strcmp(f_command, "PAUSE") == 0)
    {
        l_command_data[0] = 0x02;  // Example: PAUSE f_command byte
    } 
    else if (strcmp(f_command, "NEXT_TRACK") == 0) 
    {
        l_command_data[0] = 0x03;  // Example: NEXT_TRACK f_command byte
    }
     else if (strcmp(f_command, "PREVIOUS_TRACK") == 0) 
    {
        l_command_data[0] = 0x04;  // Example: PREVIOUS_TRACK f_command byte
    } 
    else if (strcmp(f_command, "VOLUME_UP") == 0) 
    {
        l_command_data[0] = 0x05;  // Example: VOLUME_UP f_command byte
    } 
     else if (strcmp(f_command, "VOLUME_DOWN") == 0) 
    {
        l_command_data[0] = 0x06;  // Example: VOLUME_DOWN f_command byte
    } 
    else 
    {
       
        //No operation
    }

    // Send the f_command over Bluetooth
    bool l_result = send_over_bluetooth(f_command, l_command_data, sizeof(l_command_data));
    
    if (l_result) 
    {
    g_flag=l_result;  
    } 
    else
    {
       g_flag=l_result;
    }
}


