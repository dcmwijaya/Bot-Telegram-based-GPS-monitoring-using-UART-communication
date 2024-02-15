#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
SoftwareSerial maps(12, 13); // D6 As RX, D7 As TX -> Wemos D1 Mini

// Method: setup
void setup() {
  Serial.begin(115200); // start serial communication internally
  maps.begin(115200); // start serial communication externally  
}

// Method: loop
void loop() {  
  gpssensor(); // calling the gpssensor method
}

// Method: gpssensor
void gpssensor(){
  while(!maps.available()){ Serial.println("Failed to get sensor data, system tries to reconnect communication !!"); } // serial communication with the Arduino Pro Micro board failed
  Serial.println("Retrieve serial data from Arduino Pro Micro board..."); // display data to the Wemos D1 Mini serial monitor
  delay(2000); // delay -> 2 second 
  String location = ""; // this String data type is used to store location data
  while(maps.available() > 0){ // this loop is used to read the available location data from the serial object
    location += char(maps.read()); // adds each sensor data reading into a data string named location
  }  
  Serial.println(location); // print location data on the serial monitor
  delay(1000); // delay -> 1 second 
}
