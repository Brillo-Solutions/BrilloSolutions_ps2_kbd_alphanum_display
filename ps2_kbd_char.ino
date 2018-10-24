/*Written By: Er. Dapinder Singh Virk
  Email ID: brillosolutions@gmail.com
  Version: 1.0.2
  Date: October 23, 2018
  Outputs: Displays key press in form of BIN, HEX and CHAR on serial terminal.*/

#define clkLine 3
#define dataLine 4
uint8_t kbdBits[33], i = 0;
boolean capsLock = false;
boolean numLock = true;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(clkLine, INPUT);
  pinMode(dataLine, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(clkLine), kbdInterrupt, FALLING);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (i == 33)
  {
    i = 0;
    uint8_t uprLimit = 8, lwrLimit = 1, kbdByte = 0;
    for (int j = 0; j <= 2; j++)
    {
      for (int k = uprLimit; k >= lwrLimit; k--)
      {
        if (kbdBits[k])
        {
          kbdByte <<= 1;
          kbdByte |= 0x01;
        }
        else
          kbdByte <<= 1;
      }
      Serial.print("BIN: ");
      for (int j = 0; j <= 32; j++)
        Serial.print(kbdBits[j]);
      Serial.print("\nHEX: ");
      Serial.print(kbdByte, HEX);
      Serial.print("\nCHAR: ");
      if (mapKey(kbdByte))
        break;
      uprLimit += 11;
      lwrLimit += 11;
    }
  }
}

