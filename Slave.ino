const int controlButton_IN = 7; //stores the pin number that receives the control button signal from the main arduino
const int leftButton_IN = 6; //stores the pin number that receives the left button signal from the main arduino
const int leftLimitSwitch_IN = 10; //store the pin number that receives input from the left limit switch
const int mainArduino_OUT = 8; //stores the pin number that sends various signals to the main arduino
const int motorDirection_OUT = 3; //stores the pin number that sends a signal to the motor whether to move it left or right
const int motorEngage_OUT = 4; //stores the pin number that sends a signal to the motor whether it is engaged or not
const int motorStep_OUT = 2; //stores the pin number that sends a signal to the motor whether to move or stop it
const int rightButton_IN = 5; //stores the pin number that receives the right button signal from the main arduino
const int rightLimitSwitch_IN = 9; //store the pin number that receives input from the right limit switch

float currentPosition = 0; //stores the current position of the motor
float startPosition = 0; //stores the start position of a cycle
int task = 1; //stores the number of the task that will be executed next
float zeroPosition = 0; //stores the zero position of a cycle

bool displayPosition = false; //signals whether to display the motor's current position or not

void setup()
{
  //Serial
  Serial.begin(9600); //initializes the serial port, then sets the data rate to 9600 bits per second
  Serial.println("Serial port on Slave_Arduino(UNO) initialization succeeded.");

  //Arduino
  Serial.println("Initializing Slave_Arduino(UNO)...");
  pinMode(controlButton_IN, INPUT); //sets controlButton_IN to receive input
  pinMode(leftButton_IN, INPUT); //sets leftButton_IN to receive input
  pinMode(leftLimitSwitch_IN, INPUT); //sets leftLimitSwitch_IN to receive input
  pinMode(mainArduino_OUT, OUTPUT); //sets mainArduino_OUT to send signals
  pinMode(motorDirection_OUT, OUTPUT); //sets motorDirection_OUT to send signals
  pinMode(motorEngage_OUT, OUTPUT); //sets motorEngage_OUT to send signals
  pinMode(motorStep_OUT, OUTPUT); //sets motorStep_OUT to send signals
  pinMode(rightButton_IN, INPUT); //sets rightButton_IN to receive input
  pinMode(rightLimitSwitch_IN, INPUT); //sets rightLimitSwitch_IN to receive input
  digitalWrite(motorEngage_OUT, LOW); //sends a signal to the motor that it is engaged
  Serial.println("Slave_Arduino(UNO) initialization succeeded.");
}

void loop()
{
  while (digitalRead(leftButton_IN) == HIGH) //loops while the left button is being pressed
    stepLeft();

  while (digitalRead(rightButton_IN) == HIGH) //loops while the right button is being pressed
    stepRight();

  if (digitalRead(controlButton_IN) == HIGH) //checks if the control button is being pressed
  {
    switch (task) //switches tasks based on how many times the control button has been pressed
    {
      case 1: //first press, sets that zero position
        zeroPosition = currentPosition;
        Serial.println("The zero position has been set.");
        task++;
        break;
      case 2: //second press, sets the start position
        startPosition = currentPosition;

        if (startPosition <= zeroPosition) //checks if the start position is the same as or to the left of the zero position
        {
          Serial.println("An invalid start position has been set, please try again.");
          digitalWrite(mainArduino_OUT, HIGH); //sends a signal to the main arduino that the start position was invalid
        }
        else //if the start position is to the right of the zero position
        {
          digitalWrite(mainArduino_OUT, LOW); //sends a signal to the main arduino that the zero position was valid
          Serial.println("The start position has been set.");
          task++;
        }

        break;
      case 3: //third and every subsequent press, initiates a cycle
        digitalWrite(mainArduino_OUT, HIGH); //sends a signal to the main arduino that the motor is moving towards the start position
        Serial.println("Moving to start position...");

        while (currentPosition > startPosition) //loops while the motor is to the right of the start position
          stepLeft();

        while (currentPosition < startPosition) //loops while the motor is to the left of the start position
          stepRight();

        delay(100);
        Serial.println("Start position reached.");
        digitalWrite(mainArduino_OUT, LOW); //sends a signal to the main arduino that the start position has been reached
        delay(500);
        digitalWrite(mainArduino_OUT, HIGH); //sends a signal to the main arduino that a cycle is initiating
        Serial.println("Initiating a cycle...");

        while (currentPosition > zeroPosition) //loops while the motor is to the right of the zero position
          stepLeft();

        Serial.println("The cycle has finished.");
        if (displayPosition) //checks if the current position of the motor should be displayed
        {
          Serial.print("Position: ");
          Serial.println(currentPosition);
          displayPosition = false;
        }
        digitalWrite(mainArduino_OUT, LOW); //sends a signal to the main arduino that the cycle has finished
        delay(500);
        digitalWrite(mainArduino_OUT, HIGH); //sends a signal to the main arduino that the motor is moving towards the start position
        Serial.println("Returning to start position...");

        while (currentPosition < startPosition) //loops while the motor is to the left of the start position
          stepRight();

        Serial.println("Start position reached.");
        digitalWrite(mainArduino_OUT, LOW); //sends a signal to the main arduino that the start position has been reached
        break;
      default: //if task is less than 1 or greater than 3
        Serial.println("Error: task on Slave_Arduino(UNO) went out of bounds.");
        Serial.println("Exiting program...");
        delay(200);
        exit(0);
    }

    while (digitalRead(controlButton_IN) == HIGH) //loops while the control button is being pressed
      delay(500);

    delay(500);
  }

  if (displayPosition) //checks if the current position of the motor should be displayed
  {
    Serial.print("Position: ");
    Serial.println(currentPosition);
    displayPosition = false;
  }

  delay(100);
}

void stepLeft()
{
  if (digitalRead(leftLimitSwitch_IN) == HIGH) //checks if the left limit switch isn't being pressed
  {
    digitalWrite(motorDirection_OUT, HIGH); //sends a signal to the motor which directs it left
    digitalWrite(motorStep_OUT, HIGH); //sends a signal to the motor to move it
    delayMicroseconds(15);
    digitalWrite(motorStep_OUT, LOW); //sends a signal to the motor to stop it
    delayMicroseconds(15);
    currentPosition -= 0.1;
    displayPosition = true;
  }
}

void stepRight()
{
  if (digitalRead(rightLimitSwitch_IN) == HIGH) //checks if the right limit switch isn't being pressed
  {
    digitalWrite(motorDirection_OUT, LOW); //sends a signal to the motor which directs it right
    digitalWrite(motorStep_OUT, HIGH); //sends a signal to the motor to move it
    delayMicroseconds(15);
    digitalWrite(motorStep_OUT, LOW); //sends a signal to the motor to stop it
    delayMicroseconds(15);
    currentPosition += 0.1;
    displayPosition = true;
  }
}
