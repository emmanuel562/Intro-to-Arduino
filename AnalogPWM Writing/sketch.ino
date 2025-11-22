int ledPin = 10;
int wait = 500;
int low  = 0;
int dim = 100;
int bright = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // PMW pins
  analogWrite(ledPin, low);
  Serial.println(low);
  delay(wait);
  analogWrite(ledPin, dim);
    Serial.println(dim);
  delay(wait);
  analogWrite(ledPin, bright);
    Serial.println(bright);
  delay(wait);
}