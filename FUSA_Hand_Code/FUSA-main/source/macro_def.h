// macro.h
#define COMPONENT_OFF 0
#define COMPONENT_ON 1

#define SPEED_THRESHOLD_LOW 5
#define SPEED_THRESHOLD_HIGH 20
#ifndef MACRO_H
#define MACRO_H

// Function prototypes
int addfunction(int f_varA, int f_varB);
int subfunction(int f_varA, int f_varB);
int manageVehicleComponents(int f_mode);
#define MODE_PARK 0
#define MODE_DRIVE 1
#define MODE_REVERSE 2
#endif // MACRO_H
