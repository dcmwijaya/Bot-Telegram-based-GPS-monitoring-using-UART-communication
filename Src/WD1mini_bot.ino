// library initialization
#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
SoftwareSerial mcuSerial(12, 13); // D6 As RX, D7 As TX -> Wemos D1 Mini to Arduino Pro Micro

String raw_data, latitude, longitude; // data with String type is used for GPS sensor purposes

// Method: setup
void setup() {
  Serial.begin(115200); // start serial communication inside the Wemos D1 Mini
  mcuSerial.begin(115200); // start serial communication to Arduino Pro Micro
}

// Method: loop
void loop() {  
  gpssensor(); // calling the gpssensor method
}

// Method: gpssensor
void gpssensor(){
  while(!mcuSerial.available()){ Serial.println("Failed to get sensor data, system tries to reconnect communication !!"); } // serial communication with the Arduino Pro Micro board failed
  raw_data = ""; // this String data type is used to store data obtained from serial communication
  while(mcuSerial.available()){ // this loop is used to read the serial communication data from the Arduino Pro Micro
    raw_data += char(mcuSerial.read()); // adds each sensor data reading into a data string named raw_data
  }  
  latitude = getValue(raw_data, ' ', 0); // this variable is used to store latitude data
  longitude = getValue(raw_data, ' ', 1); // this variable is used to store longitude data
  Serial.println("Retrieve serial data from Arduino Pro Micro board..."); // display data to the Wemos D1 Mini serial monitor
  delay(2000); // delay -> 2 second 
  Serial.println(latitude); // print latitude data on the serial monitor
  Serial.println(longitude); // longitude data on the serial monitor
  delay(1000); // delay -> 1 second 
}

// function for data parsing
String getValue(String data, char separator, int index){ // there are 3 parameters: data -> String, separator -> char, index -> int
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
 
  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  } 
 
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
