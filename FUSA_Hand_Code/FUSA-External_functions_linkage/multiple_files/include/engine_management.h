#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>  // For sleep function (simulates real-time delay)

extern int g_final_speed;
extern unsigned int g_seed;

// Define a struct to represent the Engine
typedef struct {
    int idle_speed;  // Idle speed in RPM
    bool is_running; // Engine status
} Engine;

#define MAX_RPM 7000
#define MIN_RPM 1000
#define SHIFT_POINT_UP 5000
#define SHIFT_POINT_DOWN 3000
#define NUM_GEARS 6

typedef enum {
    PARK,
    REVERSE,
    NEUTRAL,
    DRIVE
} GearPosition;

typedef enum {
    OFF,
    ON
} TransmissionMode;

// vehicle_status.h or wherever VehicleStatus is defined
typedef struct {
    int rpm;
    int speed;
    int throttlePosition;
    int engineIdleSpeed;  // New field for engine idle speed
} VehicleStatus;

typedef struct {
    GearPosition currentGear;
    TransmissionMode transmissionMode;
} TransmissionState;

// Function prototypes
unsigned int pseudo_random(unsigned int f_seed);
int simulate_conditions(unsigned int *f_seed);
int manage_engine_idle_speed();
void start_transmission_control_simulation();
void updateVehicleStatus(VehicleStatus *status);
void stop_engine(Engine *f_engine);
void simulateRealTimeUpdate(VehicleStatus *status, TransmissionState *state);