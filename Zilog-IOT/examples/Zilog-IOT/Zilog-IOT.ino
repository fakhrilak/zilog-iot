#include "Zilog-IOT.h"
#include <ESP8266WiFi.h>

const char* ssid = "kafiraya";
const char* password = "helloworld";

int pinLED = 5; //PIN D1 ESP8266

void setup() 
{
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print("Connecting..");
  }
  
}
void loop(){
  if (WiFi.status() == WL_CONNECTED){
   String id1 = "15"; //Masukan Id yang kamu dapat dari aplikasi Zilog
   
   int Lampu = getParams(id1);//getstatefromdatabases
   
   Serial.println(Lampu);
   
    //write Your code here
    if (Lampu == 1){
      digitalWrite(pinLED,HIGH);
    }else if(Lampu == 0){
      digitalWrite(pinLED,LOW);
    }
  }
}
