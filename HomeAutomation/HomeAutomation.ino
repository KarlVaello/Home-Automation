// Basic Bluetooth sketch HC-05_02_38400
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on.
// Needs to be placed in to AT mode
// After a factory reset the default baud rate for communication mode is 38400
//
//
//  Pins
//  BT VCC to Arduino 5V out.
//  BT GND to GND
//  BT RX to Arduino pin 3 (through a voltage divider)
//  BT TX to Arduino pin 2 (no need voltage divider)

#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
char c = ' ';
int ledPin = 13; // usamos un pin de salida al LED
int state = 0; // Variable lectrura serial
void setup()
{
  // start th serial communication with the host computer
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   //Declara pin de Salida
  BTserial.begin(38400);
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTserial.available())
  {
    c = BTserial.read();
    state = c;
    Serial.println(c);
  }

  if (state == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: off");
    BTserial.println("LED: off");

    state = ' ';

  }

  // de lo contrario si el estado es 1 ese sería Encendido “ON”
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: on");
    BTserial.println("LED: on");
    state = ' ';
  }

}


