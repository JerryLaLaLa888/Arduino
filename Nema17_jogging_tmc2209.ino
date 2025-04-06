#include <AccelStepper.h>
#include <MultiStepper.h>

#define stepPin 5
#define dirPin 6
#define MS1Pin 12
#define MS2Pin 13
#define JogfowardPin 2
#define SpeedsettingPin 3

int speed = 200;
bool button_state = false;

AccelStepper stepper1(1, stepPin, dirPin);

void setup() {

   pinMode(stepPin, OUTPUT);
   pinMode(dirPin, OUTPUT);
   pinMode(MS1Pin, OUTPUT);
   pinMode(MS2Pin, OUTPUT);
   pinMode(JogfowardPin, INPUT);
   pinMode(SpeedsettingPin, INPUT);

   stepper1.setMaxSpeed(4000);
   stepper1.setCurrentPosition(0);
   stepper1.setAcceleration(500);
   stepper1.setSpeed(500);

   Serial.begin(9600);

}

void loop() {

//microstep setting (1/8: L L 1/16: H H 1/32: H L 1/64: L H )
   digitalWrite(MS1Pin, LOW);
   digitalWrite(MS2Pin, LOW);
  

   if (digitalRead(SpeedsettingPin) == HIGH) {
     
       button_state = true;
     
       do {
         if (digitalRead(SpeedsettingPin) == LOW) {
           if (speed <= 800) {
             speed += 200;
           }
           else {
             speed = 200;
           }
           button_state = false;
           Serial.println(speed);
        }

         if (digitalRead(JogfowardPin) == HIGH) {
           stepper1.setSpeed(speed);
           stepper1.runSpeed();
          }
      } while (button_state == true);
    }

   if (digitalRead(JogfowardPin) == HIGH) {
     stepper1.setSpeed(speed);
   }
   else {
     stepper1.setSpeed(0);
   }

   stepper1.runSpeed();

}
