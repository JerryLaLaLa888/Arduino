// I2C bus
#include <Wire.h>
// Graphics & OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// keypad
#include <Keypad.h>

// row and column sizes
const byte Rows = 4;
const byte Cols = 4;
// keypad array
char Keys[Rows][Cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'.', '0', '#', 'D'}
};

// Arduino pins
byte rowPins[Rows] = {6, 7, 8, 9};
byte colPins[Cols] = {10, 11, 12, 13};

// keypad object
Keypad numberKeypad = Keypad(makeKeymap(Keys), rowPins, colPins, Rows, Cols);

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// coordinate values 
float x = 666.66;
float y = 666.66;
float z = 666.66;


// value position of selected axis 
byte display_position = 0;

void setup() {
  
  // Start Wire library
  Wire.begin();

  // Initialize OLED with I2C address 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() { 

  display.display();

  // select input x, y, or z coordinate (x: A, y: B, z: C)
  char keypress = numberKeypad.getKey();
  switch (keypress) {

    case 'A':
        display_position = 1;
        x = InputValue(x, y, z, display_position);
      break;
    
    case 'B':
        display_position = 2;
        y = InputValue(x, y, z, display_position);
      break;

    case 'C':
        display_position = 3;
        z = InputValue(x, y, z, display_position);
      break;

    // set reset key as '#'
    case '#':
      x = 0;
      y = 0;
      z = 0;

    default:
      break;
  }

  display.clearDisplay();
  displayCoord(x, y, z);
  delay(25);
}



void displayCoord(float x, float y, float z) {

  // clear the display
  display.clearDisplay();
  // set color
  display.setTextColor(WHITE);
  // set font size
  display.setTextSize(1);
  // set cursor (font) position
  display.setCursor(0,0);
  display.print("Coordinate:");

  display.setCursor(0,10);
  display.print("x: ");
  display.setCursor(20,10);
  display.print(x);

  display.setCursor(70,10);
  display.print("y: ");
  display.setCursor(90,10);
  display.print(y);

  display.setCursor(0,20);
  display.print("z: ");
  display.setCursor(20,20);
  display.print(z);
}

void displayInput(float x, float y , float z, char* input, byte display_position) {

  // clear the display
  display.clearDisplay();
  // set color
  display.setTextColor(WHITE);
  // set font size
  display.setTextSize(1);
  // set cursor (font) position
  display.setCursor(0,0);
  display.print("Coordinate:");

  switch (display_position) {
    case 1:
      display.setCursor(0,10);
      display.print("x: ");
      display.setCursor(20,10);
      display.print(input);

      display.setCursor(70,10);
      display.print("y: ");
      display.setCursor(90,10);
      display.print(y);

      display.setCursor(0,20);
      display.print("z: ");
      display.setCursor(20,20);
      display.print(z);
  
      break;

    case 2:
      display.setCursor(0,10);
      display.print("x: ");
      display.setCursor(20,10);
      display.print(x);

      display.setCursor(70,10);
      display.print("y: ");
      display.setCursor(90,10);
      display.print(input);

      display.setCursor(0,20);
      display.print("z: ");
      display.setCursor(20,20);
      display.print(z);

      break;

    case 3:
      display.setCursor(0,10);
      display.print("x: ");
      display.setCursor(20,10);
      display.print(x);

      display.setCursor(70,10);
      display.print("y: ");
      display.setCursor(90,10);
      display.print(y);

      display.setCursor(0,20);
      display.print("z: ");
      display.setCursor(20,20);
      display.print(input);
  }

  // display.setCursor(0,10);
  // display.print("x: ");
  // display.setCursor(20,10);
  // display.print(x);

  // display.setCursor(70,10);
  // display.print("y: ");
  // display.setCursor(90,10);
  // display.print(y);

  // display.setCursor(0,20);
  // display.print("z: ");
  // display.setCursor(20,20);
  // display.print(z);

  // display.setCursor(20,10);
  // display.print(input);

}

float InputValue (float x, float y , float z, byte display_position) {
  
  // desired input value
  float result = 0.0;
  // storage of input number
  int numbers[5];
  // positive or negative value
  bool Negative = false;
  // total number of input digits
  int input_count = 0;
  // number of digits after decimel point
  int decimal = 0;
  // only 1 decimal point is allowed
  bool decimal_state = false;
  // state is true while entering
  bool Input_state = true;
  // display current input state
  char input[7] = {'\0','\0','\0','\0','\0','\0','\0'};
  int input_address = 0;


  // assign value to the corresponding digit
  while (Input_state == true) {
    // initialize input
    char keypress = '\0';
    // enter current desired number
    keypress = numberKeypad.getKey();

    switch (keypress) {
      case '1':
        numbers[input_count] = 1;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '2':
        numbers[input_count] = 2;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '3':
        numbers[input_count] = 3;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '4':
        numbers[input_count] = 4;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '5':
        numbers[input_count] = 5;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '6':
        numbers[input_count] = 6;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '7':
        numbers[input_count] = 7;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '8':
        numbers[input_count] = 8;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '9':
        numbers[input_count] = 9;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '0':
        numbers[input_count] = 0;
        input_count++;

        input[input_address] = keypress;
        input_address++;

        if (decimal_state == true)
          decimal++;
        break;

      case '.':
        // only 1 decimal point is allowed
        decimal_state = true;

        input[input_address] = keypress;
        input_address++;
        break;
      
      case 'B':
        // negative sign
        if (input_count == 0) {
          Negative = true;
        }
        input[input_address] = '-';
        input_address++;
        break;

      default:
        break;

    }

  // set enter key as 'D', set maximum number of total input digits to be 5
    if (keypress == 'D' || input_count == 5) {

      // calculate the resulting number
      for (int i = 0; i < input_count; i++) {
        for (int j = 0; j < input_count - i - 1; j++) {
          numbers[i] *= 10; 
        }
        result += numbers[i];
      }

      for (int i = 0; i < decimal; i++) {
        result /= 10;
      }
      
      if (Negative == true) {
        result *= -1.0;
      }

      // set input range
      if (result > 250.0) {
        result = 250.0;
      }
      else if (result < -250.0) {
        result = -250.0;
      }

      Input_state = false;
    }

    // set cancel as 'C', return original coordinate value
    if (keypress == 'C') {
      switch (display_position) {
        case 1:
          result = x;
          Input_state = false;
          break;
    
        case 2:
          result = y;
          Input_state = false;
          break;

        case 3:
          result = z;
          Input_state = false;
          break;
      }
    }


    // display current input
    display.display();
    display.clearDisplay();
    displayInput(x, y, z, input, display_position);
    delay(25);
  }

  return result;
}
