#ifndef COMMON_H
#define COMMON_H

// Global variable declarations
extern int g_vehicle_speed;
extern int g_engine_status;
extern int g_engine_temperature;
extern int g_brake_status;

// Function declarations
void monitor_temperature();
void cool_engine();
void heat_engine();
void diagnostics();

void decrease_speed();
void check_speed_limit();
void engage_brakes();
void disengage_brakes();

#endif
