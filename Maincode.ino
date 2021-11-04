#define echoPin   1
#define frontTrig 2
#define leftTrig  4
#define rightTrig 7

#define rightMLP1 5
#define rightMLP2 6
#define leftMLP1  9
#define leftMLP2  10

void instructions();


void setup() {
  Serial.begin(9600)
  // UI Features, e.g. instructions

  Serial.println("-------------------------------------");
  Serial.println("Team 19 R2R Robot"); 
  Serial.println("Initializing ...");
  Serial.print("Please enter 1 to open instructions, 2 to finish initialisation, 3 to end the program. ");

  while (Serial.available() <= 0){     //infinite loop to wait for buffer.
    int i = 0;
    delay(10);
  }

  if (Serial.available() > 0) {
        incomingByte = Serial.read();

        if (incomingByte == '1'){
          instructions();                   //prints out instructions.
        } else if (incomingByte == '2'){
          int i = 0;
        } else if (incomingByte == '3'){
          exit(0)
        } else {
          Serial.println("Unrecognised instruction. Please enter 1 to open instructions, 2 to finish initialisation, 3 to end the program. ");
        }
    }

  

  // Motor initialisation



  // Sensor initialisation



  //confirmation of initialisation
  Serial.println("Initialisation Complete.");
  

}

void loop() {
  // Retrieve sensor information


  // Print sensor information



  // Look for user input



  // Output motor controls

}


//prints out instructions.
void instructions() {
  Serial.println("Instructions:");
  Serial.println("Movement: Standard WASD Controls, ");
  Serial.println("Press W to move forwards");
  Serial.println("Press S to move backwards");
  Serial.println("Press A to turn left");
  Serial.println("Press D to turn right");

  Serial.println("Speed control: 5 speed system");
  Serial.println("press 0 - 5 for speed");
  Serial.println("0(stopped) ----- 5(full speed)");
}

