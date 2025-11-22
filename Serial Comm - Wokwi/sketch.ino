// counter variables
int cnt = 1;
int wait = 1000;
String cntMess = "Your counter is: ";

// addition variables
int x = 3;
int y = 4;
int z;
String add = "X + Y = ";

// Area var
const float pi = 3.142;
int r = 1;
String areaMess = "The area of a circle whose radius is: ";
float area;

int redLed = 10;
String onMess = "The LED is ON!";
String offMess = "The LED is OFF!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLed, HIGH);
  Serial.println(onMess);
  delay(wait/2);
  digitalWrite(redLed, LOW);
  Serial.println(offMess);
  delay(wait/2);



  //counter
  Serial.print(cntMess);
  Serial.println(cnt);
  cnt = cnt + 1;
  delay(wait);

  // addition
  z = x + y;
  Serial.print(add);
  Serial.println(z);
  x = x + 1;
  y = y + 1; 
  delay(wait);
  
  // Area calculator
  area = pi * r * r;
  Serial.print(areaMess);
  Serial.println(area);
  r = r + 1;
  delay(wait);
}