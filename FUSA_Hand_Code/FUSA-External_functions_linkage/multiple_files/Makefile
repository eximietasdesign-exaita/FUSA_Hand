# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source directories
MAIN_DIR = main
SRC_DIR = src
SENSOR_DATA_DIR = sensorData
INFOTAINMENT_DIR = Infotainment
BCM_DIR = bcm
CCM_DIR = ccm
PARKINGMODULE_DIR=ParkingModule
PARKING_DIR =parking
ENGINE_MANAGEMENT_DIR =Engine_Management
TRANSMISSION_CONTROL_DIR = Transmission_control
ENGINE_CONTROL_DIR = Engine_Control
SPEED_CONTROL_DIR = Speed_Control
MONTHLYLEAVECOUNT_DIR =MonthlyLeaveCount


# Output binary
OUTPUT = multiProgram

# Object files
OBJS =$(MONTHLYLEAVECOUNT_DIR)/salary_calculation.o $(MONTHLYLEAVECOUNT_DIR)/employee_processing.o $(SPEED_CONTROL_DIR)/Speed_Control.o $(ENGINE_CONTROL_DIR)/Engine_Control.o $(TRANSMISSION_CONTROL_DIR)/transmission_control.o $(ENGINE_MANAGEMENT_DIR)/engine_management.o $(PARKING_DIR)/p_sensor.o $(PARKINGMODULE_DIR)/Parking_sensor.o $(MAIN_DIR)/arithmetic.o $(CCM_DIR)/ClimateControlModule.o $(SRC_DIR)/sub.o $(SENSOR_DATA_DIR)/sensor.o $(INFOTAINMENT_DIR)/audio.o $(BCM_DIR)/bodyControlModule.o

# Default target
all: $(OUTPUT)

# Rule to link the object files and create the final executable
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile salary_calculation.c
$(MONTHLYLEAVECOUNT_DIR)/salary_calculation.o: $(MONTHLYLEAVECOUNT_DIR)/salary_calculation.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile engine_management.c
$(ENGINE_MANAGEMENT_DIR)/engine_management.o: $(ENGINE_MANAGEMENT_DIR)/engine_management.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile arithmetic.c
$(MAIN_DIR)/arithmetic.o: $(MAIN_DIR)/arithmetic.c
	$(CC) $(CFLAGS) -c $< -o $@

 # Rule to compile employee_processing.c
$(MONTHLYLEAVECOUNT_DIR)/employee_processing.o: $(MONTHLYLEAVECOUNT_DIR)/employee_processing.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile sub.c
$(SRC_DIR)/sub.o: $(SRC_DIR)/sub.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile sensor.c
$(SENSOR_DATA_DIR)/sensor.o: $(SENSOR_DATA_DIR)/sensor.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile audio.c
$(INFOTAINMENT_DIR)/audio.o: $(INFOTAINMENT_DIR)/audio.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile bodyControlModule.c
$(BCM_DIR)/bodyControlModule.o: $(BCM_DIR)/bodyControlModule.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to compile ClimateControlModule.c
$(CCM_DIR)/ClimateControlModule.o: $(CCM_DIR)/ClimateControlModule.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to compile Parking_sensor.c
$(PARKINGMODULE_DIR)/Parking_sensor.o: $(PARKINGMODULE_DIR)/Parking_sensor.c
	$(CC) $(CFLAGS) -c $< -o $@  

# Rule to compile p_sensor.c
$(PARKING_DIR)/p_sensor.o: $(PARKING_DIR)/p_sensor.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to compile transmission_control.c
$(TRANSMISSION_CONTROL_DIR)/transmission_control.o: $(TRANSMISSION_CONTROL_DIR)/transmission_control.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to compile Engine_Control.c
$(ENGINE_CONTROL_DIR)/Engine_Control.o: $(ENGINE_CONTROL_DIR)/Engine_Control.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to compile Speed_Control.c
$(SPEED_CONTROL_DIR)/Speed_Control.o: $(SPEED_CONTROL_DIR)/Speed_Control.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Clean target to remove compiled files
clean:
	rm -f $(MAIN_DIR)/*.o $(MONTHLYLEAVECOUNT_DIR)/*.o $(MONTHLYLEAVECOUNT_DIR)/*.o $(SPEED_CONTROL_DIR)/*.o $(ENGINE_CONTROL_DIR)/*.o $(TRANSMISSION_CONTROL_DIR)/*.o $(ENGINE_MANAGEMENT_DIR)/*.o  $(PARKING_DIR)/*.o $(SRC_DIR)/*.o $(SENSOR_DATA_DIR)/*.o $(INFOTAINMENT_DIR)/*.o $(CCM_DIR)/*.o $(BCM_DIR)/*.o $(PARKINGMODULE_DIR)/*.o $(OUTPUT)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
