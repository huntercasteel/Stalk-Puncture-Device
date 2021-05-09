void testing() // PAGE #: 10
{
  char filename[23];

  strcpy(filename, "Filename: ");
  strcat(filename, FILENAME);
  filename[22] = '\0';
  BOX_HEIGHT = SPACE_HEIGHT * 9;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 10;
  OTHER_HEIGHT = SPACE_HEIGHT * 14;
  OTHER_WIDTH = SPACE_WIDTH + (BOX_WIDTH * 2);
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT, OTHER_WIDTH, OTHER_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawString(filename, (SPACE_WIDTH * 3) + BOX_WIDTH, SPACE_HEIGHT + (OTHER_HEIGHT * 0.25), 1, THEME_PRIMARY);
  drawString("Force: ", (SPACE_WIDTH * 3) + BOX_WIDTH, SPACE_HEIGHT + (OTHER_HEIGHT * 0.5), 1, THEME_PRIMARY);
  drawString("Start Pos: ", (SPACE_WIDTH * 3) + BOX_WIDTH, SPACE_HEIGHT + (OTHER_HEIGHT * 0.75), 1, THEME_PRIMARY);

  drawCenterString("To begin test, press and hold both bottom buttons.", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3.5) + OTHER_HEIGHT, 1, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("PLOT", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("STALK", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("NODE", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("TARE", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("START", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("ZERO", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      menu();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      plot();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      stalk();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      node();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      tare();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      start();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      zero();
    }

    waitForRelease();
  }
}

void node() // PAGE #: 11
{
  char node[5];
  int value;

  strcpy(node, FILE_NODE);
  node[4] = '\0';
  BOX_HEIGHT = SPACE_HEIGHT * 7;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 11;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("SET NODE #", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 4) + (BOX_WIDTH * 2.5), (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DEL", SPACE_WIDTH + (BOX_WIDTH * 0.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("0", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("+", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("1", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("2", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("3", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("4", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("5", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("6", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("7", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("8", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("9", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 4) + (BOX_WIDTH * 2)) && TS_POINT.y > 0 && TS_POINT.x < ((SPACE_WIDTH * 4) + (BOX_WIDTH * 3)) && TS_POINT.y < BOX_HEIGHT)
    {
      strcpy(FILE_NODE, node);
      setFilename();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(node, "0000"))
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[3] = node[2];
        node[2] = node[1];
        node[1] = node[0];
        node[0] = '0';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(node, "0000") && node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '0';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
      value = node[3];

      if (value < 57 && value > 47)
      {
        value++;
        node[3] = value;
      }
      else
      {
        value = node[2];

        if (value < 57 && value > 47)
        {
          value++;
          node[2] = value;
        }
        else
        {
          value = node[1];

          if (value < 57 && value > 47)
          {
            value++;
            node[1] = value;
          }
          else
          {
            value = node[0];

            if (value < 57 && value > 47)
            {
              value++;
              node[0] = value;
            }
            else
            {
              node[0] = 48;
            }

            node[1] = 48;
          }

          node[2] = 48;
        }

        node[3] = 48;
      }

      drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '1';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '2';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '3';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '4';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '5';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '6';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '7';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '8';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (node[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[3];
        node[3] = '9';
        drawCenterString(node, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }

    waitForRelease();
  }
}

void plot() // PAGE #: 12
{
  char plot[3];
  int value;

  strcpy(plot, FILE_PLOT);
  plot[2] = '\0';
  BOX_HEIGHT = SPACE_HEIGHT * 7;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 12;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("SET PLOT #", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 4) + (BOX_WIDTH * 2.5), (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DEL", SPACE_WIDTH + (BOX_WIDTH * 0.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("0", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("+", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("1", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("2", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("3", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("4", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("5", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("6", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("7", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("8", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("9", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 4) + (BOX_WIDTH * 2)) && TS_POINT.y > 0 && TS_POINT.x < ((SPACE_WIDTH * 4) + (BOX_WIDTH * 3)) && TS_POINT.y < BOX_HEIGHT)
    {
      strcpy(FILE_PLOT, plot);
      setFilename();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(plot, "00"))
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[1] = plot[0];
        plot[0] = '0';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(plot, "00") && plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '0';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
      value = plot[1];

      if (value < 57 && value > 47)
      {
        value++;
        plot[1] = value;
      }
      else
      {
        value = plot[0];

        if (value < 57 && value > 47)
        {
          value++;
          plot[0] = value;
        }
        else
        {
          plot[0] = 48;
        }

        plot[1] = 48;
      }

      drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '1';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '2';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '3';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '4';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '5';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '6';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '7';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '8';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (plot[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        plot[0] = plot[1];
        plot[1] = '9';
        drawCenterString(plot, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }

    waitForRelease();
  }
}

void stalk() // PAGE #: 13
{
  char stalk[3];
  int value;

  strcpy(stalk, FILE_STALK);
  stalk[2] = '\0';
  BOX_HEIGHT = SPACE_HEIGHT * 7;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 13;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("SET STALK #", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 4) + (BOX_WIDTH * 2.5), (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DEL", SPACE_WIDTH + (BOX_WIDTH * 0.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("0", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), SPACE_HEIGHT + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("+", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("1", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("2", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("3", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("4", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("5", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("6", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("7", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("8", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("9", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 4) + (BOX_WIDTH * 2)) && TS_POINT.y > 0 && TS_POINT.x < ((SPACE_WIDTH * 4) + (BOX_WIDTH * 3)) && TS_POINT.y < BOX_HEIGHT)
    {
      strcpy(FILE_STALK, stalk);
      setFilename();
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(stalk, "00"))
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[1] = stalk[0];
        stalk[0] = '0';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      if (strcmp(stalk, "00") && stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '0';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > (SPACE_HEIGHT + BOX_HEIGHT) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < (SPACE_HEIGHT + (BOX_HEIGHT * 2)))
    {
      LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
      value = stalk[1];

      if (value < 57 && value > 47)
      {
        value++;
        stalk[1] = value;
      }
      else
      {
        value = stalk[0];

        if (value < 57 && value > 47)
        {
          value++;
          stalk[0] = value;
        }
        else
        {
          stalk[0] = 48;
        }

        stalk[1] = 48;
      }

      drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '1';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '2';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '3';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '4';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '5';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '6';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '7';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 2) + BOX_WIDTH) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 2) + (BOX_WIDTH * 2)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '8';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 4)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 4) + (BOX_HEIGHT * 5)))
    {
      if (stalk[0] == '0')
      {
        LCD.fillRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * -1.5) + (BOX_HEIGHT * 0.5), BOX_WIDTH, (SPACE_HEIGHT * 1.5) + (BOX_HEIGHT * 0.5), THEME_BACKGROUND);
        stalk[0] = stalk[1];
        stalk[1] = '9';
        drawCenterString(stalk, (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);
      }
    }

    waitForRelease();
  }
}

void tare()
{
  Serial.println("Tare");
}

void start() // PAGE #: 14
{
  BOX_HEIGHT = SPACE_HEIGHT * 9;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 14;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("SET START POS", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString("0", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 4) + (BOX_WIDTH * 2.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("Move to desired location with bottom buttons.", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (BOX_HEIGHT * 1.5), 1, THEME_PRIMARY);
  drawCenterString("Use arrows for fine adjustments.", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("<--", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("-->", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("<-----", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("----->", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 4) + (BOX_WIDTH * 2)) && TS_POINT.y > 0 && TS_POINT.x < ((SPACE_WIDTH * 4) + (BOX_WIDTH * 3)) && TS_POINT.y < BACK_HEIGHT)
    {
      Serial.println("SAVE");
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      Serial.print("<--");
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      Serial.print("-->");
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      Serial.print("<-----");
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      Serial.print("------->");
    }

    waitForRelease();
  }
}

void testCompleted() // PAGE #: 15
{
  BOX_HEIGHT = SPACE_HEIGHT * 12;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 15;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString(FILENAME, LCD_WIDTH * 0.5, SPACE_HEIGHT * 2, TEXT_SIZE, THEME_PRIMARY);
  drawString("Max Force:", SPACE_WIDTH * 3, SPACE_HEIGHT * 4, 1, THEME_PRIMARY);

  LCD.writeLine(SPACE_WIDTH * 2, SPACE_HEIGHT * 2, SPACE_WIDTH * 2, SPACE_HEIGHT + (BOX_HEIGHT * 2), THEME_PRIMARY);
  LCD.writeLine(SPACE_WIDTH * 2, SPACE_HEIGHT  + (BOX_HEIGHT * 2), (SPACE_WIDTH * 2) + (BOX_WIDTH * 3), SPACE_HEIGHT + (BOX_HEIGHT * 2), THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", SPACE_WIDTH + (BOX_WIDTH * 0.5), SPACE_HEIGHT + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("INCREMENT STALK", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 2.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 2) + BOX_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("INCREMENT NODE", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 2.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("DELETE", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), SPACE_HEIGHT + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("TEST", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();
    testing();
    waitForRelease();
  }
}

void testInterrupted() // PAGE #: 16
{
  BOX_HEIGHT = SPACE_HEIGHT * 14;
  BOX_WIDTH = SPACE_WIDTH * 28;
  CURRENT_PAGE = 16;
  
  LCD.fillScreen(THEME_BACKGROUND);

  drawCenterString("Test Interrupted", LCD_WIDTH * 0.5, SPACE_HEIGHT + (BOX_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);
  drawCenterString("To resume test, press and hold both bottom buttons.", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 5) + (BOX_HEIGHT * 0.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 8) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 6), (SPACE_HEIGHT * 8) + BOX_HEIGHT, BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("CANCEL TEST", LCD_WIDTH * 0.5, (SPACE_HEIGHT * 8) + (BOX_HEIGHT * 1.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();
    testing();
    waitForRelease();
  }
}

void zero() // PAGE #: 17
{
  BOX_HEIGHT = SPACE_HEIGHT * 9;
  BOX_WIDTH = SPACE_WIDTH * 12;
  CURRENT_PAGE = 17;
  
  LCD.fillScreen(THEME_BACKGROUND);

  LCD.fillRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(0, 0, BACK_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("BACK", (BACK_WIDTH * 0.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("SET ZERO POS", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), SPACE_HEIGHT, 1, THEME_PRIMARY);
  drawCenterString("0", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT + (BOX_HEIGHT * 0.5)), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 4) + (BOX_WIDTH * 2), 0, BOX_WIDTH, BACK_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("SAVE", (SPACE_WIDTH * 4) + (BOX_WIDTH * 2.5), (BACK_HEIGHT * 0.5), TEXT_SIZE, THEME_PRIMARY);

  drawCenterString("Move to desired location with bottom buttons.", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (BOX_HEIGHT * 1.5), 1, THEME_PRIMARY);
  drawCenterString("Use arrows for fine adjustments.", (SPACE_WIDTH * 2) + (BOX_WIDTH * 1.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 1.5), 1, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("<--", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("-->", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect(SPACE_WIDTH, (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("<-----", SPACE_WIDTH + (BOX_WIDTH * 0.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  LCD.fillRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_SECONDARY);
  LCD.drawRoundRect((SPACE_WIDTH * 3) + (BOX_WIDTH * 2), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3), BOX_WIDTH, BOX_HEIGHT, BOX_RADIUS, THEME_PRIMARY);
  drawCenterString("----->", (SPACE_WIDTH * 3) + (BOX_WIDTH * 2.5), (SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3.5), TEXT_SIZE, THEME_PRIMARY);

  while (1)
  {
    waitForPress();

    if (TS_POINT.x > 0 && TS_POINT.y > 0 && TS_POINT.x < BACK_WIDTH && TS_POINT.y < BACK_HEIGHT)
    {
      testing();
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 4) + (BOX_WIDTH * 2)) && TS_POINT.y > 0 && TS_POINT.x < ((SPACE_WIDTH * 4) + (BOX_WIDTH * 3)) && TS_POINT.y < BACK_HEIGHT)
    {
      Serial.println("SAVE");
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      Serial.print("<--");
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 2)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 2) + (BOX_HEIGHT * 3)))
    {
      Serial.print("-->");
    }
    else if (TS_POINT.x > SPACE_WIDTH && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < (SPACE_WIDTH + BOX_WIDTH) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      Serial.print("<-----");
    }
    else if (TS_POINT.x > ((SPACE_WIDTH * 3) + (BOX_WIDTH * 2)) && TS_POINT.y > ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 3)) && TS_POINT.x < ((SPACE_WIDTH * 3) + (BOX_WIDTH * 3)) && TS_POINT.y < ((SPACE_HEIGHT * 3) + (BOX_HEIGHT * 4)))
    {
      Serial.print("------->");
    }

    waitForRelease();
  }
}
