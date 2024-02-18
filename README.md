[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Telegram-Bot-based-GPS-monitoring-with-UART-communication)
![Project](https://img.shields.io/badge/Project-Arduino-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# Telegram-Bot-based-GPS-monitoring-with-UART-communication
This project was created as an effort to increase security on personal belongings. The position of the items can be monitored at any time through the telegram bot, so that the items will not be easily stolen. If someone loses an item, as long as the GPS is still installed and can function properly, then its position will be tracked immediately. In this project, the Arduino Pro Micro is tasked with holding the coordinate data. The data collected is then sent to the Wemos D1 Mini via UART. The data received by the Wemos D1 Mini via UART is called raw data. This raw data will later be processed into data that is useful for Telegram Bot purposes. Telegram bots will only respond to users if there is interaction.

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
<td><img src="" alt="Pictorial-Diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td><img src="" alt="Wiring"></td>
</tr>
</table>

<br><br>

## Basic Knowledge

In general, we can make a device communicate with another device. Communication that is often used is using ``` Serial Communication ```. There are two kinds of serial communication, namely ``` Hardware Serial ``` and ``` Software Serial ```.<br><br>

<strong>1. Hardware Serial Communication</strong>

``` Hardware serial communication ``` can be done by connecting the ``` TX ``` and ``` RX ``` pins ``` crosswise ``` on each development board, for example: ``` RX-TX ```, then ``` TX-RX ```. The ``` TX ``` pin is for ``` sending data ```, while the ``` RX ``` pin is for ``` receiving data ```.<br><br>

<strong>2. Software Serial Communication</strong>

Each development board usually has ``` TX ``` and ``` RX ``` pins. These pins usually vary greatly in number, sometimes there are few, sometimes there are many. So if we want to connect many development boards at once, we cannot use ``` Hardware Serial ```, so what is needed is ``` Software Serial ```. This ``` Software Serial ``` is used to overcome the problem of the ``` limited number of TX pins and RX pins ``` on a development board. To communicate with serial software it is quite easy, namely by using certain ``` Digital Pins ``` as a ``` substitute for TX pins and RX pins ```.<br><br>

The ``` Arduino Pro Micro ``` has several pins that can support ``` Software Serial ``` which include:

<table width="840">
   <tr>
      <th width="210">Pin Name</th>
      <th width="210">Role</th>
      <th width="210">Advantages</th>
      <th width="210">Disadvantages</th>
   </tr>
   <tr>
      <td>2</td>
      <td>RX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>3</td>
      <td>TX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>4</td>
      <td>RX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>5</td>
      <td>TX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>6</td>
      <td>RX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>7</td>
      <td>TX</td>
      <td>Can only transfer data</td>
      <td>Cannot receive data</td>
   </tr>
   <tr>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
   </tr>
   <tr>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
   </tr>
   <tr>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
      <td>Coming Soon</td>
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
<td><img src="" alt="gps_device"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Telegram Bot</th>
</tr>
<tr>
<td width="420"><img src="https://github.com/devancakra/Arduino-Pro-Micro-based-GPS-Monitoring-for-Personal-Items-with-Telegram-Bot/assets/54527592/675c126a-b4b4-4ed2-a1a7-8fe40e7fcc63" alt="telegram_bot1"></td>
<td width="420"><img src="https://github.com/devancakra/Arduino-Pro-Micro-based-GPS-Monitoring-for-Personal-Items-with-Telegram-Bot/assets/54527592/861fdb3b-f822-4b6c-861a-d63118d84511" alt="telegram_bot2"></td>
</tr>
</table>

<br><br>

## LICENSE
MIT License - Copyright © 2024 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.
