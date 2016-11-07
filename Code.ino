int motorPinBack1 = 2; //connected to left motor (BLUE)
int motorPinFront1 = 3; //PWM (YELLOW)
int motorPinBack2 = 4; //connected to right motor (BLACK)
int motorPinFront2 = 5; //PWM (BLUE)
int sensPin=0;
int sensLDR=1;
int powerIR = 13; // 6.2K + 2.2K ohms resistor @ receiver
int powerLDR = 7; // 22K ohms resistor

void setup() {
pinMode(motorPinBack1,OUTPUT);
pinMode(motorPinFront1,OUTPUT);
pinMode(motorPinBack2,OUTPUT);
pinMode(motorPinFront2,OUTPUT);
pinMode(powerIR,OUTPUT);
pinMode(powerLDR,OUTPUT);
digitalWrite(powerIR,HIGH);
digitalWrite(powerLDR,HIGH);
analogReference(DEFAULT);
Serial.begin(9600);
}
void loop() {
int sens0 = (analogRead(sensPin));
int sens1 = (analogRead(sensLDR));
int IR = map(sens0,0,1023,100,0); // mapping of value
int LDR = map(sens1,0,1023,12,0); //
Serial.print("Lux = "); // PhotoResistor
Serial.print(LDR);
Serial.print(" | Infrared = "); // Infrared Sensor
Serial.println(IR);
delay(5);
analogWrite(motorPinFront1,255); // continous forward motion
analogWrite(motorPinBack1,LOW); // until any ostacle is
analogWrite(motorPinFront2,235); // sensed
analogWrite(motorPinBack2,LOW);
if(IR>=12 && LDR<=6) // DARKNESS / WITH FLOUROSCENT
{
digitalWrite(motorPinFront1,LOW); //move backward
digitalWrite(motorPinBack1,HIGH);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,HIGH);
delay(370);
analogWrite(motorPinFront1,200); //turn Right
digitalWrite(motorPinBack1,LOW);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,LOW);
delay(615);
}
else{
if(LDR>=7)
{
if(IR==83){ // DAYLIGHT
digitalWrite(motorPinFront1,LOW); //move backward
digitalWrite(motorPinBack1,HIGH);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,HIGH);
delay(370);
analogWrite(motorPinFront1,200); //turn Right
digitalWrite(motorPinBack1,LOW);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,LOW);
delay(615);
}
else{
if(IR==60){
digitalWrite(motorPinFront1,LOW); //move backward
digitalWrite(motorPinBack1,HIGH);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,HIGH);
delay(370);
analogWrite(motorPinFront1,200); //turn Right
digitalWrite(motorPinBack1,LOW);
digitalWrite(motorPinFront2,LOW);
digitalWrite(motorPinBack2,LOW);
delay(615);
}
}
}
}
}
