int br = 9600;
int redPin = 9; 
int greenPin = 10; 
int yellowPin = 11; 
String led;
float brightness;
int input;
int off = 0;

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
  
  if (led == "red"){
    intensity();
    analogWrite(redPin, brightness);
    analogWrite(greenPin, off);
    analogWrite(yellowPin, off);
  }
  else if (led == "green"){
    intensity();
    analogWrite(greenPin, brightness);
    analogWrite(redPin, off);
    analogWrite(yellowPin, off);
  }
  else if (led == "yellow"){
    intensity();
    analogWrite(yellowPin, brightness);
    analogWrite(greenPin, off);
    analogWrite(redPin, off);
  }
  else if (led == "off") {
  analogWrite(redPin, off);
  analogWrite(greenPin, off);
  analogWrite(yellowPin, off);
}
  else {
    Serial.println("Invalid color! Try red, green, or yellow.");
  }
}

void intensity(){
  Serial.println("What is your desired brightness on a scale of 0 - 10?: ");
  while(Serial.available() == 0){}
  input = Serial.parseInt();
  brightness = pow(2, 0.8*input) -1;
  Serial.print(led +"at - "); 
  Serial.println(brightness);
}