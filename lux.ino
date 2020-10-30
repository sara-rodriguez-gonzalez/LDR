void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

  float vin = 0;
  float vout = 0;
  float rl = 0;
  float il = 0;

void loop() {
  
  vin = analogRead(A0);

  vout = (vin*5)/1023;

  Serial.println("");
  Serial.print("Voltaje analogico: ");
  Serial.print(vout);
  Serial.println(" V");
  
  rl = 615.01*((5/vout)-1);

  Serial.print("Resistencia en el LDR: ");
  Serial.print(rl);
  Serial.println(" Ohms");
  
  il = pow((rl/127562),-1.16550117);
  
  Serial.print("Intensidad luminosa: ");
  Serial.print(il);
  Serial.println(" lux\n");

  if(il<3500)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  
  delay(1000);
}
