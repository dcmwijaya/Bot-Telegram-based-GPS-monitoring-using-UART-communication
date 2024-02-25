#include <SoftwareSerial.h>
static const int Rx_pin = 0; // D3 As RX Wemos D1 Mini
static const int Tx_pin = 2; // D4 As TX Wemos D1 Mini
SoftwareSerial mySerial(Rx_pin, Tx_pin);
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
}
void loop(){
  mySerial.print("hi Slave");
  delay(5000);
  
  if(mySerial.available()> 0){
    String data="";
    while(mySerial.available()> 0){ data += char(mySerial.read()); }
    delay(1000);
    Serial.println(data);
  }
}
