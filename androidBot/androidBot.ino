//NOTE : MAY NOT WORK IF YOU SEND A "STRING" INSTEAD OF A 'C' (single character) from Serial communication!

char line1;                               //char variable to store message serially received.
int flag;                                 //flag to hold current state of operation, like forward movement.


//pins to be interfaced to the motor
int motorL1 = 8;
int motorL2 = 9;
int motorR1 = 10;
int motorR2 = 11;

void setup(){

  // initialize the serial communications:
  Serial.begin(9600);
  
  //declare motor pins as OUTPUT
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
}

void loop()
{
  if (Serial.available()) {               //check if serial communication has started or not
    delay(100);                           //give a delay to microcontroller to prepare for further operations
  
      while (Serial.available() > 0) {    //while loop commands take place only when Seril is receiving something
  
      line1 = Serial.read();              //store message received in line1 variable
      
      if(line1=='f'){                     //check if line1 holds value 'f'
        flag = 0;                         //trigger the flag to store value 0
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
      
      if(flag == 0){                      //if flag contains 0 then forward movement sequnce takes place
        digitalWrite(motorL1,HIGH);       //FORWARD sequnce
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,HIGH);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 1){                      //STOP sequnce
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 2){                      //RIGHT movement sequence
        digitalWrite(motorL1,HIGH);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 3){                      //LEFT movement sequence
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,LOW);
        digitalWrite(motorR1,HIGH);
        digitalWrite(motorR2,LOW);
        
      }
      if(flag == 4){                      //BACKWARD sequence
        digitalWrite(motorL1,LOW);
        digitalWrite(motorL2,HIGH);
        digitalWrite(motorR1,LOW);
        digitalWrite(motorR2,HIGH);
      }  
    }
  }
}
