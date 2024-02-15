#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
#include <TinyGPS++.h> // calls a library called TinyGPS++.h

// variable initialization
static const int RXPin = 0, TXPin = 1; // RXD, TXD pin -> Arduino Pro Micro
static const uint32_t GPSBaud = 9600; // baudrate -> 9600
float lat, lng; // data with float type is used for GPS sensor purposes
String lattitude, longitude; // data with String type is used for GPS sensor purposes

// new object initialization
SoftwareSerial APMicroserial(RXPin, TXPin); 
TinyGPSPlus gps;

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication internally
  APMicroserial.begin(GPSBaud); // start serial communication internally
  Serial1.begin(115200); // start serial communication externally 
}

// Method: loop
void loop() {  
  sensor(); // calling the sensor method
}

// Method: view_data
void view_data(){
  // display data to the Arduino Pro Micro serial monitor
  Serial.println("Transmit serial data to Wemos D1 Mini...");
  delay(1000); // delay -> 1 second
  Serial.println("lattitude : " + lattitude);
  Serial.println("longitude : " + longitude);
  delay(1000); // delay -> 1 second
}

// Method: send_data
void send_data(){
  // send data from Arduino Pro Micro to Wemos D1 Mini
  Serial1.print(lattitude);
  Serial1.print(longitude);
  delay(1000); // delay -> 1 second
}

// Method: sensor
void sensor(){
  while(APMicroserial.available() > 0){
    gps.encode(APMicroserial.read());
    
    if (gps.location.isUpdated()){
      lat = (gps.location.lat());
      lng = (gps.location.lng());
    }

    lattitude = String(lat, 6);
    longitude = String(lng, 6);
    
    view_data(); // calling the view_data method
    send_data(); // calling the send_data method
  }
}
