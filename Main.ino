#include <Adafruit_GFX.h> // Version 1.5.3
#include <Adafruit_TFTLCD.h> // Version 1.0.2
#include <HX711.h> // Version 0.7.4
#include <SD.h>
#include <TouchScreen.h> // Version 1.1.0

/* TFT LCD with Touchscreen Brekout Board
   Source: https://learn.adafruit.com/adafruit-2-8-and-3-2-color-tft-touchscreen-breakout-v2/8-bit-wiring-and-test

   GND ---> Breadboard GND
   Vin ---> Breadboard VLT
   CS  ---> Master Arduino #30
   C/D ---> Master Arduino #31
   WR  ---> Master Arduino #32
   RD  ---> Master Arduino #33
   RST ---> Master Arduino RST
   X+  ---> Master Arduino #34
   Y+  ---> Master Arduino A3
   X-  ---> Master Arduino A2
   Y-  ---> Master Arduino #35
   D0  ---> Master Arduino #22
   D1  ---> Master Arduino #23
   D2  ---> Master Arduino #24
   D3  ---> Master Arduino #25
   D4  ---> Master Arduino #26
   D5  ---> Master Arduino #27
   D6  ---> Master Arduino #28
   D7  ---> Master Arduino #29

*/
#define LCD_CS 30 // LCD CS pin is connected to digital #30
#define LCD_CD 31 // LCD C/D pin is connected to digital #31
#define LCD_WR 32 // LCD WR pin is connected to digital #32
#define LCD_RD 33 // LCD RD pin is connected to digital #33
#define LCD_RST A0 // LCD RST pin is connected to analog 0
#define TS_XP 34 // Touchscreen X+ pin is connected to digital #34
#define TS_YP A3 // Touchscreen Y+ pin is connected to analog 3
#define TS_XM A2 // Touchscreen X- pin is connected to analog 2
#define TS_YM 35 // Touchscreen Y- pin is connected to digital #35
#define TS_PRESSURE_MAX 1000 // The maximum pressure the touchscreen will recognize as an intended press is 1000
#define TS_PRESSURE_MIN 10 // The minimum pressure the touchscreen will recognize as an intended press is 10

/* Micro SD Card Breakout Board Wiring
   Source: https://learn.adafruit.com/adafruit-micro-sd-breakout-board-card-tutorial/arduino-wiring

   5V  ---> Breadboard VLT
   GND ---> Master Arduino GND
   CLK ---> Master Arduino #52
   DO  ---> Master Arduino #50
   DI  ---> Master Arduino #51
   CS  ---> Master Arduino #53

*/
#define SD_CS 53 // SD Card CS pin is connected to digital #53

/* HX711 Load Cell Amplifier Wiring
   Source: https://learn.sparkfun.com/tutorials/load-cell-amplifier-hx711-breakout-hookup-guide/all#hardware-hookup-

    VDD ---> Breadboard VLT
    VCC ---> Breadboard VLT
    DAT ---> Master Arduino #3
    CLK ---> Master Arduino #2
    GND ---> Master Arduino GND

*/
#define LC_DAT 3 // Load Cell DAT pin is connected to digital #3
#define LC_CLK 2 // Load Cell CLK pin is connected to digital #2

/* Master Arduino Wiring

   5V  ---> Breadboard VLT
   GND ---> Breadboard GND
   #46 ---> Slave Arduino #7
   #48 ---> Slave Arduino #5
   #49 ---> Slave Arduino #6

*/
#define OUT_CB 46 // Control Button Out is connected to digital #46
#define OUT_RB 48 // Right Button Out is connected to digital #48
#define OUT_LB 49 // Left Button Out is connected to digital #49

/* Slave Arduino Wiring

   GND ---> Master Arduino GND
   #8  ---> Master Arduino #47
   #4  ---> Microstep Driver ENA+
   #3  ---> Microstep Driver DIR+
   #2  ---> Microstep Driver PUL+

*/
#define IN_SA 47 // Slave Arduino In is connected to digital #47

