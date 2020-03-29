#include <Adafruit_LSM303DLH_Mag.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_LSM303DLH_Mag_Unified mag = Adafruit_LSM303DLH_Mag_Unified(12345);

void Compass_setup() {
  Serial.print("\nInitializing Compass... ");
  // Initialise the sensor 
  if (!mag.begin()) {
    // There was a problem detecting the LSM303 ... check your connections
    Serial.println("Failed, no LSM303 detected.");
    Serial.println(" - Check your wiring.");
    while (1);
  }
  Serial.println("Success"); // Print heading after
}

void Compass() {
  /* Get a new sensor event */
  sensors_event_t event;
  mag.getEvent(&event);

  float Pi = 3.14159;

  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y, event.magnetic.x) * 180) / Pi;

  // Normalize to 0-360
  if (heading < 0) {
    return heading = 360 + heading;
  }
}

// Finilize this function
float getCurrentHeading(){
  return 5;
}
