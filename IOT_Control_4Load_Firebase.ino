/* 
 https://arduino.esp8266.com/stable/package_esp8266com_index.json
 */

#include <ESP8266WiFi.h> 
#include <FirebaseESP8266.h>

#define ssid "M.Ansar"  //WiFi SSID
#define password "78612345"  //WiFi Password
#define FIREBASE_HOST "-------------------------" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "-----------------" //Your Firebase Auth Token

FirebaseData firebaseData;

uint8_t Relay1 = D0;
uint8_t Relay2 = D1;
uint8_t Relay3 = D2;
uint8_t Relay4 = D3;

uint8_t LED = D4;

int load1, load2, load3, load4, Power;

void setup() {  
Serial.begin(9600);
  
pinMode(Relay1, OUTPUT); digitalWrite(Relay1, HIGH);  
pinMode(Relay2, OUTPUT); digitalWrite(Relay2, HIGH);
pinMode(Relay3, OUTPUT); digitalWrite(Relay3, HIGH);
pinMode(Relay4, OUTPUT); digitalWrite(Relay4, HIGH);

pinMode(LED, OUTPUT); 

WiFi.begin (ssid, password);
while(WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
}
Serial.println ("");
Serial.println ("WiFi Connected!");
Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
digitalWrite(LED,HIGH);
delay(100);
}

void loop() {

if(Firebase.get(firebaseData,"/P1")) {
 if (firebaseData.dataType() == "string") {
 Power = firebaseData.stringData().toInt();
 }
}

if(Firebase.get(firebaseData,"/L1")) {
 if (firebaseData.dataType() == "string") {
 load1 = firebaseData.stringData().toInt();
 }
}

if(Firebase.get(firebaseData,"/L2")) {
 if (firebaseData.dataType() == "string") {
 load2 = firebaseData.stringData().toInt();
 }
}

if(Firebase.get(firebaseData,"/L3")) {
 if (firebaseData.dataType() == "string") {
 load3 = firebaseData.stringData().toInt();
 }
}

if(Firebase.get(firebaseData,"/L4")) {
 if (firebaseData.dataType() == "string") {
 load4 = firebaseData.stringData().toInt();
 }
}

if(Power==0){
digitalWrite(Relay1, load1);  
digitalWrite(Relay2, load2);
digitalWrite(Relay3, load3);
digitalWrite(Relay4, load4);
}else{
digitalWrite(Relay1, HIGH);  
digitalWrite(Relay2, HIGH);
digitalWrite(Relay3, HIGH);
digitalWrite(Relay4, HIGH);  
 }
}
