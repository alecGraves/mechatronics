String recieved;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lightControl();
}

void lightControl()
{
  //read  in a value
  int in(Serial.read());

  // print out valid values recieved
  if (in != -1)
  {
    // wait for message to load
    delay(10);

    // get the rest of the message
    while(in != -1)
    {
      // print recieved value
      recieved += (char)in;
  
      // read in a value from serial
      in = Serial.read();
    }
    
    if (recieved[0] == 'q')
    {
      recieved = "Message Recieved: " +
        recieved + 
        "\nPotentiometer: " +
        String(analogRead(A0)) + 
        "\nDistance Sensor: " + 
        String(analogRead(A1));
      digitalWrite(13, HIGH);
    }
    else
    {
      recieved = "Message Recieved: " + recieved;
      digitalWrite(13, LOW);
    }
    Serial.print(recieved);

    recieved = "";
  }
  delay(1);
}

void twoWayExample()
{
  //read  in a value
  int in(Serial.read());

  // print out valid values recieved
  if (in != -1)
  {
    // flash the led, wait for message to load
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);

    // get the rest of the message
    while(in != -1)
    {
      // print recieved value
      recieved += (char)in;
  
      // read in a value from serial
      in = Serial.read();
    }
    
    Serial.print(recieved);
    recieved = "";
  }
  delay(1);
}
