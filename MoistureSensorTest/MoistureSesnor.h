#ifdef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H

// This function will be caled in the ardino "setup()" to setup the moisture sensor
void moisture_setup();

// Here this function will be called jsut like "moisture_setup()" to update the values from the sensor
void mositure_update();


// ---- Getter Functions -----
// Fetch the latest calcualted data 
float get_smoothed_moisture();
float get_absorption_rate();

#endif // MOISTURE_SENSOR_H