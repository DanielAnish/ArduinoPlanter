#include "MoistureSensor.h"

void setup() 
{
  Serial.begin(9600);

  Serial.println("====================== Ardunio Moisture Sensor Test ==============");

  moisture_setup();

  Serial.println("Sensor setup complete. Starting updates .....")
  Serial.println("==============================================")
}

void loop() {
  moisture_update();
}

