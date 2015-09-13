
//variables to store pins to be interfaced with the Infrared proximity sensors
int sensorPinLeft = A0;    
int sensorPinRight =A1;
     
//variables to store values read from analog sensors
int sensorValueLeft = 0;
int sensorValueRight = 0;


//pins to interface motor driver digital pins
int motorL1 = 8;
int motorL2 = 9;
int motorR1 = 10;
int motorR2 = 11;


void setup() {
  //declare motor pins as OUTPUT
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
}

void loop() {
   //store value of analog input from proximity sensors
   sensorValueLeft = analogRead(sensorPinLeft);
   sensorValueRight = analogRead(sensorPinRight);
   
   //check if left sensor is sensing anything, if it does then move bot to right
   if((sensorValueLeft > 20) && (sensorValueRight < 20)){
     digitalWrite(motorL1, HIGH);
     digitalWrite(motorL2, LOW);
     digitalWrite(motorR1, LOW);
     digitalWrite(motorR2, HIGH);
   }
   
   //check if right sensor is sensing anything, if it does then move bot to left
   else if((sensorValueLeft < 20) && (sensorValueRight > 20)){
     digitalWrite(motorL1, LOW);
     digitalWrite(motorL2, HIGH);
     digitalWrite(motorR1, HIGH);
     digitalWrite(motorR2, LOW);
   }
   
   //check if no obstacle is being sensed, then move forward
   else if((sensorValueLeft < 20) && (sensorValueRight < 20)){
     digitalWrite(motorL1, HIGH);
     digitalWrite(motorL2, LOW);
     digitalWrite(motorR1, HIGH);
     digitalWrite(motorR2, LOW);
   }
   else {
     digitalWrite(motorL1, LOW);
     digitalWrite(motorL2, LOW);
     digitalWrite(motorR1, LOW);
     digitalWrite(motorR2, LOW);
   }
    
}

 