/* Breadboard Wiring

   GND ---> Left Limit Switch GND
            Right Limit Switch GND
            Left Button GND
            Right Button GND
            Control Button GND
            Microstep Driver ENA-
            Microstep Driver DIR-
            Microstep Driver PUL-
   11e ---> Left Limit Switch VLT
   11d ---> Slave Arduino #10
   11c ---> Breadboard VLT (via resistor)
   13e ---> Right Limit Switch VLT
   13d ---> Slave Arduino #9
   13c ---> Breadboard VLT (via resistor)
   15e ---> Left Button VLT
   15d ---> Master Arduino #4
   15c ---> Breadboard VLT (via resistor)
   17e ---> Right Button VLT
   17d ---> Master Arduino #5
   17c ---> Breadboard VLT (via resistor)
   19e ---> Control Button VLT
   19d ---> Master Arduino #6
   19c ---> Breadboard VLT (via resistor)

*/
#define IN_LB 4 // Left Button In is connected to digital #4
#define IN_RB 5 // Right Button In is connected to digital #5
#define IN_CB 6 // Control Button In is connected to digital #6

// Assigns human-readable names to some common 16-bit color values
#define BLACK 0x0000
#define BLUE 0x001F
#define CYAN 0x07FF
#define WHITE 0xFFFF



char FILENAME[13];
char FILE_NODE[5];
char FILE_PLOT[3];
char FILE_STALK[3];
File DATA_FILE;
HX711 LOAD_CELL;
int16_t BACK_HEIGHT;
int16_t BACK_WIDTH;
int16_t BOX_HEIGHT;
int16_t BOX_WIDTH;
int16_t LCD_HEIGHT;
int16_t LCD_WIDTH;
int16_t OTHER_HEIGHT;
int16_t OTHER_WIDTH;
int16_t SPACE_HEIGHT;
int16_t SPACE_WIDTH;
TSPoint TS_POINT;
uint16_t LCD_ID;
uint16_t THEME_BACKGROUND;
uint16_t THEME_PRIMARY;
uint16_t THEME_SECONDARY;

Adafruit_TFTLCD LCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RST);
float CALIBRATION_FACTOR = -40620; //stores the factor to multiply by the raw load cell data which calibrates the data to be human-readable
int CURRENT_PAGE = 0;
int LCD_ROTATION = 1;
int16_t BOX_RADIUS = 8;
TouchScreen TS = TouchScreen(TS_XP, TS_YP, TS_XM, TS_YM, 300);
uint8_t TEXT_SIZE = 2;

int task = 1; //stores the number of the task that will be executed next
String filename; //stores the name of the file to perform the current task on

