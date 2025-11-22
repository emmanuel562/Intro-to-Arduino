//Variables
int redPin = 9; 
int greenPin = 10; 
int bluePin = 11;
int br = 9600; 
int sd = 200;
int ld = 1000;
int i;
int input;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // i++ Increment by 1
  // i = i + 2 Increment by 2

  Serial.println("How many blinks doyou want?:  ");
  while(Serial.available()== 0){}
  input = Serial.parseInt();


  for (i= 0; i < input; i++){
  color(255, 0, 0);
  delay(sd);
  color(0, 255, 0);
  delay(sd);
  color(0, 0, 255);
  delay(sd);
  color(0, 0, 0);
  delay(ld);
  }


}

void color(int r, int g, int b){
  //Sets 
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}