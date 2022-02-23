#include <SoftwareSerial.h>

SoftwareSerial MyBlue(0,1);// RX | TX 

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
 // put your setup code here, to run once:
 MyBlue.begin(9600);

 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  while(MyBlue.available() > 0){ 
    
    //Read the RGB values from Serial Buffer => 123,50,255)
    int redValue = MyBlue.parseInt();
    int greenValue = MyBlue.parseInt();
    int blueValue = MyBlue.parseInt();
    
    setColor(redValue, greenValue, blueValue);

    serialFlush(); //Clear the Serial Buffer

  }
  
}

void setColor(int R, int G, int B){
  analogWrite(redPin, R);
  analogWrite(greenPin, G);
  analogWrite(bluePin, B);
}

void serialFlush(){
  while(MyBlue.available()>0){
    MyBlue.read();
  }
}
