//Pin definitions
const int enablePin = 9;// h-bridge enable pin
const int motorPin1 = 3;// h-bidge pin 3
const int motorPin2 = 4; // h-bridge pin 2
const int zeroSwitch = 8;// limit switch at 0 position
const int encodePin = 2;
const int encodeGround = 11;//encoder ground pin?? why??
const int cupPin = 7;
const int liftPin = 6;
const int lightSensorPin = A0;
const int colorSensor = A1;


//bool n = LOW;

//this could be removed:
volatile bool encoderCState =0; // current encoder state
volatile bool encoderPState =0; // previous encoder state

//this is 
volatile unsigned long lastDebTime = 0; //used for interrupt
volatile int posCount = 0; // tracks current position (with interrupt)
volatile bool mode = true; // tracks current direction

/**
@function 
This function is called when encoder signal changes.

uses posCount to track current position
*/
void EncoderInterrupt() 
{
  encoderCState = digitalRead(encodePin);

  //could remove this if statement:
  //when removed you could change action to 'falling' 
  // or leave as change and divide CurrentAngle by 2
//  if (encoderCState != encoderPState)//a new state
//  {
//    lastDebTime = millis();
//  }

  if ((millis() - lastDebTime) > 1)
  {
    lastDebTime = millis();
    if(mode)
    {
      posCount--;
    }
    else{
      posCount++;
    }
  }
    
}

/**
@function ge the current angle as a float (1 = 1 rotation, .5 = 1/2 rotation)
*/
float CurrentAngle(){
  return float(posCount)/46.4;//23.2;
}

/**
@function swap the direction of the motor by reversing h-bridge signals
*/
void SwapPins(){
  if(mode){
    //clockwise
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    mode = false;
  }
  else{
    //counterclockwise
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    mode = true;
  }
}

/**
@function set the motor speed using analogwrite to enablePin
*/
void SetSpeed(int mSpeed){
  analogWrite(enablePin, min(max(mSpeed, 0), 230));
}

void log(){
  Serial.println(analogRead(colorSensor));
//  Serial.println(analogRead(lightSensorPin));
//  Serial.println(digitalRead(zeroSwitch));
//  Serial.println(CurrentAngle());
}

/**
@function arduino set up
*/
void setup()
{
  lastDebTime = millis();
  
  pinMode(enablePin, OUTPUT);
  pinMode (motorPin1, OUTPUT);
  pinMode (motorPin2, OUTPUT);
  pinMode (encodePin,INPUT);
  pinMode (encodeGround, OUTPUT);
  pinMode (zeroSwitch, INPUT);//switch
  pinMode (cupPin, OUTPUT);
  pinMode (liftPin, OUTPUT);
  pinMode (lightSensorPin,INPUT);
  pinMode (colorSensor,INPUT);

  Serial.begin(9600);
  
  Serial.println("on");
  
 attachInterrupt(digitalPinToInterrupt(encodePin), EncoderInterrupt, CHANGE);

  digitalWrite(encodeGround, LOW);
  SetSpeed(0);
  SwapPins();// clockwise
  SwapPins();// counterclockwise
}


/**
@function arduino main loop
*/
int target = 0;
float average = 0;

void loop() 
{
  
  //move to 0 position and reset posCount
  SetSpeed(160);
  while(digitalRead(zeroSwitch) == HIGH){
    log();
    delay(1);
  }
  SetSpeed(0);
  SwapPins();
  posCount = 0;

  //wait for light sensor reading
  do{
    for (int i = 0; i < 100; ++i)
      average += analogRead(lightSensorPin)/100;
      delay(1);
    log();
    Serial.println("____________________");
    Serial.println(average);
    delay(100);
  }while(average < 0.0001);
  average = 0;

  //lower
  digitalWrite(liftPin, HIGH);
  delay(500);
  //pick up
  digitalWrite(cupPin, HIGH);
  delay(1000);
  //raise
  digitalWrite(liftPin, LOW);
  delay(500);
  
  //Move to the color sensor
  SetSpeed(160);
  while(CurrentAngle()-.10 < -0.001){
    log();
    delay(1);
  }
  SetSpeed(0);
  delay(1000);

  //lower
  digitalWrite(liftPin, HIGH);
  delay(500);

  //read color sensor
  for (int i = 0; i < 100; i++)
  {
    average += analogRead(colorSensor)/100;
    delay(1);
  }
  if (abs(average - 573) < 10){
    target = 0;
  }
  if (abs(average - 539) < 10){
    target = 1;
  }
  if (abs(average - 701) < 10){
    target = 2;
  }

  average = 0
  
  //raise
  digitalWrite(liftPin, LOW);
  delay(500);

  SetSpeed(160);
  switch(target){
    case 0:
      while(CurrentAngle()-.25 < -0.001){
        log();
        delay(1);
      }
      target ++;
      break;
    case 1:
      while(CurrentAngle()-.29 < -0.001){
        log();
        delay(1);
      }
      target ++;
      break;
    case 2:
      while(CurrentAngle()-.30 < -0.001){
        log();
        delay(1);
      }
      target ++;
      break;
    default://case 0, set target to 1
      while(CurrentAngle()-.25 < -0.001){
        log();
        delay(1);
      }
      target ++;
      target = 1;
      break;
  };
  SetSpeed(0);
  SwapPins();
  //lower
  digitalWrite(liftPin, HIGH);
  delay(500);
  digitalWrite(cupPin, LOW);
  delay(10);
  digitalWrite(liftPin, LOW);
  delay(500);
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
@function loop for Parts 2 and 3 of Lab 4 (mostly 3 now)
*/
void part2and3(){
  SetSpeed(0);
  delay(1);
  SwapPins();
  SetSpeed(160);
  while(abs(CurrentAngle()-.15) > .05){
    Serial.println(CurrentAngle());
    delay(10);
  }
  SetSpeed(0);
  delay(500);
  SwapPins();
  SetSpeed(160);
  while(digitalRead(8) == HIGH){
    Serial.println(digitalRead(8));
    delay(10);
  }
  SetSpeed(0);
  delay(500);
}


/**
@function loop for Part 1 of Lab 4
*/
void part1(){
  Serial.println(CurrentAngle());
  delay(10);
  //if ( (abs(CurrentAngle())-1) < 0.05){ //wtf does this not work??
  if ( abs(CurrentAngle()-1) < 0.05 || abs(-1*CurrentAngle()-1) < 0.05){
    posCount = 0;
    digitalWrite(enablePin, LOW);
    delay(500);
    SwapPins();
    SetSpeed(125);
  }

}


/**
@function basic test program for movement
*/
void test()
{
    int motorSpeed = 125;
  analogWrite(enablePin, motorSpeed);
  delay(1000);
  digitalWrite(enablePin, LOW);
//  Serial.println(posCount);
  Serial.println(CurrentAngle());
  delay(500);
//  SwapPins();

  analogWrite(enablePin, motorSpeed);
  delay(500);
  digitalWrite(enablePin, LOW);
  delay(500);
//  Serial.println(posCount);
  Serial.println(CurrentAngle());
//  SwapPins();
}

