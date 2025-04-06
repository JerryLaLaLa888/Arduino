#define PUL 5
#define DIR 6
#define ENA 7

float acceleration = 0;        // deg/s^2
float speed = 0;               // deg/s
float current_speed = 0;       // deg/s
int move = 0;                  // deg
int count = 0;

int pulses_per_rev = 3200;     // pulses/rev setting
float freq = 0;                // PWM freqency, Hz
float period = 0;              // PWM period, ms

float hightime_percent = 0;    // %
float hightime = 0;            // ms
float lowtime = 0;             // ms

void setup() {

  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(ENA, OUTPUT);

  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);

  Serial.begin(115200);

  acceleration = 0.3;          // deg/s^2
  speed = 250;                 // deg/s
  move = 720;                  // deg

  hightime_percent = 70;       // %

}

void loop() {

    digitalWrite( PUL, LOW );
    delay( 5000 );

  for ( int x = 0; x < pulses_per_rev / 360.0 * move; x++ ) {
    
    if ( current_speed < speed - acceleration * 360.0 / pulses_per_rev && count < pulses_per_rev / 360.0 * move - x ) {
      current_speed += acceleration * 360.0 / pulses_per_rev;
      count++;
    }
    else if (count < pulses_per_rev / 360.0 * move - x) {
      current_speed = speed;
    }

    if ( count >= pulses_per_rev / 360.0 * move - x ) {
      current_speed -= acceleration * 360.0 / pulses_per_rev;
      //Serial.println(current_speed);
    }


    freq = current_speed * ( pulses_per_rev / 360.0 );
    period = 1.0 / freq * 1000;
    hightime = period * hightime_percent / 100.0;
    lowtime = period - hightime;

    //Serial.println(current_speed);

    digitalWrite( PUL, LOW );
    delay( lowtime );
    digitalWrite( PUL, HIGH );
    delay( hightime );

  }
 
  
  while( speed == 250 ) {
    delay(100);
  }

}

