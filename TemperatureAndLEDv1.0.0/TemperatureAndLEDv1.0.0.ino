int analogPin = A1;

int val = 0;  // variable to store the analog voltage value read from the pin
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
  float temp = -85.5 * voltage + 157.0;

  float tempArr[5] = {temp, lastTemps[0], lastTemps[1], lastTemps[2], lastTemps[3]};
  for (int i = 0; i < 5; i++) lastTemps[i] = tempArr[i];

  float avgTempLastFive = (lastTemps[0] + lastTemps[1] + lastTemps[2] + lastTemps[3] + lastTemps[4]) / 5;

  Serial.print("voltage: ");
  Serial.println(voltage, 3);
//  Serial.print("temp: ");
//  Serial.println(temp, 3);
  Serial.print("Recent Temp: ");
  Serial.println(avgTempLastFive);
//  Serial.println(" ");
  
  if(temp > 25){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  else if(temp >= 15 && temp <= 25){
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
}
