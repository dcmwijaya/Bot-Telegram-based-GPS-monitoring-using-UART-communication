#include <SoftwareSerial.h>
static const int Rx_pin = 9; // 9 As RX Arduino Pro Micro
static const int Tx_pin = 8; // 8 As TX Arduino Pro Micro
SoftwareSerial mySerial(Rx_pin,Tx_pin);
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
}
void loop(){
  mySerial.print("hello Master");
  delay(5000);

  if(mySerial.available()> 0){
    String data="";
    while(mySerial.available()> 0){ data += char(mySerial.read()); }
    delay(1000);
    Serial.println(data);
  }
}
