[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Arduino-based-GPS-Monitoring-with-Bot-of-Things)
![Project](https://img.shields.io/badge/Project-Bot%20of%20Things-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# Arduino-based-GPS-Monitoring-with-Bot-of-Things
<strong>Solo Project: Arduino-based GPS Monitoring with Bot of Things</strong><br><br>
This project was created as an effort to increase security on personal belongings. The position of the items can be monitored at any time through the telegram bot, so that the items will not be easily stolen. If someone loses an item, as long as the GPS is still installed and can function properly, then its position will be tracked immediately. In this project, the Arduino Pro Micro is tasked with holding the coordinate data. The data collected is then sent to the Wemos D1 Mini via UART: Hardware Serial. The data received by the Wemos D1 Mini via UART: Software Serial is called raw data. This raw data will later be processed into data that is useful for Telegram Bot purposes. Telegram bots will only respond to users if there is interaction.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | Arduino Pro Micro Leonardo ATMEGA32U4 |
| Supporting Board | Wemos D1 Mini |
| Code Editor | Arduino IDE |
| Application Support | Telegram Bot |
| Driver | USB-Serial CH340 |
| Communications Protocol | • Universal Asynchronous Receiver-Transmitter (UART)<br>• MTProto |
| Programming Language | C/C++ |
| Arduino Library | • SoftwareSerial (default)<br>• TinyGPS++<br>• CTBot<br>• ArduinoJson |
| Sensor | GPS NEO6MV2 (x1) |
| Other Components | • Micro USB cable - USB type A (x1)<br>• Jumper cable (1 set)<br>• Li-ion battery 18650 5V (x1)<br>• 1-Slot battery holder (x1)<br>• Micro USB cable - 2 pin JST (x1) |

<br><br>

## Download & Install
1. Arduino IDE

   <table><tr><td width="810">
         
   ```
   https://www.arduino.cc/en/software
   ```

   </td></tr></table><br>
   
2. USB-Serial CH340

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CH340_Driver
   ```
   
   </td></tr></table>
   
<br><br>

## Project Designs
<table>
<tr>
<th width="420">Block Diagram</th>
<th width="420">Pictorial Diagram</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/36c483ca-9e5f-4d9d-aed3-95c02a0c73b5" alt="Block-Diagram"></td>
<td><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/449a79ca-d05f-4e41-a063-4cbfa5a4221b" alt="Pictorial-Diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/ca52fea1-8949-4ed9-a398-1ee70edbe938" alt="Wiring"></td>
</tr>
</table>

<br><br>

## Basic Knowledge
Basically, a device can be communicated with other devices either wirelessly or by cable. Communication between commonly used hardware is ``` Serial Communication ```. It can be known that there are three types of ``` Serial Communication ```, which include: ``` UART (Universal Asynchronous Receiver-Transmitter) ```, ``` SPI (Serial Peripheral Interface) ```, and ``` I2C (Inter Integrated Circuit) ```. ``` Serial UART communication ``` allows each device to act as a ``` master ``` or ``` slave ``` in a limited way. ``` Master ``` is the primary device that has full authority over the control of the Slave, while the ``` Slave ``` is the secondary device that is under the authority of the Master device. There are two kinds of ``` UART Serial Communication ```, namely ``` Hardware Serial ``` and ``` Software Serial ```. ``` Hardware serial communication ``` can be done by connecting the ``` TX ``` and ``` RX ``` pins ``` crosswise ``` on each development board, for example: ``` RX-TX ```, then ``` TX-RX ```. The ``` TX ``` pin is for ``` sending data ```, while the ``` RX ``` pin is for ``` receiving data ```. ``` Serial Software Communication ``` is more or less the same as ``` Serial Hardware Communication ``` in terms of cabling, but there are differences in terms of coding. By using this ``` Serial Software ``` you can overcome the constraints of the limitations of ``` RX ``` and ``` TX ``` pins on the development board. To communicate with this ``` Serial Software ``` is quite easy, namely by using certain ``` Digital Pins ``` as a ``` substitute for TX pins and RX pins ```.<br><br>

The ``` Arduino Pro Micro ``` has several pins that can support ``` Software Serial ``` which include :

<table width="840">
   <tr>
      <th width="420">Pin Name</th>
      <th width="420">Support</th>
   </tr>
   <tr>
      <td>8</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>9</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>10</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>16</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>14</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>15</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>Other Digital pins</td>
      <td>TX only</td>
   </tr>
</table><br><br>

The ``` Wemos D1 Mini ``` has several pins that can support ``` Software Serial ``` which include :

<table width="840">
   <tr>
      <th width="420">Pin Name</th>
      <th width="420">Support</th>
   </tr>
   <tr>
      <td>D0</td>
      <td>TX only</td>
   </tr>
   <tr>
      <td>D1</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D2</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D3</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D4</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D5</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D6</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D7</td>
      <td>RX and TX</td>
   </tr>
   <tr>
      <td>D8</td>
      <td>RX and TX</td>
   </tr>
</table>

<br><br>

## Arduino IDE Setup
1. Open the ``` Arduino IDE ``` first, then open the project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
   
      • ``` APmicro_gpstracker.ino ```
      
      • ``` WD1mini_bot.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
      
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
   
      ```
      http://arduino.esp8266.com/stable/package_esp8266com_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      How to setup the ``` Arduino Pro Micro ``` board
   
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Board ``` -> ``` Arduino AVR Boards ``` -> ``` Arduino Micro ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      How to setup the ``` Wemos D1 Mini ``` board
            
      </th></tr>
      <tr><td colspan="2">

      • Click ``` Tools ``` section -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` esp8266 ```.

      • Then click ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Boards ``` -> ``` Wemos D1 Mini ```.
            
      </td></tr>
   </table><br>
   
4. ``` Change the Board Speed ``` in Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      How to change the speed of ``` Arduino Pro Micro ``` board
   
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 9600 ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      How to change the speed of ``` Wemos D1 Mini ``` board
            
      </th></tr>
      <tr><td colspan="2">

      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```
            
      </td></tr>
   </table><br>
   
5. ``` Install Library ``` in Arduino IDE

   <table><tr><td width="810">
         
      Download all the library zip files. Then paste it in the: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Port Setup ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Port ``` -> Choose according to your device port ``` (you can see in device manager) ```

   </td></tr></table><br>

7. Change the ``` WiFi Name ```, ``` WiFi Password ```, and so on according to what you are currently using.<br><br>

8. Before uploading the program please click: ``` Verify ```.<br><br>

9. If there is no error in the program code, then please click: ``` Upload ```.<br><br>

10. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` others ``` section.

<br><br>

## Telegram Bot Setup
1. Open <a href="https://t.me/botfather">@BotFather</a>.<br><br>

2. Type ``` /newbot ```.<br><br>

3. Type the desired bot name, for example: ``` personalgps_bot ```.<br><br>

4. Type the desired bot username, for example: ``` personalgps_bot ```.<br><br>

5. Also do it for bot image settings, bot descriptions, and so on according to your needs.<br><br>

6. Copy ``` your telegram bot API token ``` -> then paste it into the ``` #define botToken "YOUR_API_BOT_TOKEN" ``` section. 

   <table><tr><td width="810">
      
   For example :

   ```
   #define botToken "2006772150:AAE6Fdjk3KbiySkzV6CLbd6ClJDzgTfJ5y0"
   ```
   
   </td></tr></table><br><br>

## Get Started
1. Download and extract this repository.<br><br>
   
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
   
4. Configure your device according to the settings above.<br><br>

5. Please enjoy [Done].

<br><br>

## Demonstration of Application
Via Telegram: <a href="https://t.me/personalgps_bot">@personalgps_bot</a>

<br><br>

## Highlights
<table>
<tr>
<th width="840">GPS Device</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/871ea86c-e63b-4304-a211-9a3bd9b4cf53" alt="gps_device"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Telegram Bot</th>
</tr>
<tr>
<td width="420"><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/73de4858-b062-4b4c-8457-c7bfe08684e7" alt="telegram_bot1"></td>
<td width="420"><img src="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/assets/54527592/c6c7e0da-c522-4be8-9e0b-b0dbaa6223cc" alt="telegram_bot2"></td>
</tr>
</table>

<br><br>

## Component Testing
You can download the component test file via the following link: <a href="https://github.com/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication/tree/master/Assets/Component%20Testing">Click Here</a>

<br><br>

## Disclaimer
This application has been created by including third-party sources. Third parties here are service providers, whose services are in the form of libraries, frameworks, and others. I thank you very much for the service. It has proven to be very helpful and implementable.

<br><br>

## LICENSE
MIT License - Copyright © 2024 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.
