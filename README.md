// # Arduino_Sensor_2018

// This is our program

int ThermistorPin = 0;
float adc;
float T;
float B = 3435.0;
float R0 = 10000;
float T0 = 298.15;

void setup() {
Serial.begin(9600);
}

void loop() {
  adc = analogRead(ThermistorPin);
  T = 1/(log((R0*1024/adc - R0)/R0)/B+1/T0) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" °C"); 
  delay(500);
}
