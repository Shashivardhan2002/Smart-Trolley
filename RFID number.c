void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()){
    Serial.print((char)Serial.read());
    
    }
  // put your main code here, to run repeatedly:

}