void setup()
{
  // Serial
  Serial.begin(9600);
  Serial.println("Serial port initialization succeeded.");

  //Arduino
  Serial.println("Initializing arduino...");
  pinMode(IN_CB, INPUT);
  pinMode(IN_LB, INPUT);
  pinMode(IN_RB, INPUT);
  pinMode(IN_SA, INPUT);
  pinMode(OUT_CB, OUTPUT);
  pinMode(OUT_LB, OUTPUT);
  pinMode(OUT_RB, OUTPUT);
  pinMode(SD_CS, OUTPUT);
  Serial.println("Arduino initialization succeeded.");

  // LCD
  Serial.println("Initializing LCD...");
  LCD.reset();
  LCD_ID = LCD.readID();

  switch (LCD_ID)
  {
    case 0x7575:
    case 0x8357:
    case 0x9325:
    case 0x9328:
    case 0x9341:
      Serial.print("Found ");
      Serial.print(LCD_ID, HEX);
      Serial.println(" LCD driver chip.");
      break;
    default:
      Serial.print("Unknown LCD driver chip: ");
      Serial.println(LCD_ID, HEX);
      deinitialize(EXIT_FAILURE);
  }

  LCD.begin(LCD_ID);
  LCD.setRotation(LCD_ROTATION);
  LCD.fillScreen(BLACK);
  Serial.println("LCD initialization succeeded.");

  //Load Cell
  Serial.println("Initializing load cell...");
  LOAD_CELL.begin(LC_DAT, LC_CLK);
  LOAD_CELL.set_scale(CALIBRATION_FACTOR);
  LOAD_CELL.tare();
  Serial.println("Load cell initialization succeeded.");
  Serial.print("Zero Factor: ");
  Serial.println(LOAD_CELL.read_average());

  // SD Card
  Serial.println("Initializing SD card...");

  if (!SD.begin(SD_CS))
  {
    Serial.println("Error: SD port initialization failed.");
    deinitialize(EXIT_FAILURE);
  }

  Serial.println("SD port initialization succeeded.");

  // Global Variables
  strcpy(FILE_NODE, "0000");
  FILE_NODE[4] = '\0';
  strcpy(FILE_PLOT, "00");
  FILE_PLOT[2] = '\0';
  strcpy(FILE_STALK, "00");
  FILE_STALK[2] = '\0';
  LCD_HEIGHT = LCD.height();
  LCD_WIDTH = LCD.width();
  SPACE_HEIGHT = LCD_HEIGHT / 40;
  SPACE_WIDTH = LCD_WIDTH / 40;
  BACK_HEIGHT = SPACE_HEIGHT * 7;
  BACK_WIDTH = SPACE_WIDTH * 12;
  THEME_BACKGROUND = BLACK;
  THEME_PRIMARY = WHITE;
  THEME_SECONDARY = BLUE;

  setFilename();
  menu();
}