boolean mapKey(uint8_t keyCode)
{
  boolean isFound = false;
  switch (keyCode)
  {
    /**Matrix numeric keypad codes: (0 - 9)**/
    case 0x70:
    {
      if (numLock)
        Serial.print("0");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x69:
    {
      if (numLock)
        Serial.print("1");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x72:
    {
      if (numLock)
        Serial.print("2");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x7A:
    {
      if (numLock)
        Serial.print("3");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x6B:
    {
      if (numLock)
        Serial.print("4");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x73:
    {
      if (numLock)
        Serial.print("5");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x74:
    {
      if (numLock)
        Serial.print("6");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x6C:
    {
      if (numLock)
        Serial.print("7");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x75:
    {
      if (numLock)
        Serial.print("8");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    case 0x7D:
    {
      if (numLock)
        Serial.print("9");
      else
        Serial.print("ENABLE NUM LOCK TO SEE NUMBER");
      isFound = true;
      break;
    }
    /**Matrix numeric keypad codes: (0 - 9)**/

    /**Horizontal numeric keypad codes: (0 - 9)**/
    case 0x45:
    {
      Serial.print("0");
      isFound = true;
      break;
    }
    case 0x16:
    {
      Serial.print("1");
      isFound = true;
      break;
    }
    case 0x1E:
    {
      Serial.print("2");
      isFound = true;
      break;
    }
    case 0x26:
    {
      Serial.print("3");
      isFound = true;
      break;
    }
    case 0x25:
    {
      Serial.print("4");
      isFound = true;
      break;
    }
    case 0x2E:
    {
      Serial.print("5");
      isFound = true;
      break;
    }
    case 0x36:
    {
      Serial.print("6");
      isFound = true;
      break;
    }
    case 0x3D:
    {
      Serial.print("7");
      isFound = true;
      break;
    }
    case 0x3E:
    {
      Serial.print("8");
      isFound = true;
      break;
    }
    case 0x46:
    {
      Serial.print("9");
      isFound = true;
      break;
    }
    /**Horizontal numeric keypad codes: (0 - 9)**/

    /**Enter key**/
    case 0x5A:
    {
      Serial.print("\n");
      isFound = true;
      break;
    }
    /**Enter key**/

    /**Dot keys**/
    case 0x49:
    {
      Serial.print(".");
      isFound = true;
      break;
    }
    case 0x71:
    {
      Serial.print(".");
      isFound = true;
      break;
    }
    /**Dot keys**/

    /**Arithmetic keys**/
    case 0x79:
    {
      Serial.print("+");
      isFound = true;
      break;
    }
    case 0x7B:
    {
      Serial.print("-");
      isFound = true;
      break;
    }
    case 0x7C:
    {
      Serial.print("*");
      isFound = true;
      break;
    }
    case 0x4A:
    {
      Serial.print("/");
      isFound = true;
      break;
    }
    case 0x55:
    {
      Serial.print("=");
      isFound = true;
      break;
    }
    /**Arithmetic keys**/

    /**Caps Lock key**/
    case 0x58:
    {
      if (capsLock)
      {
        Serial.print("CAPS LOCK DISABLED");
        capsLock =false;
      }
      else
      {
        Serial.print("CAPS LOCK ENABLED");
        capsLock = true;
      }
      isFound = true;
      break;
    }
    /**Caps Lock key**/

    /**Num Lock key**/
    case 0x77:
    {
      if (numLock)
      {
        Serial.print("NUM LOCK DISABLED");
        numLock =false;
      }
      else
      {
        Serial.print("NUM LOCK ENABLED");
        numLock = true;
      }
      isFound = true;
      break;
    }
    /**Num Lock key**/
    
    /**Alphabetic keys**/
    case 0x15:
    {
      if (capsLock)
        Serial.print("Q");
      else
        Serial.print("q");
      isFound = true;
      break;
    }
    case 0x1D:
    {
      if (capsLock)
        Serial.print("W");
      else
        Serial.print("w");
      isFound = true;
      break;
    }
    case 0x24:
    {
      if (capsLock)
        Serial.print("E");
      else
        Serial.print("e");
      isFound = true;
      break;
    }
    case 0x2D:
    {
      if (capsLock)
        Serial.print("R");
      else
        Serial.print("r");
      isFound = true;
      break;
    }
    case 0x2C:
    {
      if (capsLock)
        Serial.print("T");
      else
        Serial.print("t");
      isFound = true;
      break;
    }
    case 0x35:
    {
      if (capsLock)
        Serial.print("Y");
      else
        Serial.print("y");
      isFound = true;
      break;
    }
    case 0x3C:
    {
      if (capsLock)
        Serial.print("U");
      else
        Serial.print("u");
      isFound = true;
      break;
    }
    case 0x43:
    {
      if (capsLock)
        Serial.print("I");
      else
        Serial.print("i");
      isFound = true;
      break;
    }
    case 0x44:
    {
      if (capsLock)
        Serial.print("O");
      else
        Serial.print("o");
      isFound = true;
      break;
    }
    case 0x4D:
    {
      if (capsLock)
        Serial.print("P");
      else
        Serial.print("p");
      isFound = true;
      break;
    }
    case 0x1C:
    {
      if (capsLock)
        Serial.print("A");
      else
        Serial.print("a");
      isFound = true;
      break;
    }
    case 0x1B:
    {
      if (capsLock)
        Serial.print("S");
      else
        Serial.print("s");
      isFound = true;
      break;
    }
    case 0x23:
    {
      if (capsLock)
        Serial.print("D");
      else
        Serial.print("d");
      isFound = true;
      break;
    }
    case 0x2B:
    {
      if (capsLock)
        Serial.print("F");
      else
        Serial.print("f");
      isFound = true;
      break;
    }
    case 0x34:
    {
      if (capsLock)
        Serial.print("G");
      else
        Serial.print("g");
      isFound = true;
      break;
    }
    case 0x33:
    {
      if (capsLock)
        Serial.print("H");
      else
        Serial.print("h");
      isFound = true;
      break;
    }
    case 0x3B:
    {
      if (capsLock)
        Serial.print("J");
      else
        Serial.print("j");
      isFound = true;
      break;
    }
    case 0x42:
    {
      if (capsLock)
        Serial.print("K");
      else
        Serial.print("k");
      isFound = true;
      break;
    }
    case 0x4B:
    {
      if (capsLock)
        Serial.print("L");
      else
        Serial.print("l");
      isFound = true;
      break;
    }
    case 0x1A:
    {
      if (capsLock)
        Serial.print("Z");
      else
        Serial.print("z");
      isFound = true;
      break;
    }
    case 0x22:
    {
      if (capsLock)
        Serial.print("X");
      else
        Serial.print("x");
      isFound = true;
      break;
    }
    case 0x21:
    {
      if (capsLock)
        Serial.print("C");
      else
        Serial.print("c");
      isFound = true;
      break;
    }
    case 0x2A:
    {
      if (capsLock)
        Serial.print("V");
      else
        Serial.print("v");
      isFound = true;
      break;
    }
    case 0x32:
    {
      if (capsLock)
        Serial.print("B");
      else
        Serial.print("b");
      isFound = true;
      break;
    }
    case 0x31:
    {
      if (capsLock)
        Serial.print("N");
      else
        Serial.print("n");
      isFound = true;
      break;
    }
    case 0x3A:
    {
      if (capsLock)
        Serial.print("M");
      else
        Serial.print("m");
      isFound = true;
      break;
    }
    /**Alphabetic keys**/
  }
  Serial.print("\r\n\n");
  return isFound;
}

void kbdInterrupt()
{
  kbdBits[i++] = digitalRead(dataLine);
}
