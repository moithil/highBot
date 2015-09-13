char line1;
int flag;

int motorL1 = 8;
int motorL2 = 9;
int motorR1 = 10;
int motorR2 = 11;

void setup(){

  // initialize the serial communications:
  Serial.begin(9600);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
 
}

void loop()
{
  if (Serial.available()) {
    delay(100);
    
    while (Serial.available() > 0) {
  
      line1=Serial.read();
      
      if(line1=='f'){
        flag = 0;
      }
      if(line1=='s'){
        flag = 1;
      }
      if(line1=='r'){
        flag = 2;
      }
      if(line1=='l'){
        flag = 3;
      }
      if(line1=='b'){
        flag = 4;
      }
      
      if(flag == 0){
        digitalWrite(motorL1,HIGH);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,HIGH);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 1){
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 2){
        digitalWrite(motorL1,HIGH);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 3){
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,HIGH);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 4){
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,HIGH);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,HIGH);
      }  
    }
  }
}
