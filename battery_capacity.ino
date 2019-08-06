const int T = 10 ;

int val[T] ;
int readIndex = 0 ;
int total = 0 ;
int average = 0 ;
int analogPin = A3 ;

void setup() {
  
  Serial.begin(9600) ;
  for (int i = 0; i < T ; i++) {
    val[i] = 0;
  }
  //將所有讀數初始化為0
}

void loop() {

  total = total - val[readIndex];                                    //減去最後一次讀數
  val[readIndex] =map(analogRead(analogPin),720,845,0,100) ;         //從感應器讀值並把範圍設定成0~100
  total = total + val[readIndex];                                    //將讀值加到總數中
  readIndex = readIndex + 1;                                         //下一次

  if (readIndex >= T) {
    readIndex = 0 ;
    }
  //加完10次後就進到下一個10次
  average = total / T ;                           //計算平均 
 
  if (average<0 or average>100) {
    if (average<0) {
      Serial.print("battery capacity: ") ;Serial.println(0) ;
      }
    if (average>100) {
      Serial.print("battery capacity: ") ;Serial.println(100) ;
      } 
    }else{
      Serial.print("battery capacity: ") ;Serial.println(average) ;
      }
  Serial.println(average) ;
  delay(100) ;

}
