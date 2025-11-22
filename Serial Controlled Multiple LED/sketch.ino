int br = 9600;
int redPin = 2; 
int greenPin = 7; 
int yellowPin = 4; 
String led;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  Serial.println("Which light do you want to turn on? red, green, or yellow: ");
  Serial.println("Use -off- toturn the light off ");
  while(Serial.available() == 0){}
  led = Serial.readString();
  led.toLowerCase();
  led.trim();
  Serial.println(led); 
  
  if (led == "red"){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
  else if (led == "green"){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
  else if (led == "yellow"){
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
  }
  else if (led == "off") {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
}
  else {
    Serial.println("Invalid color! Try red, green, or yellow.");
  }
}
