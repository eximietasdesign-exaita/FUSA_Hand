#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function in a real-time simulation
#include "../include/engine_management.h"

unsigned int g_seed = 12345;

//Function Prototypes
static void updateTransmissionState(TransmissionState *state, GearPosition gear, TransmissionMode mode);
static bool shouldShiftUp(const VehicleStatus *status);
static bool shouldShiftDown(const VehicleStatus *status);
static void shiftGear(TransmissionState *state, GearPosition newGear);
static void control_transmission_shift(VehicleStatus *status, TransmissionState *state);

//Global Variables
int g_status_rpm = 0;
int g_status_speed = 0;
int g_status_throttle_position = 0;
int g_state_current_gear = 0;
int g_status_engine_idle_speed = 0;

void updateVehicleStatus(VehicleStatus *f_status) {
    // Simulate reading from sensors using pseudo-random values
    f_status->rpm = 2000 + (pseudo_random(g_seed) % 5000); // Random RPM between 2000 and 7000
    f_status->speed = pseudo_random(g_seed) % 100;         // Random speed between 0 and 99
    f_status->throttlePosition = pseudo_random(g_seed) % 100; // Random throttle position between 0 and 99
    
    // Update engine idle speed
    f_status->engineIdleSpeed = manage_engine_idle_speed(); // Assumes this function is available and works as expected
}

static void updateTransmissionState(TransmissionState *f_state, GearPosition f_gear, TransmissionMode f_mode) {
    f_state->currentGear = f_gear;
    f_state->transmissionMode = f_mode;
}

static bool shouldShiftUp(const VehicleStatus *f_status) {
    return (f_status->rpm > SHIFT_POINT_UP);
}

static bool shouldShiftDown(const VehicleStatus *f_status) {
    return (f_status->rpm < SHIFT_POINT_DOWN);
}

static void shiftGear(TransmissionState *f_state, GearPosition f_newGear) {
    if (f_state->currentGear != f_newGear) {
        // Optionally log the shift
        f_state->currentGear = f_newGear;
    }
}

static void control_transmission_shift(VehicleStatus *f_status, TransmissionState *f_state) {
    if (f_state->transmissionMode == OFF) {
        return; // Transmission is off. No shifting possible.
    }

    switch (f_state->currentGear) {
        case PARK:
            if (f_status->throttlePosition > 0 && f_status->speed > 0) {
                updateTransmissionState(f_state, DRIVE, f_state->transmissionMode);
            }
            break;
        case REVERSE:
            if (f_status->throttlePosition == 0 && f_status->speed == 0) {
                updateTransmissionState(f_state, NEUTRAL, f_state->transmissionMode);
            }
            break;
        case NEUTRAL:
            if (f_status->throttlePosition > 0 && f_status->speed > 0) {
                updateTransmissionState(f_state, DRIVE, f_state->transmissionMode);
            } else if (f_status->throttlePosition == 0 && f_status->speed == 0) {
                updateTransmissionState(f_state, PARK, f_state->transmissionMode);
            }
            break;
        case DRIVE:
            if (shouldShiftUp(f_status)) {
                if (f_state->currentGear < NUM_GEARS - 1) {
                    shiftGear(f_state, f_state->currentGear + 1);
                }
            } else if (shouldShiftDown(f_status)) {
                if (f_state->currentGear > 0) {
                    shiftGear(f_state, f_state->currentGear - 1);
                }
            }
             break;
            default:
            //no operation performed
            break;
    }
}
void simulateRealTimeUpdate(VehicleStatus *f_status, TransmissionState *f_state) 
{
    updateVehicleStatus(f_status);
    control_transmission_shift(f_status, f_state);
    g_status_rpm = f_status->rpm;
    g_status_speed = f_status->speed;
    g_status_throttle_position = f_status->throttlePosition;
    g_state_current_gear = f_state->currentGear;
    g_status_engine_idle_speed = f_status->engineIdleSpeed;
    sleep(1); // Sleep for 1 second to simulate real-time updates
}
