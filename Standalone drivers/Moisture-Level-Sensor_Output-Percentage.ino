// The following code activates a relay solenoid connected to digital pin 7 that then 
// is activated by an analog capacitive moisture sensor connected to analog pin 0

const int AirValue = 520;    // Value when sensor is in air (dry)
const int WaterValue = 260;  // Value when sensor is in water (wet)
const int relayPin = 7;      // Digital pin connected to the relay module
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);       // open serial port at 9600 bps
  pinMode(relayPin, OUTPUT); // set relay pin as output
  digitalWrite(relayPin, LOW); // make sure relay is off at start
}

void loop() {
  soilMoistureValue = analogRead(A0);  // read the sensor value

  // Map the sensor value to 0-100%
  int moisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  // Constrain to make sure it stays between 0 and 100
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Control the water pump
  if (moisturePercent >= 50) {
    // Soil is wet enough → turn OFF pump
    digitalWrite(relayPin, LOW);  // assuming LOW = relay off
    Serial.println("Pump OFF");
  } else {
    // Soil is dry → turn ON pump
    digitalWrite(relayPin, HIGH); // assuming HIGH = relay on
    Serial.println("Pump ON");
  }

  delay(500); // update every 0.5 seconds
}
