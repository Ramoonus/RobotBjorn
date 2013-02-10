#define EngineSpeed 192 
// Recommended: 192 for 5x AA
// Recommended 96 for 1x 9V
// Recommended: 64 over USB
// Min: 0
// Max: 255

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

  // Brake on start
  Brake(); 
  Serial.println('Startup procedure completed');
  Serial.println('Brake initialized');
}

void loop(){
  // do something
}
void Test() {
  // Short test script
  DriveForward(); 
  delay(2500); 
  Brake(); 
  delay(2500);
}

void TestSensor() {
  if (!SensorMiddle() ) { 
    DriveForward(); 
    Serial.println("Go with the flow!" );  
  }
  else { 
    Brake(); 
    Serial.println("Emergency brake");  
  }

  delay(1000);
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
}
// Drive in reverse function
void ReverseLeft() {
  //Motor B backward @ full speed
  digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, EngineSpeed);    //Spins the motor on Channel B at full speed
}
void ReverseRight() {
  //Motor A backwards @ full speed
  digitalWrite(12, LOW); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, EngineSpeed);   //Spins the motor on Channel A at full speed
}
void DriveReverse() {
  ReverseLeft();
  ReverseRight();
}
// Drive specific way function
void DriveLeft() {
  //Motor B forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, EngineSpeed);   //Spins the motor on Channel B at full speed
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
  ReverseLeft();
  DriveRight();
}
// Turn Right
void TurnRight() {
  ReverseRight();
  DriveLeft();
}
// Head Lights 
void HeadLights() {
}
// Brake Light
void BrakeLight(){
}
// Turn Left Light
void LeftLight() {
}
// Turn Right Light
void RightLight() {
}
// Sensor Left
int SensorLeft() {
  if( analogRead(A5) > 512 ) { 
    return 1; 
  } // please select left port
  else return 0; 
}
// Sensor Middle
int SensorMiddle() {
  if( analogRead(A5) > 512 ) { 
    return 1; 
  } // please select middle port
  else return 0; 
}
// Sensor Right
int SensorRight() {
  if( analogRead(A5) > 512 ) { 
    return 1; 
  } // please select right port
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
  Serial.println("Reading on A5");
  Serial.println(analogRead(A5) );
  Serial.println("Reading sensor left function");
  Serial.println(SensorLeft() );
  delay(1000);
}
// Sensor Middle Debug
void SensorMiddleDebug() {
  Serial.println("Reading on A5");
  Serial.println(analogRead(A5) );
  Serial.println("Reading sensor middle function");
  Serial.println(SensorMiddle() );
  delay(1000);
}
// Sensor Right Debug
void SensorRightDebug() {
  Serial.println("Reading on A5");
  Serial.println(analogRead(A5) );
  Serial.println("Reading sensor right function");
  Serial.println(SensorRight() );
  delay(1000);
}