void loop()
{
  /*
  while (digitalRead(IN_LB) == LOW && digitalRead(IN_RB) == HIGH) //loops while only the left button is being pressed
    digitalWrite(OUT_LB, HIGH); //sends a signal to the slave arduino that the left button is being pressed

  digitalWrite(OUT_LB, LOW); //sends a signal to the slave arduino that the left button isn't being pressed

  while (digitalRead(IN_RB) == LOW && digitalRead(IN_LB) == HIGH) //loops while only the right button is being pressed
    digitalWrite(OUT_RB, HIGH); //sends a signal to the slave arduino that the right button is being pressed

  digitalWrite(OUT_RB, LOW); //sends a signal to the slave arduino that the right button isn't being pressed

  if (digitalRead(IN_CB) == LOW) //checks if the control button is being pressed
  {
    switch (task) //switches tasks based on how many times the control button has been pressed
    {
      case 1: //first press, sets the zero position
        Serial.println("CASE 1");
        digitalWrite(OUT_CB, HIGH); //sends a signal to the slave arduino that the control button is being pressed
        Serial.println("The zero position has been set.");
        task++;
        delay(500);
        break;
      case 2: //second press, sets the start position
        Serial.println("CASE 2");
        digitalWrite(OUT_CB, HIGH); //sends a signal to the slave arduino that the control button is being pressed
        delay(500);

        if (digitalRead(IN_SA) == HIGH) //checks if the slave arduino sent a signal that the start position was invalid
          Serial.println("An invalid start position has been set, please try again.");
        else //if the start position was valid
        {
          Serial.println("The start position has been set.");
          task++;
        }

        delay(500);
        break;
      case 3: //third and every other subsequent press, initiates a cycle
        Serial.println("CASE 3");
        getFileName();
        DATA_FILE = SD.open(filename, FILE_WRITE); //opens a file on the SD port with a filename entered by the user for writing

        if (DATA_FILE) //checks if file opened successfully
        {
          Serial.print(filename);
          Serial.println(" opened successfully.");
          task++;
        }
        else //if file didn't open successfully
        {
          Serial.print(filename);
          Serial.println(" couldn't be opened, please try again.");
          break;
        }

        digitalWrite(OUT_CB, HIGH); //sends a signal to the slave arduino that the control button was pressed

        while (digitalRead(IN_SA) == LOW) //loops until the slave arduino sends a signal that the motor is moving towards the start position
          delay(100);

        Serial.println("Moving to start position...");

        while (digitalRead(IN_SA) == HIGH) //loops until the slave arduino sends a signal that the start position has been reached
          delay(100);

        Serial.println("Start position reached.");

        while (digitalRead(IN_SA) == LOW) //loops until the slave arduino sends a signal that a cycle is initiating
          delay(100);

        Serial.println("Initiating a cycle...");

        while (digitalRead(IN_SA) == HIGH) //loops until the slave arduino sends a signal that the cycle has finished
        {
          DATA_FILE.println(LOAD_CELL.get_units(), 3); //writes the data from the load cell into the file
          Serial.println(LOAD_CELL.get_units(), 3);
        }

        DATA_FILE.close();

        Serial.println("The cycle has finished.");

        while (digitalRead(IN_SA) == LOW) //loops until the slave arduino sends a signal that the motor is moving towards the start position
          delay(100);

        Serial.println("Returning to start position...");

        while (digitalRead(IN_SA) == HIGH) //loops until the slave arduino sends a signal that the start position has been reached
          delay(100);

        Serial.println("Start position reached.");
        delay(500);
        break;
      case 4: //fourth and every other subsequent press, displays the contents of a file
        Serial.println("CASE 4");
        getFileName();
        DATA_FILE = SD.open(filename);

        if (DATA_FILE) //checks if file opened successfully
        {
          Serial.print(filename);
          Serial.println(":");

          while (DATA_FILE.available()) //loops until the end of the file is reached
            Serial.write(DATA_FILE.read()); //prints the current line of data from the file to the serial port

          DATA_FILE.close();
          task--;
        }
        else //if file didn't open successfully
        {
          Serial.print(filename);
          Serial.println(" couldn't be opened, please try again.");
        }

        delay(500);
        break;
      default: //if task is less than 1 or greater than 4
        Serial.println("Error: task on Main_Arduino(MEGA) went out of bounds.");
        Serial.println("Exiting program...");
        exit(0);
    }

    while (digitalRead(IN_CB) == LOW) //loops while the control button is being pressed
      delay(500);

    digitalWrite(OUT_CB, LOW); //sends a signal to the slave arduino that the control button isn't being pressed
  }

  delay(100);
  */
}

void getFileName()
{
  byte clearSerial; //stores the current byte of data from the serial port
  Serial.println("Please enter a filename before continuing.");
  filename = "";

  while (true) //loops until a valid filename is entered
  {
    while (filename.length() == 0) //loops while filename is empty
    {
      filename = Serial.readString(); //reads the incoming data from the serial port as string
      filename[filename.length() - 1] = NULL; //clears the newline character from the end of the user input
    }

    if (filename.indexOf(".csv") <= 0 || filename.length() > 13) //checks if filename contains ".csv" or is more than 12 characters with a NULL termination
    {
      Serial.println("An invalid filename has been entered, please try again.");
      filename = "";
    }
    else
      break;
  }

  while (Serial.available() > 0) //loops while there is data from the serial port
    clearSerial = Serial.read(); //clears the data from the serial port one byte at a time
}

void deinitialize(int exitStatus)
{
  Serial.println("Exiting program...");
  delay(100);
  exit(exitStatus);
}

void drawCenterString(const char *string, int16_t text_x, int16_t text_y, uint8_t text_size, uint16_t text_color)
{
  int16_t cursor_x, cursor_y;
  uint16_t text_width, text_height;
  LCD.setTextSize(text_size);
  LCD.setTextColor(text_color);
  LCD.getTextBounds(string, 0, text_y, &cursor_x, &cursor_y, &text_width, &text_height);
  LCD.setCursor(text_x - text_width / 2, text_y - text_height / 2);
  LCD.print(string);
}

