
int ledPin = 3;
int baudRate = 9600;
float brightness;
int input;
int dt = 2000;
void setup() {
  Serial.begin(baudRate);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println("What is your desired brightness on a scale of 0 - 10?: ");
  while(Serial.available() == 0){}
  input = Serial.parseInt();
  brightness = pow(2, 0.8*input) -1;
  Serial.print("You PWM Value is: ");
  Serial.println(brightness);
  analogWrite(ledPin, brightness);
  delay(dt);
}