// We could aso use 3 potentiometer to read RGB value too, Idea💡


//Variables
int redPin = 9; 
int greenPin = 10; 
int bluePin = 11; 
String userChoice;
String presetChoice;
int redVal;
int greenVal;
int blueVal;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Start
  Serial.println("Instructions:");
  Serial.println("1. Enter any decimal color code to be mixed or select a preset color.");
  Serial.println("2. Preset colors are Red, Green, Blue, Yellow, Cyan, Magenta, and White.");
  Serial.println("3. Enter -mix- to enter decimal color code");
  Serial.println("3. Enter -preset- to select a preset color");
  Serial.println("3. Enter -off- to turn the light off");
  Serial.println(" ");

  //Waits to collect data
  while(Serial.available() == 0){}
  userChoice = Serial.readString();
  userChoice.toLowerCase();
  if (userChoice == "mix"){

    //Ask for redVal
    Serial.println("What is the Red Value? ");
    while(Serial.available() == 0){}
    redVal = Serial.parseInt();

    //Ask for greenVal
    Serial.println("What is the Green Value? ");
    while(Serial.available() == 0){}
    greenVal = Serial.parseInt();

    //Ask for blueVal
    Serial.println("What is the Blue Value? ");
    while(Serial.available() == 0){}
    blueVal = Serial.parseInt();

    Serial.println("Your color mix in RGB Format is: ");
    Serial.println(redVal);
    Serial.println(greenVal);
    Serial.println(blueVal);
    color(redVal, greenVal, blueVal);
  }

  // For Preset choice
  else if (userChoice == "preset"){
    Serial.println("What colour do you choose?:");
    while(Serial.available() == 0){}
    presetChoice = Serial.readString();
    presetChoice.toLowerCase();

    if (presetChoice == "red"){
      color(255, 0, 0);
    }
    else if (presetChoice == "green"){
      color(0, 255, 0);
    }
    else if (presetChoice == "blue"){
      color(0, 0, 255);
    }
    else if (presetChoice == "white"){
      color(255, 255, 255);
    }
    else if (presetChoice == "yellow"){
      color(255, 255, 0);
    }
    else if (presetChoice == "cyan"){
      color(0, 255, 255);
    }
    else if (presetChoice == "magenta"){
      color(255, 0, 255);
    }
    else {
      Serial.print("Your preset choice is: ");
      Serial.println(presetChoice);
      Serial.println("Please enter a valid color");
    }
  }

  // To turn LED off
  else if (userChoice == "off"){
    color(0, 0, 0);
  }
  else{
      Serial.print("Your input is: ");
      Serial.println(userChoice);
      Serial.println("Please enter a valid input");
      Serial.println("  ");
  }
}

void color(int r, int g, int b){
  //Sets 
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}