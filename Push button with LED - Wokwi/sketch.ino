const int br = 9600;
const int btn = 2;
int result;
int dt = 100;
const int led = 4;

void setup() {
  Serial.begin(br);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
} 

void loop() {
  result = digitalRead(btn);
  Serial.println(result);
  if (result == 0){
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
    delay(dt);
}