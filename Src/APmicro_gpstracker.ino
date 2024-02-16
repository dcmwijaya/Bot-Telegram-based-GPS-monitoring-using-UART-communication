#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
#include <TinyGPS++.h> // calls a library called TinyGPS++.h

// object initialization
SoftwareSerial mcuSerial(0,1); // RXD, TXD pin -> Arduino Pro Micro to Wemos D1 Mini
SoftwareSerial gpsSerial(2,3); // RXD, TXD pin -> Arduino Pro Micro to GPS Module Sensor
TinyGPSPlus gps;

// variable initialization
float lat, lng; // data with float type is used for GPS sensor purposes
String latitude, longitude; // data with String type is used for GPS sensor purposes

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication inside the Arduino Pro Micro
  Serial1.begin(115200); // start serial communication to Wemos D1 Mini
  mcuSerial.begin(115200); // start serial communication to Wemos D1 Mini
  gpsSerial.begin(9600); // start serial communication to GPS Module Sensor
}

// Method: loop
void loop() {  
  sensor(); // calling the sensor method
}

// Method: sensor
void sensor(){
  while(gpsSerial.available()){ // if there is serial communication from the GPS sensor then
    gps.encode(gpsSerial.read()); // reading GPS data
    if (gps.location.isUpdated()){ // if the GPS location is updated then
      lat = (gps.location.lat()); // this float variable is to hold gps data -> latitude
      lng = (gps.location.lng()); // this float variable is to hold gps data -> longitude
    }
    latitude = String(lat, 6); // this string variable is to hold gps data -> latitude
    longitude = String(lng, 6); // this string variable is to hold gps data -> longitude
  }
//  lat = -7.3364958; lng = 112.6367014; latitude = String(lat, 6); longitude = String(lng, 6); // dummy Data
  view_data(); // calling the view_data method
  send_data(); // calling the send_data method
}

// Method: view_data
void view_data(){
  // display data to the Arduino Pro Micro serial monitor
  Serial.println("Transmit serial data to Wemos D1 Mini...");
  delay(1000); // delay -> 1 second
  Serial.println("latitude : " + latitude);
  Serial.println("longitude : " + longitude);
  delay(1000); // delay -> 1 second
}

// Method: send_data
void send_data(){
  // send data from Arduino Pro Micro to Wemos D1 Mini
  Serial1.println(latitude);
  Serial1.println(longitude);
  delay(1000); // delay -> 1 second
}
