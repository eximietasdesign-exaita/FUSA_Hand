#include <stdio.h>
#include <stdbool.h>

typedef enum {
    DRIVE,
    PARK,
    REVERSE
} GearMode;
//function prototype
void park_car_in_single_function(GearMode f_current_mode, float f_parking_length, float f_parking_width, float f_required_parking_size);