#include <SoftwareSerial.h> // calls a library called SoftwareSerial.h
#include <CTBot.h> // calls a library called CTBot.h

// object initialization
SoftwareSerial mcuSerial(12, 13); // D6 As RX, D7 As TX -> Wemos D1 Mini to Arduino Pro Micro
CTBot myBot; // constructor CTBot
CTBotInlineKeyboard myKbd; // custom inline keyboard object helper

// variable initialization
#define ssid "YOUR_WIFI_NAME" // ssid name
#define password "YOUR_WIFI_PASSWORD" // ssid password
#define botToken "YOUR_API_BOT_TOKEN" // telegram bot API token 
#define gpsCheck "gpsCheck" // callback data sent when "Checking GPS" button is pressed
String location, latitude, longitude; // data with String type is used for GPS sensor purposes
String sendMsg1, sendMsg2; // data with String type is used for telegram bot purposes
unsigned long previousMillis = 0; // will store last time telegram bot was updated
const long interval = 1000; // interval for telegram bot service (milliseconds)

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication inside the Wemos D1 Mini
  mcuSerial.begin(9600); // start serial communication to Arduino Pro Micro
  connectBot(); // calling the connectBot method
  buttonBot(); // calling the buttonBot method
}

// Method: loop
void loop() {  
  gpssensor(); // calling the gpssensor method
  telegrambot(); // calling the telegrambot method
}

// Method: gpssensor
void gpssensor(){
  if(!mcuSerial.available()){ // if serial communication is not connected then do :
    while(!mcuSerial.available()){ Serial.println("The system is waiting for serial communication from the Arduino Pro Micro !!"); } // waiting for serial communication
  }
  if(mcuSerial.available()){ // if serial communication is connected then do :
    location = ""; // this String data type is used to store data obtained from serial communication
    while(mcuSerial.available()){ // this loop is used to read the serial communication data from the Arduino Pro Micro
      location += char(mcuSerial.read()); // adds each sensor data reading into a data string named location
    }  
    location.trim(); // remove existing spaces
    latitude = getValue(location, ',', 0); // this variable is used to store latitude data
    longitude = getValue(location, ',', 1); // this variable is used to store longitude data
    delay(7000); // delay -> 7 second 
  }
  Serial.println("Retrieve serial data from Arduino Pro Micro board..."); // display data to the Wemos D1 Mini serial monitor
  Serial.println("latitude : " + latitude + "\nlongitude : " + longitude + "\n"); // print latitude & longitude data on the serial monitor
}

// function for data parsing
String getValue(String data, char separator, int index){ // there are 3 parameters: data -> string, separator -> character, index -> integer
  int found = 0; // variable with integer type to store found data
  int strIndex[] = {0, -1}; // variable with integer type to store two index values to be used as bounds when extracting substrings from the data string. Initially, strIndex[0] is set to 0, and strIndex[1] is set to -1
  int maxIndex = data.length()-1; // variable with integer type to store the upper limit of the index
 
  for(int i=0; i<=maxIndex && found<=index; i++){ // loop to search data
    if(data.charAt(i)==separator || i==maxIndex){ // if the character at index-i in the data string is equal to a separator character or index-i has reached the end of the string then
        found++; // increases the number of values that have been found during iteration through the string
        strIndex[0] = strIndex[1]+1; // to set the initial border of the substring that will be retrieved
        strIndex[1] = (i == maxIndex) ? i+1 : i; // to set the end limit of the substring to be retrieved
    }
  } 

  // returns a value based on the condition:
  // 1. checks whether the value found is greater than the index. If this condition is true, then the function will return the substring data starting from strIndex[0] to strIndex[1]
  // 2. if the condition is false (meaning the found value is not greater than the index), then the function will return an empty string meaning no value was found at the requested index
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

// Method: connectBot
void connectBot(){
  myBot.wifiConnect(ssid, password); // connect the ESP8266 to the desired ssid
  myBot.setTelegramToken(botToken); // set the telegram bot token
  myBot.setMaxConnectionRetries(5); // try 15 times to connect to the specified ssid
}

// Method: buttonBot
void buttonBot(){
  myKbd.addButton("🌍 Checking GPS", gpsCheck, CTBotKeyboardButtonQuery); // checking gps button
}

// Method: telegrambot
void telegrambot(){
  unsigned long currentMillis = millis(); // to save the current time

  if (currentMillis - previousMillis >= interval) { // if the current time minus the previous time is greater than equal to the interval then
    previousMillis = currentMillis; // previous time is the same as the current time
    
    TBMessage msg; // this variable to store telegram message data
  
    if(myBot.getNewMessage(msg)){ // if there is an incoming message...    
      if(msg.messageType == CTBotMessageText){ // check what kind of message I received
        if(msg.text.equalsIgnoreCase("/start")){ // start
          sendMsg1 = "🙋🏻‍♂️ Hai @" + msg.sender.username + " 👋👋\nWelcome to Personal GPS Bot.\n\n";
          sendMsg1 += "‼️ Please input the secret code\n.................................. *(9 Characters)";
          myBot.sendMessage(msg.sender.id, sendMsg1);
        } 
        else if(msg.text.equalsIgnoreCase("MYGPS2024")){ // code validated successfully
          sendMsg1 = "✅ Code validated successfully";
          myBot.sendMessage(msg.sender.id, sendMsg1);
          sendMsg2 = "To view the item's position via satellite, please click the button below 👇👇";
          myBot.sendMessage(msg.sender.id, sendMsg2, myKbd);
        }
        else { // command not found
          sendMsg1 = "❌ Command not found";
          myBot.sendMessage(msg.sender.id, sendMsg1);
        }
      }
      else if(msg.messageType == CTBotMessageQuery){ // received a callback query message
        if(msg.callbackQueryData.equals(gpsCheck)){ // gps check
          sendMsg1 = "◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎";
          sendMsg1 += "\n◎◎◎◎       🌍 ITEM POSITION       ◎◎◎◎";
          sendMsg1 += "\n◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n";
          sendMsg1 += "🗺️ Latitude :  "+latitude+"\n\n🗺️ Longitude :  "+longitude;
          sendMsg1 += "\n\nTo see the specific position of the object, please click the link below :";
          sendMsg1 += "\n\n◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\nhttps://www.google.com/maps/@"+location;
          sendMsg1 += "\n◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎";
          myBot.sendMessage(msg.sender.id, sendMsg1);
        }
      }
    }
  }
}
