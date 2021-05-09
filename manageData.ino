void manageData() // PAGE #: 20
{
  BOX_HEIGHT = SPACE_HEIGHT * 12;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 20;
  OTHER_HEIGHT = LCD_HEIGHT - (SPACE_HEIGHT * 2);
  OTHER_WIDTH = SPACE_WIDTH * 12;

  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT, OTHER_WIDTH, OTHER_HEIGHT, BOX_RADIUS, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DELETE", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * -1) + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("ALL", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("UP", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DISPLAY", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("TEST", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DOWN", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DELETE", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("TEST", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      menu();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > SPACE_HEIGHT && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT))
    {
      deleteAll();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)))
    {
      up();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)))
    {
      displayTest();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)))
    {
      down();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)))
    {
      deleteTest();
    }
    
    waitForRelease();
  }
}

void deleteAll() // PAGE #: 21
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 21;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Are you sure you want to continue?", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3), 1, THEME_PRIMARY);
  drawCenterString("This will delete all test data.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5), 1, THEME_PRIMARY);

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
      manageData();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      manageData();
    }

    waitForRelease();
  }
}

void deleteTest() // PAGE #: 22
{
  char message[46];
  int previousPage = CURRENT_PAGE;

  strcpy(message, "This will delete test data file ");
  strcat(message, FILENAME);
  strcat(message, ".");
  message[45] = '\0';
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 22;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Are you sure you want to continue?", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3), 1, THEME_PRIMARY);
  drawCenterString(message, LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5), 1, THEME_PRIMARY);

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
      manageData();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      switch(previousPage)
      {
        case 23:
          displayTest();
          break;
        default:
          manageData();
          break;
      }
    }

    waitForRelease();
  }
}

void displayTest() // PAGE #: 23
{
  BOX_HEIGHT = SPACE_HEIGHT * 12;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 23;

  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString(FILENAME, LCD_WIDTH * 0.5, SPACE_HEIGHT * 2, TEXT_SIZE, THEME_PRIMARY);
  drawString("Max Force:", SPACE_WIDTH * 3, SPACE_HEIGHT * 4, 1, THEME_PRIMARY);

  LCD.writeLine(SPACE_WIDTH * 2, SPACE_HEIGHT * 2, SPACE_WIDTH * 2, SPACE_HEIGHT + (BOX_HEIGHT * 2), THEME_PRIMARY);
  LCD.writeLine(SPACE_WIDTH * 2, SPACE_HEIGHT  + (BOX_HEIGHT * 2), (SPACE_WIDTH * 2) + (BOX_WIDTH * 3), SPACE_HEIGHT + (BOX_HEIGHT * 2), THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DELETE", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("TEST", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();
    
    if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)))
    {
      manageData();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)))
    {
      deleteTest();
    }
    
    waitForRelease();
  }
}

void down()
{
  Serial.println("Down");
}

void up()
{
  Serial.println("Up");
}