void drawString(const char *string, int16_t text_x, int16_t text_y, uint8_t text_size, uint16_t text_color)
{
  int16_t cursor_x, cursor_y;
  uint16_t text_width, text_height;
  LCD.setTextSize(text_size);
  LCD.setTextColor(text_color);
  LCD.getTextBounds(string, 0, text_y, &cursor_x, &cursor_y, &text_width, &text_height);
  LCD.setCursor(text_x, text_y - text_height / 2);
  LCD.print(string);
}

void menu() // PAGE #: 0
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 18.5;
  CURRENT_PAGE = 0;
  OTHER_HEIGHT = SPACE_HEIGHT * 6;

  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(SPACE_WIDTH, SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("TESTING", SPACE_WIDTH + (BOX_WIDTH * 0.5), SPACE_HEIGHT + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("MANAGE", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * -1) + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("DATA", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("HARDWARE", SPACE_WIDTH + (BOX_WIDTH * 0.5), (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("CHECK", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SETTINGS", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, OTHER_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, OTHER_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("RESET", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2) + (OTHER_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);
  
  while (1)
  {
    waitForPress();

    if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > SPACE_HEIGHT && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT))
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > SPACE_HEIGHT && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT))
    {
      manageData();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)))
    {
      hardwareCheck();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)))
    {
      settings();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2) + OTHER_HEIGHT))
    {
      reset();
    }

    waitForRelease();
  }
}

void reset() // PAGE #: 1
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 1;

  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Are you sure you want to continue?", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3), 1, THEME_PRIMARY);
  drawCenterString("This will delete all test data and reset settings.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("CONFIRM", LCD_WIDTH * 0.5, SPACE_HEIGHT + (BOX_HEIGHT * 0.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("CANCEL", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > (SPACE_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT + BACK_HEIGHT))
    {
      menu();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      menu();
    }

    waitForRelease();
  }
}

void setFilename()
{
  strcpy(FILENAME, FILE_PLOT);
  strcat(FILENAME, FILE_STALK);
  strcat(FILENAME, FILE_NODE);
  strcat(FILENAME, ".csv");
  FILENAME[12] = '\0';
}

void waitForPress()
{
  do
  {
    TS_POINT = TS.getPoint();
    delay(10);
  }
  while (TS_POINT.z < TS_PRESSURE_MIN || TS_POINT.z > TS_PRESSURE_MAX);

  TSPoint tempPoint = TS_POINT;

  switch (LCD_ROTATION)
  {
    case 0:
      TS_POINT.x = map(TS_POINT.x, 120, 905, LCD_WIDTH, 0);
      TS_POINT.y = map(TS_POINT.y, 85, 895, LCD_HEIGHT, 0);
      break;
    case 1:
      TS_POINT.x = map(tempPoint.y, 85, 895, LCD_WIDTH, 0);
      TS_POINT.y = map(tempPoint.x, 905, 120, LCD_HEIGHT, 0);
      break;
    case 2:
      TS_POINT.x = map(TS_POINT.x, 905, 120, LCD_WIDTH, 0);
      TS_POINT.y = map(TS_POINT.y, 895, 85, LCD_HEIGHT, 0);
      break;
    case 3:
      TS_POINT.x = map(tempPoint.y, 895, 85, LCD_WIDTH, 0);
      TS_POINT.y = map(tempPoint.x, 120, 905, LCD_HEIGHT, 0);
      break;
  }
}

void waitForRelease()
{
  int releaseCount = 0;
  TSPoint tempPoint;

  do
  {
    tempPoint = TS.getPoint();

    if (tempPoint.z < TS_PRESSURE_MIN || tempPoint.z > TS_PRESSURE_MAX)
    {
      releaseCount++;
    }
    else
    {
      releaseCount = 0;
      TS_POINT.x = tempPoint.x;
      TS_POINT.y = tempPoint.y;
      TS_POINT.z = tempPoint.z;
    }

    delay(10);
  }
  while (releaseCount < 10);
}
