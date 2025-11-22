//Example 1 Variables. Just Uncomment to see it simulate
// int potPin = A0;
// int potVal;
// int baudRate = 9600;
// int wait = 1000;
// float volt;

// Ecample 2 Variables
int potPin = A2;
int ledPin = 3;
int potVal;
int baudRate = 9600;
int wait = 100;
float brightness;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  Serial.begin(baudRate);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Example 1 Codes
  // potVal = analogRead(potPin);
  // volt = (5./1023.) * potVal;
  // Serial.print("The potVal is: ");
  // Serial.println(potVal);
  // Serial.print("The corresponding Voltage is:");
  // Serial.println(volt);
  // delay(wait);

  //Example 2
  potVal = analogRead(potPin);
  //Linear brightness
  // brightness = (255./1023.) * potVal;

  //Exponential Brightness
  brightness = pow(2, potVal/127.875) - 1;
  Serial.print("The potVal is: ");
  Serial.println(potVal);
  Serial.print("The corresponding PWM Value is:");
  Serial.println(brightness);
  analogWrite(ledPin, brightness);
  delay(wait);

}