int analogPin = A3 ;
int btr = 0 ;

void setup() {

  Serial.begin(9600) ;

}

void loop() {

  btr = analogRead(analogPin);
  Serial.print("battery capacity: ") ;Serial.println(btr) ;
  delay(1000) ;

}
