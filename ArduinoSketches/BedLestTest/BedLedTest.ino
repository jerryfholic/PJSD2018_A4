#include "ESP8266WiFi.h"
#include <Wire.h>

#define I2C_SDL    D1
#define I2C_SDA    D2
#define AAN true
#define UIT false

const char* ssid = "RaspberryA4";
const char* password =  "kamerplant";
char buffer_array[3];
int i = 0;
bool new_data_flag = false, led_status = false, led_update = true;
String request;
unsigned char vorige_schakelaar = 0x00, schakelaar;

WiFiServer wifiServer(80);

void setup() {

  pinMode(D5, OUTPUT);
  Wire.begin();

  Serial.begin(115200);

  delay(1000);

  Wire.beginTransmission(0x38);
  Wire.write(byte(0x03));          
  Wire.write(byte(0x0F));         
  Wire.endTransmission();

  Wire.beginTransmission(0x38); 
  Wire.write(byte(0x01));            
  Wire.write(byte(0<<4));            
  Wire.endTransmission();
     
  IPAddress ip(10,10,10,20); // where xx is the desired IP Address
  IPAddress gateway(10,10,10,1); // set gateway to match your network 
  IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network
  WiFi.config(ip, gateway, subnet);

/*
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }

  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
*/
  
}

void loop() {

  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {

      while (client.available() > 0) {
        request = client.readStringUntil('\r');
        //client.flush();
        //request = client.read();
        Serial.println(request);        
      }

      if (request == "sw") {
        Wire.beginTransmission(0x38);
        Wire.write(byte(0x00));
        Wire.endTransmission();
        Wire.requestFrom(0x38, 1);
        unsigned char inputs = Wire.read();
        unsigned char sensorwaarde = inputs & 0x0F;
        Serial.print("Digital in: ");
        Serial.println(sensorwaarde);
        client.print(sensorwaarde);
        request = "";
      }    

      if (request == "leds") {      

      
        
        Wire.beginTransmission(0x38); 
        Wire.write(byte(0x01));            
        Wire.write(byte(15<<4));            
        Wire.endTransmission();  
        client.print("LEDs aan");
        Serial.println("LEDs aan");
     
        delay(5000);   
        
        Wire.beginTransmission(0x38); 
        Wire.write(byte(0x01));            
        Wire.write(byte(0<<4));            
        Wire.endTransmission();  
        client.print("LEDs uit");
        Serial.println("LEDs uit");
        request = "";
       
      }
      
      delay(1000);
    }

    client.stop();
    Serial.println("Client disconnected");
  }

  Wire.beginTransmission(0x38);
  Wire.write(byte(0x00));
  Wire.endTransmission();
  Wire.requestFrom(0x38, 1);
  schakelaar = Wire.read();
  schakelaar = schakelaar & 0x01;

  if(schakelaar == 0x01){
    if(led_update == true){
      if(led_status == false){
        led_status = true;
        
        Wire.beginTransmission(0x38); 
        Wire.write(byte(0x01));            
        Wire.write(byte(15<<4));            
        Wire.endTransmission();
        
        led_update = false;
        Serial.println("leds aan");      
      }      
    }
    if(led_update == true){
      if(led_status == true){
        led_status = false;
        
        Wire.beginTransmission(0x38); 
        Wire.write(byte(0x01));            
        Wire.write(byte(0<<4));            
        Wire.endTransmission();
        
        led_update = false;
        Serial.println("leds uit");      
      }        
    }
  }

  if(schakelaar == 0x00){
    led_update = true;
  }
/*
  if(led_status = true){
    Wire.beginTransmission(0x38); 
    Wire.write(byte(0x01));            
    Wire.write(byte(15<<4));            
    Wire.endTransmission();
  }
  if(led_status = false){
     Wire.beginTransmission(0x38); 
     Wire.write(byte(0x01));            
     Wire.write(byte(0<<4));            
     Wire.endTransmission();
  }
  */
}
