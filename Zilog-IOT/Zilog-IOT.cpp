#include "Zilog-IOT.h"

int getParams(String id){
  int Data;
  
  HTTPClient http;
  
  http.begin("http://fakhrilak-iotku.herokuapp.com/iot/v1/data/"+id);
  
  int httpCode = http.GET(); 
                        
  StaticJsonDocument<200> doc;
  
  if (httpCode > 0) { //Check the returning code
 
  String payload = http.getString();
   
  deserializeJson(doc, payload);  
   
  int data = doc["data"];
  
  if (data == 1){
    Data = 1;
  }else if(data == 0){
    Data = 0;
  }

}
 
http.end(); 
 

 
delay(200);

return Data;
}
