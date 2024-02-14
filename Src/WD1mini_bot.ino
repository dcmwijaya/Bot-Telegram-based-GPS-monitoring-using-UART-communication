#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
SoftwareSerial maps(12, 13); // D6 As RX, D7 As TX -> Wemos D1 Mini

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication internally
  maps.begin(9600); // start serial communication externally
  while(!maps.available()){ Serial.println("Failed to connect, system is trying to reconnect !!"); } // serial communication with the Arduino Pro Micro board failed
}

// Method: loop
void loop() {  
  Serial.println("Retrieve serial data from Arduino Pro Micro board..."); // display data to the Wemos D1 Mini serial monitor
  delay(2000); // delay -> 2 second  
  String location = ""; // this String data type is used to store location data
  while(maps.available()){ // this loop is used to read the available location data from the serial object
    location += char(maps.read()); // adds each character read into a data string named location
  } 
  Serial.print(location); // print location data on the serial monitor
  location.trim(); // removes spaces at the beginning and end of string data
  delay(1000); // delay -> 1 second
}
