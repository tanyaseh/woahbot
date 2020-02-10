#include <Servo.h>
Servo servoleft;
Servo servoright;
String inputstr = "";

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  inputstr.reserve(200);
  servoleft.attach(8);
  servoright.attach(5);
  servoleft.write(0);
  servoright.write(0);
  
}

void turn() {
  for (pos = 0; pos <= 120; pos += 1) {
    servoleft.write(pos);
//    servoright.write(pos);
    delay(3);
  } 
  for (pos = 0; pos <= 90; pos += 1) {
//    servoleft.write(pos);
    servoright.write(pos);
    delay(3);
  } 
  
  delay(1000);


  
  for (pos = 120; pos >= 0; pos -= 1) {
//    servoleft.write(pos);
    servoright.write(pos);
    delay(1);
  } 
  
  delay(100);
  
  for (pos = 90; pos >= 0; pos -= 1) {
    servoleft.write(pos);
//    servoright.write(pos);
    delay(.1);
  } 

  for (pos = 0; pos <= 20; pos += 1) {
    servoleft.write(pos);
//    servoright.write(pos);
    delay(3);
  } 
  for (pos = 0; pos <= 40; pos += 1) {
//    servoleft.write(pos);
    servoright.write(pos);
    delay(3);
  } 

  for (pos = 20; pos >= 0; pos -= 1) {
    servoleft.write(pos);
//    servoright.write(pos);
    delay(3);
  } 
  for (pos = 40; pos >= 0; pos -= 1) {
//    servoleft.write(pos);
    servoright.write(pos);
    delay(3);
  } 

  
}

void stop() {
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.print("0");
//  if(Serial.available() > 0) {
    char data = (char)Serial.read();
    inputstr += data;
    if (inputstr.indexOf('1') > 0) {
      Serial.print(1);
      turn();
      stop();
      inputstr = "";
      }

//     char data = Serial.read();
//   char str[2];
//    str[0] = data;
//    str[1] = '\0';
//    Serial.print(str);
//    }
  
  delay(100);
}
