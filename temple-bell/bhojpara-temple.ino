/*
* Ultrasonic Sensor with Arduino and relay
*
* by Harikrushna Adiecha,
* https://harikrushna.info
*
*/

// defines pins numbers
const int TRIG_PIN = 8;
const int ECHO_PIN = 9;
const int RELAY_PIN = 7;

// defines variables
long duration;
int distance;
int min_dist = 1; // Minimum distance 1cm to keep motor on
int max_dist = 20; // Maximum distance 20cm to keep motor on
int off_delay = 100; // 100 miliseconds
int on_delay = 1000; // 1000 milisecnds (1 second)

void setup() {
  pinMode(RELAY_PIN, OUTPUT); // Sets the Motor as an Output
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance = ");
  Serial.println(distance);

  if(distance >= min_dist &&  distance <= max_dist)
  {
    Serial.println("Motor is on");
    digitalWrite(RELAY_PIN, LOW);
    delay(on_delay);
  }
  else {
    Serial.println("Motor is off");
    digitalWrite(RELAY_PIN, HIGH);
    delay(off_delay);
  }
}
