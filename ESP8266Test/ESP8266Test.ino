#include <SoftwareSerial.h>
int ledPin = 4;
SoftwareSerial mySerial(10, 11); // RX, TX
bool flag = false;
int status = 0;
void startServer();
String data;
void setup() {
  // Open serial communications and wait for port to open:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
  Serial.println("WIFI test!");
 
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.println("Hello, world?");
  delay(3000);
  mySerial.println("AT+RST");
  delay(3000);
  startServer();
  delay(3000);

 /*while (1) {                            //当串口有完成数据返回时，结束语句     
     if(mySerial.find("Technologcy")==true)
      {
          Serial.println("esp8266 WIFI ready ");  
           break;
      }
      //Serial.println("=================================");  
      if (mySerial.available()) {
          Serial.print(mySerial.readString());
        //mySerial.print("AT+CIFSR\n");
      }
  }*/
  //Serial.println("Hello word !");  
}

 int index;
 int error;
 String str;
 int closed;
 int rec = -1;
 
void loop() { // run over and over   
  /*if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }*/
  if(flag){
    flag = false;
    switch(status){
    case 1:
      // 设置 服务器端口     
      mySerial.println("AT+CIFSR"); 
      Serial.println("AT+CIFSR");   
      delay(2000);  
      break;
    case 2:
      mySerial.println("AT+CIPSERVER=1,1212"); 
      //Serial.println("AT+CIPSERVER=1,1212");   
      delay(2000);  
      break;  
    case 3:
      // 接受数据  
      if (mySerial.available()){
         str = mySerial.readString(); 
         Serial.print(str);         
      }
      break;          
    }
  }
  
  if (!flag && mySerial.available()) {
      //Serial.println(mySerial.readString());
      str = mySerial.readString();
      index = str.lastIndexOf('K');    
      error = str.lastIndexOf('R'); 
      closed = str.lastIndexOf("CLOSED");
      rec = str.lastIndexOf(":");
      Serial.println(str);
      if(rec > 1){
         Serial.print("rec ; ");
         Serial.println(rec );
         Serial.println(str.substring(rec+1, rec+2));
         String c = str.substring(rec+1, rec+2);
         if(c == "1"){
             digitalWrite(ledPin, HIGH);
         }else if(c == "0"){
             digitalWrite(ledPin, LOW);
         }
      }
      //Serial.print("closed: ");    
      //Serial.println(closed);
      if(index > 1 ){
          Serial.println("++++++++++++++++++++++");
          if(str.substring(index -1, index+1) == "OK"){
              Serial.println("pelase input next cmd : ");
              flag = true;
              delay(1000);
              status ++ ;
          }
          Serial.println(str.substring(index -1, index+1));
        }
      }else if(error > 4){
        if(str.substring(error -4, error+1) == "ERROR"){
              Serial.println("pelase input cmd : ");
              flag = true;
              delay(3000);
              //status ++ ;
          }
      }else if(str.lastIndexOf("CLOSED") >= 0 ){
          flag = true;
          //Serial.println("TCP DONE !");
      }
  
  /*if (Serial.available()) {
    //int value = Serial.read();
    mySerial.print(Serial.readString());         
  }*/
}


// 开机启动设置esp8266为 AP 模式
void startServer(){       
  mySerial.println("AT+CIPMUX=1");  
  //mySerial.println("AT+CWJAP="\"\"");  
  //if (mySerial.available()) {
  //   Serial.println(mySerial.readString()); 
  //   if
 // }
  //delay(1000);
  // 设置 服务器端口
  /*mySerial.write("AT+CIPSERVER=1,1212\n");
  if (mySerial.available()) {
    Serial.write(mySerial.read());    
  } */
}

