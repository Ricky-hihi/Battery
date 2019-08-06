int analogPin = A1 ;
int MyArray[11] = {0} ;
int val ;
byte blank ;

void setup() {
  
  Serial.begin(9600) ;
}

void loop() {
  
  val = map(analogRead(analogPin),720,850,0,100) ;
  // 把感測器值填入陣列中
  for (byte i = 0 ; i<11 ; i++){
    MyArray[i] = {val} ;
    delay(100) ;
    }
    
  // 把陣列中的值由大排到小
    for (byte m = 0 ; m<11 ; m++ ){
      for (byte n = m+1 ; n<11 ; n++){
        if (MyArray[m] < MyArray[n]){
          blank = MyArray[m] ;
          MyArray[m] = MyArray[n] ;
          MyArray[n] = blank ;
          }
        } 
      }
      
  // 印出排序後的陣列
    if (MyArray[5]<0 or MyArray[5]>100){
      if (MyArray[5]<0){
        Serial.print("battery capacity : ") ;Serial.print(0) ;Serial.println("%") ;
        }
      if (MyArray[5]>100){
        Serial.print("battery capacity : ") ;Serial.print(100) ;Serial.println("%") ;
        }
      }else{
        Serial.print("battery capacity : ") ;Serial.print(MyArray[5]) ;Serial.println("%") ;
        }

}
