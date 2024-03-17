#include <TimeInterrupt.h>  //library for timer interrupts
float temp;//declaring a variable temp
  void setup(){
  // put your setup code here, to run once:

  Serial.begin(9600);//initialize serial connection with computer
  pinMode(13,OUTPUT);//setting 13th pin as output
}
void printMessage(){
  Serial.print("Temperature: ");//to display temerature: on serial monitor
  Serial.print(temp);//to print varying temp values
  Serial.print("\xC2\B0");//to print degree symbol
  Serial.print("C");//centigrade
}
void loop(){
  // put your main code here, to run repeatedly:

  int A=analogRead(A0);//reading analog values from LM35 sensor
  float volt=A*(5.0/1024.0);//converting analog readings into voltage
  temp=volt*100;//converting voltag einto centigrade
  if(temp<30)
  {
    digitalWrite(13,HIGH);//sending high signal to led 
    TimeInterrupt.addInterrupt(printMessage,100);//adding an interrupt to blink the led by calling 'printMessage' for 100ms
    digitalWrite(13,LOW);//sending low signal to led 
    TimeInterrupt.addInterrupt(printMessage,250);//call printMessage for every 250ms
  }
  else if(temp>30)
  {
    digitalWrite(13,HIGH);
    TimeInterrupt.addInterrupt(printMessage,100);
    digitalWrite(13,LOW);
    TimeInterrupt.addInterrupt(printMessage,500);//call printMessage for every 500ms
  }
    
  }
  
