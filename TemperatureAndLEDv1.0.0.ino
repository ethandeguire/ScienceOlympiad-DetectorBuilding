/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read
float lastTemps[] = {0.0,0.0,0.0,0.0,0.0};

void setup() {
  Serial.begin(9600);           //  setup serial
   
   // setup LEDS
   pinMode(2, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(7, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(analogPin);  // read the input pin
  float voltage = sensorValue * (5.0 / 1023.0);
  float temp = -85.3 * voltage + 159.0;

  float tempArr[5] = {temp, lastTemps[0], lastTemps[1], lastTemps[2], lastTemps[3]};
  for (int i = 0; i < 5; i++) lastTemps[i] = tempArr[i];

  float avgTempLastFive = (lastTemps[0] + lastTemps[1] + lastTemps[2] + lastTemps[3] + lastTemps[4]) / 5;

  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print("temp: ");
  Serial.println(temp);
//  Serial.print("Recent Temp: ");
//  Serial.println(avgTempLastFive);
//  Serial.println(" ");
  
  if(temp < 15){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  else if(temp >= 15 && temp < 25){
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
  }
    
  delay(1000);

  
//  digitalWrite(2, HIGH);
//  digitalWrite(4, LOW);   
//  digitalWrite(7, HIGH);      
//  delay(200);              
//  digitalWrite(2, LOW); 
//  digitalWrite(4, HIGH);
//  digitalWrite(7, LOW);  
//  delay(200);             
}

