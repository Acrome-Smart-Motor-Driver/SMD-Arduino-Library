// ---------------------------------------------------------------------------
//  Example of Acrome SMD Red Getting Module Data with Arduino.
//
//  This code demonstrates how to retrieve data from various modules connected to the 
//  SMD-Red (Smart Motor Driver - Red) using the Acrome-SMD library.
//
//  Example Code by: Berat Eren Dogan / Acrome Robotics
// ---------------------------------------------------------------------------
//  WARNING: To run this code, ensure that you have the following hardware components:
//
//  1. SMD (Smart Motor Driver - Red): Ensure that the SMD is properly connected and powered.
//
//  2. Arduino Gateway: Connect the Arduino Gateway to your Arduino board.
//     Note that the Gateway should NOT be attached while uploading the code.
//
//  3. Various Modules: Connect different modules (Button, Light, Joystick, Distance, QTR, Potentiometer, IMU) to the SMD.
//     Update the respective 'ID' variables for each module in the code accordingly.
//     For simplicity, 'ModuleIDs' is set to 0 for all modules; please adjust the IDs as needed.
//
//  IMPORTANT: Do not have the Gateway attached to your Arduino when uploading the code. 
//  Only attach the Gateway after the code upload is complete. This is crucial for proper initialization.
//  Once the code is uploaded, attach the Gateway and establish the connection with the SMD as required.
//
//  If you encounter any issues, refer to the documentation of your hardware components for troubleshooting steps.
// ---------------------------------------------------------------------------

#include <Acrome-SMD.h>

#define BAUDRATE    115200
#define ID          0 

int ModuleIDs = 1;

Red myRed(ID, Serial3, BAUDRATE);

int buttonVal = 0;
int lightVal  = 0;
int JoystickVal_x = 0;
int JoystickVal_y = 0;
int JoystickVal_button  = 0;
int distanceVal = 0;
int potanitometerVal  = 0;
float Roll_IMU  = 0;
float Pitch_IMU = 0;

void setup() {
  myRed.begin();
  myRed.scanModules();
  myRed.printAvailableSensors(Serial);
}

void loop() {
  //  Button Module get
  buttonVal =   myRed.getButton(ModuleIDs);
  //  Ambient Light Module get
  lightVal  = myRed.getLight(ModuleIDs);
  //  Joystick Module get
  JoystickVal_x =  myRed.getJoystickX(ModuleIDs);
  JoystickVal_y =  myRed.getJoystickY(ModuleIDs);
  JoystickVal_button = myRed.getJoystickButton(ModuleIDs);
  //  Distance Module get
  distanceVal = myRed.getDistance(ModuleIDs);
  //  Reflectance Module get
  QTRValues qtr = myRed.getQTR(ModuleIDs);
  //  Potantiometer Module get
  potanitometerVal = myRed.getPotentiometer(ModuleIDs);
  //  IMU Module get
  Roll_IMU = myRed.getRollAngle(ModuleIDs);
  Pitch_IMU = myRed.getPitchAngle(ModuleIDs);

  delay(50);

  // You can use similar statements to print values for other modules.
  Serial.println(JoystickVal_x);
  Serial.println(JoystickVal_y);
  Serial.println(JoystickVal_button);
  
}