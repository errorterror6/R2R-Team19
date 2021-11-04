#define trigPin   1
#define frontEcho 2
#define leftEcho  4
#define rightEcho 7

#define rightMLP1 5
#define rightMLP2 6
#define leftMLP1  9
#define leftMLP2  10

void instructions();
void initialise_sensors();
void initialise_motors();
void sensor_print(int front, int left, int right);
void motor_control(char instruction);


void setup() {
  Serial.begin(9600)                  //begin Serial Communication
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
  initialise_motors();
  // Sensor initialisation
  initialise_sensors();
  //confirmation of initialisation
  Serial.println("Initialisation Complete.");
  

}

void loop() {
  // Retrieve sensor information
  

  // Print sensor information

  sensor_print(front, left, right);

  // Look for user input



  // Output motor controls

  motor_control(instruction);

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


//instructions to initialise sensors
void initialise_sensors(){
  pinMode(trigPin, OUTPUT); // Sets the TrigPin as an OUTPUT
  pinMode(frontEcho, INPUT); // Sets the front echoPin as an INPUT
  pinMode(leftEcho, INPUT); // Sets the left echoPin as an INPUT
  pinMode(rightEcho, INPUT); // Sets the right echoPin as an INPUT
}

void initialise_motors(){
  
}

void sensor_print(int front, int left, int right){
  
}

void motor_control(char instruction){
  
}


