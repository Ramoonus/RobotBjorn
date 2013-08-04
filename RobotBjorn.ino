// Sensors
const char SensorLeftPin    = A5;
const char SensorMiddlePin  = A5;
const char SensorRightPin  = A5;

// Motor
int EngineSpeed = 128;
// Recommended: 192 for 5x AA, 96 for 1x 9V 64 over USB
// Min: 0  Max: 255
// Channel A = right engine
// Channel B = left engine
const char MotorChannelApin = 12;
const char MotorBrakeApin = 9;
const char MotorChannelAPWMpin = 3;
const char MotorChannelBpin = 13;
const char MotorBrakeBpin = 8;
const char MotorChannelBPWMpin = 11;

// Horn
const char HornPin = 2; 

// Debug
const boolean Debug = false;

// Motherboard
const boolean Due = false; // is this an arduino due?
const boolean Mega = false; // is this an arduino mega?

// Startup Procedure
void setup() {
  // Open Serial Pin
  Serial.begin(9600);  

  //Setup Channel A
  pinMode(MotorChannelApin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MotorBrakeApin, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(MotorChannelBpin, OUTPUT); //Initiates Motor Channel B pin
  pinMode(MotorBrakeBpin, OUTPUT);  //Initiates Brake Channel B pin

  // Sensor
  pinMode(SensorLeftPin, INPUT);
  pinMode(SensorMiddlePin, INPUT);
  pinMode(SensorRightPin, INPUT);

  // Turn on Headlights
  HeadLights();
  TailLights();
  Serial.println('Lights are on');

  // Brake on start
  Brake(); 
  Serial.println('Startup Brake initialized');

  //Serial.println("Run keyboard control");

  // Ending pin configuration and other startup routines
  Serial.println('Startup procedure completed');

}

// Execute Procedure
void loop(){

  //Test
  //test();

  // Respond to Keyboard
  KeyboardControl();

  // AutoPilot
  //AutoPilot(); delay(500);
}
// Test Function
void Test() { 
  // Dance
  DriveForward();
  delay(2500); 
  DriveReverse(); 
  delay(2500);
  TurnLeft();
  delay(2500);
  TurnRight();
  delay(2500);
  Horn();   
  Horn();   
  Horn(); 
  delay(2500);
}

void AutoPilot() {

  if(SensorMiddle() ) {   // On something insight
    Brake();              // Brake
    Serial.println("Stopped because I detected something");
    if (!SensorLeft) { // Look Left
      Serial.println("Going left");
      TurnLeft; 
      delay(500);
      Brake;
    }              

    else if (!SensorRight) { // Or look right 
      Serial.println("Going right");
      TurnRight; 
      delay(500);
      Brake; 
    }          

    else { // Or do nothing
      Horn(); 
      delay(1000);
    }              
  }
  else {
    DriveForward(); 
  }
}

void KeyboardControl(){ 
  if(Serial.available()){
    char val = Serial.read();
    if(val != -1) // if some value inputted 
    {
      switch(val)
      {
      case 'w'://Move Forward
        DriveForward();
        break;
      case 's'://Move Backward
        DriveReverse();
        break;
      case 'a'://Turn Left
        Brake();
        TurnLeft();   
        break;       
      case 'd'://Turn Right
        Brake();
        TurnRight();
        break;
      case 'z':
        Serial.println("Hello");
        break;
      case 'x':
        //stop();
        Brake();
        break;

        // Gearbox
      case '0'://Gear 0
        Gearbox(0);
        break;
      case '1'://Gear 0
        Gearbox(1);
        break;
      case '2'://Gear 0
        Gearbox(2);
        break;
      case '3'://Gear 0
        Gearbox(3);
        break;
      case '4'://Gear 0
        Gearbox(4);
        break;
      case '5'://Gear 0
        Gearbox(5);
        break;
      case '6'://Gear 0
        Gearbox(6);
        break;
      case '7'://Gear 0
        Gearbox(7);
        break;
      case '8'://Gear 0
        Gearbox(8);
        break;
      case '9'://Gear 0
        Gearbox(9);
        break;

      case 't'://Test
        Serial.println("Enabling Test Procedure");
        Test();
        Serial.println("Done");
        break;

      case 'h'://Horn
        Serial.println("Feeling horny?");
        Horn();

        break;
      }


    }
    else ; //stop();  
  }
}

void Gearbox( int gear) {
  // Depends motor PWM by 'gear'
  int  EngineSpeed = map(gear, 0, 9, 0, 255);

  if(Debug) {
    Serial.print("Gear: ");
    Serial.println(gear);
    Serial.print("PWM Speed: ");
    Serial.println(EngineSpeed);
    Serial.print("Percentage power: ");
    Serial.print( EngineSpeed /255 );
    Serial.println("%"); 
  }
}


// Brake functions
void BrakeLeft() {
  digitalWrite(MotorBrakeBpin, HIGH);  //Engage the Brake for Channel B
}
void BrakeRight() {
  digitalWrite(MotorBrakeApin, HIGH);  //Engage the Brake for Channel A
}
void Brake() {
  // Brake
  BrakeLeft(); 
  BrakeRight(); 
  // Brake lights
  BrakeLight();
}

// Drive in reverse function
void ReverseLeft() {
  //Motor B backward @ full speed
  digitalWrite(MotorChannelBpin, LOW);  //Establishes backward direction of Channel B
  digitalWrite(MotorBrakeBpin, LOW);   //Disengage the Brake for Channel B
  analogWrite(MotorChannelBPWMpin, EngineSpeed);    //Spins the motor on Channel B 
}
void ReverseRight() {
  //Motor A backwards @ full speed
  digitalWrite(MotorChannelApin, LOW); //Establishes forward direction of Channel A
  digitalWrite(MotorBrakeApin, LOW);   //Disengage the Brake for Channel A
  analogWrite(MotorChannelAPWMpin, EngineSpeed);   //Spins the motor on Channel A 
}
void DriveReverse() {
  // Lights on
  ReverseLight();
  // Reverse
  ReverseLeft();
  ReverseRight();
  // Lights off
  ReverseLightOff();
}

// Drive specific way function
void DriveLeft() {
  //Motor B forward @ full speed
  digitalWrite(MotorChannelBpin, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBrakeBpin, LOW);   //Disengage the Brake for Channel B
  analogWrite(MotorChannelBPWMpin, EngineSpeed);   //Spins the motor on Channel B 
}
void DriveRight(){
  //Motor A forward @ full speed
  digitalWrite(MotorChannelApin, HIGH);  //Establishes forward direction of Channel A
  digitalWrite(MotorBrakeApin, LOW);   //Disengage the Brake for Channel A
  analogWrite(MotorChannelAPWMpin, EngineSpeed);    //Spins the motor on Channel A at half speed
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
  DriveLeft();
  RightLightOff();
}

// Sensor Left
boolean SensorLeft() {
  if(digitalRead(SensorLeftPin) == LOW) return 1;
  else { 
    return 0;  
  }
}
// Sensor Middle
boolean SensorMiddle() {
  if(digitalRead(SensorMiddlePin) == LOW) return 1;
  else { 
    return 0; 
  }
}
// Sensor Right
boolean SensorRight() {
  if(digitalRead(SensorRightPin) == LOW) return 1;
  else { 
    return 0; 
  }
}
// Current Sensing Channel A
int CurrentSenseA() {
  // Max: 3.3 V equals 2A
  // Output: value in mA
  if(Due) {
    return map( analogRead(A0) , 0, 1023, 0, 2000);
  }
  else {    
    return map( analogRead(A0) , 0, 676, 0, 2000);
  }
}
// Current Sensing Channel B
int CurrentSenseB() {
  // Max: 3.3 V equals 2A
  // Output: value in mA
  if(Due) { 
    return map( analogRead(A1) , 0, 1023, 0, 2000); 
  }
  else {    
    return map( analogRead(A0) , 0, 676, 0, 2000);
  }
}
// Sensor Left Debug
void SensorLeftDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorLeftPin );
  Serial.println(digitalRead(SensorLeftPin) );
  Serial.println("Reading sensor left function");
  Serial.println(SensorLeft() );
}
// Sensor Middle Debug
void SensorMiddleDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorMiddlePin );
  Serial.println(digitalRead(SensorMiddlePin) );
  Serial.println("Reading sensor middle function");
  Serial.println(SensorMiddle() );
}
// Sensor Right Debug
void SensorRightDebug() {
  Serial.println("Reading on ");
  Serial.println( SensorRightPin );
  Serial.println(digitalRead(SensorRightPin) );
  Serial.println("Reading sensor right function");
  Serial.println(SensorRight() );
}
// Horn / Beeper 
void Horn() {
  //tone(pin, frequency, duration)  
  tone(HornPin, 262, 1500);
  // Frequency 262 = C4
}
// Head Lights 
void HeadLights() {
  // Enable Headlight left
  // Enable Headlight right
}
// Tail Lights
void TailLights() {
  // Enable Taillight Left
  // Enable Taillight Right
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





