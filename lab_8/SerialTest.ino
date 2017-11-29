/*
  Serial Call and Response

  This program sends an ASCII A (byte of value 65) on startup and
  repeats that until it gets some data in.  Then it waits for a byte
  in the serial port, and sends three sensor values whenever it gets a
  byte in.

  Thanks to Greg Shakar and Scott Fitzgerald for the improvements

  The circuit:
  * potentiometers attached to analog inputs 0 and 1
  * pushbutton attached to digital I/O 2

  http://www.arduino.cc/en/Tutorial/SerialCallResponse

  Created 26 Sept. 2005
  by Tom Igoe
  Modified 14 April 2009
  by Tom Igoe and Scott Fitzgerald

  Ported to the Maple 27 May 2010
  by Bryan Newbold
*/


int inByte = 0;         // incoming serial byte
char msg = 0;

void setup() {
    pinMode(PB11, INPUT);
    Serial.begin(115200); // Ignored by Maple. But needed by boards using hardware serial via a USB to Serial adaptor
    Serial2.begin(420000);
}

void loop() {
//  Serial.println(Serial2.available());
  int n(10);
  delay(10);
  for (int i(0); i < n; ++i)
  {
    Serial.println((uint8_t)Serial2.read());
  }
  Serial.print('\n');

  while(true)
  {
    delay(10);
  }
//      for (int k(0); k < 96; ++k)
//      {
//        msg=0;
//        for (int i(1); i < 8; ++i)
//        {
//          if (digitalRead(PB11))
//          {
//            msg |= (1 << i);
//          }
//          delayMicroseconds(4);
//        }
//        if (msg != 254)
//          Serial.println((int)msg);
//      }
}
