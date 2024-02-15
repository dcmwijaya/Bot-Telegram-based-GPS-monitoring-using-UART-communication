#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
SoftwareSerial APMicroserial(0, 1); // rx, tx -> Arduino Pro Micro

float lat, lng; // data with float type is used for GPS sensor purposes
String lattitude, longitude; // data with String type is used for GPS sensor purposes

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication internally
  Serial1.begin(115200); // start serial communication externally 
}

// Method: loop
void loop() {  
  sensor(); // calling the sensor method
  internal_data(); // calling the internal_data method
  external_data(); // calling the external_data method
}

// Method: sensor
void sensor(){
  // dummy Data
  lat = -7.3364958;
  lng = 112.6367014;
  lattitude = String(lat, 6);
  longitude = String(lng, 6);
}

// Method: internal_data
void internal_data(){
  // display data to the Arduino Pro Micro serial monitor
  Serial.println("Transmit serial data to Wemos D1 Mini...");
  delay(1000); // delay -> 1 second
  Serial.println("lattitude : " + lattitude);
  Serial.println("longitude : " + longitude);
  delay(1000); // delay -> 1 second
}

// Method: external_data
void external_data(){
  // send data from Arduino Pro Micro to Wemos D1 Mini
  Serial1.print(lattitude);
  Serial1.print(longitude);
  delay(1000); // delay -> 1 second
}
