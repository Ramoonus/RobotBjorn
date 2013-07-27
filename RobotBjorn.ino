int EngineSpeed = 192;
// Recommended: 192 for 5x AA
// Recommended 96 for 1x 9V
// Recommended: 64 over USB
// Min: 0
// Max: 255

// Sensors
const char SensorLeftPort    = A5;
const char SensorMiddlePort  = A5;
const char SensorRightPort  = A5;

// Piezo Speaker
const char HornPort = A5; 

// Startup Procedure
void setup() {
  // Open Serial Port
  Serial.begin(9600);  



  // Channel A = right engine
  // Channel B = left engine

  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

  // Lights (using shift register)
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  // Turn on Headlights
  HeadLights();

  // Ending pin configuration and other startup routines
  Serial.println('Startup procedure completed');

  // Brake on start
  Brake(); 
  Serial.println('Startup Brake initialized');

  Serial.println("Run keyboard control");
}

// Execute Procedure
void loop(){

  //Test
  //test();

  // Respond to Keyboard
  //KeyboardControl();

  // AutoPilot
  //AutoPilot();

}
void Test() {
  // Forward
  DriveForward(); 
  // Wait
  delay(2500); 
  // Backward
  Brake(); 
  // Wait
  delay(2500);
}

void AutoPilot() {
}

void KeyboardControl(){ 
  if(Serial.available()){
    char val = Serial.read();
    if(val != -1)
    {
      switch(val)
      {
      case 'w'://Move Forward
        //advance (255,255);   //move forward in max speed
        break;
      case 's'://Move Backward
        //back_off (255,255);   //move back in max speed
        break;
      case 'a'://Turn Left
        //turn_L (100,100);        
        break;       
      case 'd'://Turn Right
        //turn_R (100,100);
        break;
      case 'z':
        Serial.println("Hello");
        break;
      case 'x':
        //stop();
        break;
      }
    }
    else ; //stop();  
  }
}

void Gearbox() {
  // Depends motor PWM by 'gear'
  // 0

  // 1

  // 2

  // 3

  // 4

  // 5

  // 6

  // 7

  // 8

  // 9

}


// Brake functions
void BrakeLeft() {
  digitalWrite(8, HIGH);  //Engage the Brake for Channel B
}
void BrakeRight() {
  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
}
void Brake() {
  BrakeLeft(); 
  BrakeRight(); 
  BrakeLight();
}
// Alias stop as brake
void stop() { 
  Brake; 
} 

// Drive in reverse function
void ReverseLeft() {
  //Motor B backward @ full speed
  digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, EngineSpeed);    //Spins the motor on Channel B 
}
void ReverseRight() {
  //Motor A backwards @ full speed
  digitalWrite(12, LOW); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, EngineSpeed);   //Spins the motor on Channel A 
}
void DriveReverse() {
  ReverseLight();
  ReverseLeft();
  ReverseRight();
  ReverseLightOff();
}

// Drive specific way function
void DriveLeft() {
  //Motor B forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, EngineSpeed);   //Spins the motor on Channel B 
}
void DriveRight(){
  //Motor A forward @ full speed
  digitalWrite(12, HIGH);  //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, EngineSpeed);    //Spins the motor on Channel A at half speed
}
void DriveForward() {
  DriveLeft();
  DriveRight();
}
// Turn Left
void TurnLeft() {
  LeftLight(); 
  ReverseLeft();
  DriveRight();
  LeftLightOff();
}
// Turn Right
void TurnRight() {
  RightLight(); 
  ReverseRight();
  RightLightOff();
}

// Sensor Left
int SensorLeft() {
  if( analogRead(SensorLeftPort) > 512 ) { 
    return 1; 
  }
  else return 0; 
}
// Sensor Middle
int SensorMiddle() {
  if( analogRead(SensorMiddlePort) > 512 ) { 
    return 1; 
  }
  else return 0; 
}
// Sensor Right
int SensorRight() {
  if( analogRead(SensorRightPort) > 512 ) { 
    return 1; 
  } 
  else return 0; 
}
// Current Sensing Channel A
int CurrentSenseA() {
  // Max: 3.3 V equals 2A
  // Output: value in mA
  return map( analogRead(A0) , 0, 676, 0, 2000);
}
// Current Sensing Channel B
int CurrentSenseB() {
  // Max: 3.3 V equals 2A
  // Output: value in mA
  return map( analogRead(A1) , 0, 676, 0, 2000);
}
// Sensor Left Debug
void SensorLeftDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorLeftPort );
  Serial.println(analogRead(SensorLeftPort) );
  Serial.println("Reading sensor left function");
  Serial.println(SensorLeft() );
}
// Sensor Middle Debug
void SensorMiddleDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorMiddlePort );
  Serial.println(analogRead(SensorMiddlePort) );
  Serial.println("Reading sensor middle function");
  Serial.println(SensorMiddle() );
}
// Sensor Right Debug
void SensorRightDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorRightPort );
  Serial.println(analogRead(SensorRightPort) );
  Serial.println("Reading sensor right function");
  Serial.println(SensorRight() );
}
// Horn / Beeper 
void Horn() {
  //tone(pin, frequency, duration)  
  tone(HornPort, 262, 1500);
  // Frequency 262 = C4
}
// Head Lights 
void HeadLights() {
  // Enable Headlight left
  // Enable Headlight right
}
// Brake Light
void BrakeLight(){
  // Enable Breaklight left
  // Enable Breaklight right
}
// Turn Left Light
void LeftLight() {
}
// Turn Left Light Off
void LeftLightOff() {
}
// Turn Right Light
void RightLight() {
}
// Turn Right Light
void RightLightOff() {
}
// White lights when in reverse
void ReverseLight(){
}
void ReverseLightOff(){
}


