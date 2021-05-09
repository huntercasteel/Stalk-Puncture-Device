void hardwareCheck() // PAGE #: 30
{
  OTHER_HEIGHT = SPACE_HEIGHT * 24;
  OTHER_WIDTH = LCD_WIDTH - (SPACE_WIDTH * 2);
  CURRENT_PAGE = 30;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("Move shuttle by pressing both bottom buttons.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 3) + BACK_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString("Shuttle will return to start position when leaving.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5) + BACK_HEIGHT, 1, THEME_PRIMARY);

  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 8) + BACK_HEIGHT, OTHER_WIDTH, OTHER_HEIGHT, BOX_RADIUS, THEME_PRIMARY);

  drawString("Position:", SPACE_WIDTH * 2, (SPACE_HEIGHT * 8) + BACK_HEIGHT + (OTHER_HEIGHT * 0.33), TEXT_SIZE, THEME_PRIMARY);
  drawString("Force:", SPACE_WIDTH * 2, (SPACE_HEIGHT * 8) + BACK_HEIGHT + (OTHER_HEIGHT * 0.66), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      menu();
    }

    waitForRelease();
  }
}
