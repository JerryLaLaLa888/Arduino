
int R = 9;
int G = 10;
int B = 11;

int R_button = 2;
int G_button = 3;
int B_button = 4;

int R_b_condition = 0;
int G_b_condition = 0;
int B_b_condition = 0;

int R_brightness = 0;
int G_brightness = 0;
int B_brightness = 0;

void setup() {

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(R_button, INPUT);
  pinMode(G_button, INPUT);
  pinMode(B_button, INPUT);

  Serial.begin(9600);

}

void loop() {

  if (digitalRead(R_button) == HIGH)
  {
    R_b_condition = 1;
    do {
       if (digitalRead(R_button) == LOW)
       {
        if (R_brightness <= 255 && (255 - R_brightness) >= 50)
        {
          R_brightness += 50;
          R_b_condition = 0;
        }
        else
        {
          R_brightness = 0;
          R_b_condition = 0;
        }
       }
    } while (R_b_condition == 1);
  }

   if (digitalRead(G_button) == HIGH)
  {
    G_b_condition = 1;
    do {
       if (digitalRead(G_button) == LOW)
       {
        if (G_brightness <= 255 && (255 - G_brightness) >= 50)
        {
          G_brightness += 50;
        }
        else
        {
          G_brightness = 0;
        }
        G_b_condition = 0;

        Serial.println(G_brightness);
        delay(100);
       }
    } while (G_b_condition == 1);
  }

 if (digitalRead(B_button) == HIGH)
  {
    B_b_condition = 1;
    do {
       if (digitalRead(B_button) == LOW)
       {
        if (B_brightness <= 255 && (255 - B_brightness) >= 50)
        {
          B_brightness += 50;
          B_b_condition = 0;
        }
        else
        {
          B_brightness = 0;
          B_b_condition = 0;
        }
       }
    } while (B_b_condition == 1);
  }
 
  analogWrite(R, R_brightness);
  analogWrite(G, G_brightness);
  analogWrite(B, B_brightness);
  delay(10);

}
