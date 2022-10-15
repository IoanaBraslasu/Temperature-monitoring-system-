#include <Wire.h>

// Pin 2-8 is connected to the 7 segments of the display.

int SegA = 2;
int SegB = 3;
int SegC = 4;
int SegD = 5;
int SegE = 6;
int SegF = 7;
int SegG = 8;

// Pins for the control resistances:
int Rez1 = 9;
int Rez2 = 10;

// Pin for the relay:
int relay = 12;

// We define the sensor address:
int SensorAddress = 0x40;

// We initalize the temperature:
int temp;
int byte1;
int byte2;



void setup() {
  //We initialize "Wire.h" library
  Wire.begin();
  
  // We initialize the digital pins as outputs.
  pinMode(SegA, OUTPUT);
  pinMode(SegB, OUTPUT);
  pinMode(SegC, OUTPUT);
  pinMode(SegD, OUTPUT);
  pinMode(SegE, OUTPUT);
  pinMode(SegF, OUTPUT);
  pinMode(SegG, OUTPUT);
  pinMode(Rez1, OUTPUT);
  pinMode(Rez2, OUTPUT);
  pinMode(relay, OUTPUT);

  // Now we want to read on serial the temperature value:
  Serial.begin(9600);
  Serial.print("Temperature Sensor\n\n");
 
}

void loop() {
  // we begin the transmission for the sensor:
  Wire.beginTransmission(SensorAddress);
  Wire.write(byte(0xE3));
  Wire.endTransmission();


  // Now we request the transmitted data from the register above
  Wire.requestFrom(SensorAddress,2);
 
  // We read the temeperatire from the sensor:
  if(Wire.available()<=2) {
     byte1 = Wire.read();
     byte2 = Wire.read();
     
  }
  Serial.print("Octet 1: ");
  Serial.println(byte1);
  Serial.print("octet 2: ");
  Serial.println(byte2);


  temp = -46+ 175 *(byte1*256+byte2)/65536;
  
  int temp1 = temp/10;
  int temp2 =  temp%10;

  Serial.print("Temp: ");
  Serial.println(temp);
  digitalWrite(relay,LOW);

  if (temp>=30)
  {
    digitalWrite(relay,HIGH);

    }

  for( int i = 0; i <150; i = i++)
  {
  disp(temp2,Rez1);   //display digit 1 (most left)
  delay(10);
  digitalWrite(Rez1, LOW);
  disp(temp1, Rez2);   // display digit 2 (second most left)
  delay(10);
  digitalWrite(Rez2, LOW);
  }
  
  

}

// Function that displays the digits
void disp(byte number, int port) {
  digitalWrite(port, HIGH);
  switch (number) {
    case 0:  // print 0
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break;

    case 1:  // print 1
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;

    case 2:  // print 2
      //Serial.println("printed 2");
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;

    case 3:  // print 3
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;

    case 4:  // print 4
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;

    case 5:  // print 5
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;

    case 6:  // print 6
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;

    case 7:  // print 7
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;

    case 8:  // print 8
      //Serial.println("printed 8");
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;

    case 9:  // print 9
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
  }  

}
