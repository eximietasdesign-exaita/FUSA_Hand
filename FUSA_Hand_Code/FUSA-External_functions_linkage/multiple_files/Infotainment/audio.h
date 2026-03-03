#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//bool send_over_bluetooth(const char* command, const uint8_t* data, size_t data_size);
//void send_bluetooth_command(const char* command);
// Enumeration for Bluetooth audio controls
typedef enum {
    PLAY = 1,
    PAUSE,
    NEXT_TRACK,
    PREVIOUS_TRACK,
    VOLUME_UP,
    VOLUME_DOWN,
    NOCOMMAND
} BluetoothAudioCommand;
void bluetooth_audio_control(BluetoothAudioCommand command);