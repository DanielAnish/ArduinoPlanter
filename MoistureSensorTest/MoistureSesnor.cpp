#include <Arduino.h>
#include "MoistureSensor.h"
#include <stdio.h>
#include <string.h>


// Enable DEBUG printing
#define DEBUG

const int MOISTURE_SESNOR_PIN = A0;
const int AIR_VALUE = 520;
const int WATER_VALUE = 260;

// INTERNAL STATE VARIABLES
static float smoothed_moisture = 0.0
static float prev_smoothed+moisture = 0.0;
static float absorption_rate = 0.0;
static uint32_t prev_time;


void moisture_setup()
{
  pinMode(MOISTURE_SENSOR_PIN, INPUT);

  int intial_raw_value = analogRead(MOISTURE_SENSOR_PIN);

  smoothed_moisture = map(initial_raw_value, AIR_VALUE, WATER_VALUE, 0, 100);
  smoothed_moisture = constrain(smoothed_moisture, 0, 100)

  prev_smoothed_moisture = smoothed_moisture;

  prev_time = millis();

}

void moisture_update()
{
  const float ALPHA = 0.2;
  const unsigned long SAMPLE_INTERNAL_MS = 250;

  uint32_t current_time = millis()

  if (current_time - prev_time >= SAMPLE_INTERNAL_MS){

    int soilMoistureValue = analogRead(MOISTURE_SENSOR_PIN);

    float current_moisture_pct = map(soilMoistureValue, AIR_VALUE, WATER_VALUE, 0 ,100);
    current_moisture_pct = constrain(current_moisture_pct, 0, 100);

    smoothed_moisture = ALPHA * current_moisture_pct + (1.0 - ALPHA) * prev_smoothed_moisture;


    float dt_seconds = (current_time - prev_time) / 1000.0;
    if(dt_seconds > 0){
      absorption_rate = (smoothed_moisture - prev_smoothed_moisture) / dt_seconds;
    }

    #ifdef DEBUG
      char buffer[100];
      sprintf(buffer, "Moisture: %.2f %% | Rate: %.3f %s\r\n", smoothed_moisture, absorption_rate, "%/s");

      Serial.print(buffer);
    #endif // DEBUG

    prev_smoothed_moisture = smoothed_moisture;
    prev_time = current_time;
  }

}

float get_smoothed_moisture(){
  return smoothed_moisture;
}

float get_absorption_rate(){
  return absoprtion_rate;
}