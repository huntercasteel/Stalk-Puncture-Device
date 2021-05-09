void settings() // PAGE #: 40
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 40;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("Calibration Equation:", (SPACE_WIDTH * 14) + BACK_WIDTH, (SPACE_HEIGHT * -1) + (BACK_HEIGHT * 0.5), 1, THEME_PRIMARY);
  drawCenterString("Y = 0.234X + 23.2", (SPACE_WIDTH * 14) + BACK_WIDTH, (SPACE_HEIGHT * 1) + (BACK_HEIGHT * 0.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("RECALIBRATE", LCD_WIDTH * 0.5, (SPACE_HEIGHT * -1) + (BOX_HEIGHT * 0.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("LOAD CELL", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 0.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SWITCH THEME", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      menu();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > (SPACE_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT + BACK_HEIGHT))
    {
      recalibrateLoadCellZero();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      switchTheme();
      settings();
    }

    waitForRelease();
  }
}

void recalibrateLoadCellValue() // PAGE #: 41
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 41;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Apply known force to load cell,", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3), 1, THEME_PRIMARY);
  drawCenterString("then press RECORD VALUE.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("RECORD VALUE", LCD_WIDTH * 0.5, SPACE_HEIGHT + (BOX_HEIGHT * 0.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("CANCEL", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();
    
    if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > (SPACE_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT + BACK_HEIGHT))
    {
      settings();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      settings();
    }

    waitForRelease();
  }
}

void recalibrateLoadCellZero() // PAGE #: 42
{
  BOX_HEIGHT = SPACE_HEIGHT * 15;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 42;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Lay device in testing orientation and ensure no loads", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3), 1, THEME_PRIMARY);
  drawCenterString("are present on load cell, then press RECORD ZERO.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), SPACE_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("RECORD ZERO", LCD_WIDTH * 0.5, SPACE_HEIGHT + (BOX_HEIGHT * 0.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("CANCEL", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5) + BACK_HEIGHT, TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > (SPACE_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + BOX_HEIGHT + BACK_HEIGHT))
    {
      recalibrateLoadCellValue();
    }
    else if (TS_POINT.x > (SPACE_WIDTH * 6) && TS_POINT.y > ((SPACE_HEIGHT * 2) + BOX_HEIGHT + BACK_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 6) + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2) + BACK_HEIGHT))
    {
      settings();
    }

    waitForRelease();
  }
}

void switchTheme()
{
  if (THEME_PRIMARY == WHITE)
  {
    THEME_PRIMARY = BLACK;
    THEME_SECONDARY = CYAN;
    THEME_BACKGROUND = WHITE;
  }
  else
  {
    THEME_PRIMARY = WHITE;
    THEME_SECONDARY = BLUE;
    THEME_BACKGROUND = BLACK;
  }
}
