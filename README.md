# Temperature-monitoring-system
This project aims to design a greenhouse temperature monitoring and control system by using a HTU21D temperature sensor that is connected to a Intel Galileo gen 2 board. 

## Hardware resources: 
* seven segment display
* 12 V supply
* resistors
* NPN transistors
* command relay
* breadboard
* jumpers
* Intel Galileo gen 2 board

## Software resources:
* Arduino.exe

## Why do you need this project?
The purpose of the system is to maintain a stable temperature in a greenhouse in a certain temperature interval. 
To simulate a temperature change, you should make a heating resistance connected to a command relay that will start to heat when it is connected to a supply. 

![HEAT_RESISTANCE]()
A LED is also added to the heating assembly which will be off when the sensor detects a temperature higher than the desired one and on when the temperature must reach that temperature. To display the monitored temperature, a seven-segment display is used. 