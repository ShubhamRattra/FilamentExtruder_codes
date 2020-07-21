const int stepPin = 5;
const int dirPin = 2;
const int enPin = 8;
const int homeSwitchPin = 7;       //limit switch

void setup() {
  Serial.begin(9600);

  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(homeSwitchPin , INPUT);
  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);
  digitalWrite(dirPin,LOW);   // Enables the motor to move in a particular direction
}

void loop() {
 int homeSw = digitalRead( homeSwitchPin);
  Serial.print(digitalRead(dirPin));

    if( homeSw == HIGH && (digitalRead(dirPin) == LOW) ){
        motorStep(1000);
    }
    else if( homeSw == LOW && (digitalRead(dirPin) == LOW) ){
          digitalWrite(dirPin,HIGH);
          delay(100);        //delay bw change of revolution
    }

    if( (digitalRead(dirPin) == HIGH) ){
        motorStep(6000);   //change in number of steps when limit switch pressed
        digitalWrite(dirPin,LOW);
        delay(100);        //delay bw change of revolution
    }
}

void motorStep(int MAX){
   for(int x = 0; x < MAX; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(1000);         //change speed of stepper
        digitalWrite(stepPin,LOW);
        delayMicroseconds(1000);        //change speed of stepper
      }
}
