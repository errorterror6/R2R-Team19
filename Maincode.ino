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
void sensor_information(int *p_front, int *p_left, int *p_right);
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
  // Retrieve sensor information, store as front,left,right(cm)
  int front;
  int left;
  int right;

  int *p_front = &front;
  int *p_left = &left;
  int *p_right = &right;

  sensor_information(p_front, p_left, p_right);


  // Print sensor information

  sensor_print(front, left, right);

  // Look for user input

  //TO DO ALEX: write code to receive user input.

  // Output motor controls

  motor_control(instruction);
  
  delay(10);

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
  //TO DO MARTIN: initialise motor pins
}

void sensor_information(int *p_front, int *p_left, int *p_right){
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin
  duration1 = pulseIn(frontEcho, HIGH);
  duration2 = pulseIn(leftEcho, HIGH);
  duration2 = pulseIn(rightEcho, HIGH);
  // Calculating the distance
  *p_front = duration1 * 0.034 / 2;
  *p_left = duration2 * 0.034 / 2;
  *p_right = duration3 * 0.034 / 2;

  //resetting all the pins
  duration1 = pulseIn(frontEcho, LOW);
  duration2 = pulseIn(leftEcho, LOW);
  duration2 = pulseIn(rightEcho, LOW);
}

void sensor_print(int front, int left, int right){
  //TO DO ALEX: print the output. front = front distance(cm), left = left distance etc.
}

void motor_control(char instruction){
  //TO DO MARTIN: given instruction (WASD, 012345), control the motors.
}


