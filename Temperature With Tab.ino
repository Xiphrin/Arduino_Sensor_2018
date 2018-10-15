int ThermistorPin = A0;
int adc;
unsigned int TempTab[][2] =
{
{50,0},
{100,390},
{150,1677},
{200,2544},
{250,3237},
{300,3837},
{350,4382},
{400,4895},
{450,5392},
{500,5883},
{550,6379},
{600,6890},
{650,7426},
{700,8002},
{750,8636},
{800,9355},
{850,10203},
{900,11260},
{950,12695},
{971,4985},
{1023,16567}
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int i;
  int adco, adci, tempo, tempi;
  int result;
  // put your main code here, to run repeatedly:
  adc = analogRead(ThermistorPin);
  // Serial.println(adc);
  for (i = 1; adc > TempTab[i][0];i++);
  adco = TempTab[i-1][0];
  adci = TempTab[i][0];
  tempo = TempTab[i-1][1];
  tempi = TempTab[i][1];
  
  result = map(adc, adco, adci, tempo, tempi);

  Serial.print((result-4000)/100); 
  Serial.print(".");
  Serial.println((result-4000)%100); 
  delay(500);
}
