
int R = 9;
int G = 10;
int B = 11;

int R_button = 2;
int G_button = 3;
int B_button = 4;

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

}

void loop() {

  if (digitalRead(R_button) == HIGH)
  {R_brightness = 150;}
  else
  {R_brightness = 0;}

  if (digitalRead(G_button) == HIGH)
  {G_brightness = 150;}
  else
  {G_brightness = 0;}

  if (digitalRead(B_button) == HIGH)
  {B_brightness = 150;}
  else
  {B_brightness = 0;}

  analogWrite(R, R_brightness);
  analogWrite(G, G_brightness);
  analogWrite(B, B_brightness);
  delay(10);

  //digitalWrite(R, LOW);
  //digitalWrite(G, LOW);
  //digitalWrite(B, LOW);
  //delay(1000);

}
