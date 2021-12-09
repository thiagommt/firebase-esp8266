#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <Ultrasonic.h> 

#define FIREBASE_HOST "iot2021-d27af-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH "mZl2OtTvUh4VQ7y2Tt1Jt1JkfGDyoXEeJdtK27oP" 

#define ON_Board_LED 2  

const char* ssid = "SATC IOT"; 
const char* password = "IOT2021#"; 

Ultrasonic ultrasonic(D3, D2); 
long distancia;

void setup() {
  Serial.begin(115200);
  delay(500);
  
  WiFi.begin(ssid, password); 
  Serial.println("");
    
  pinMode(ON_Board_LED,OUTPUT); 
  digitalWrite(ON_Board_LED, HIGH); 

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(ON_Board_LED, LOW);
    delay(250);
    digitalWrite(ON_Board_LED, HIGH);
    delay(250);
  }
  
  digitalWrite(ON_Board_LED, HIGH); 
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  distancia = ultrasonic.Ranging(CM);
  Serial.print("Distancia: "); 
  Serial.print(distancia);
  Serial.println("cm"); 
  delay(1000); 
  String dataSend = String(distancia) + " cm"; 

  Firebase.setString("Vinicius/Value",dataSend); 

  // Conditions for handling errors.
  if (Firebase.failed()) { 
      Serial.print("Setting /Value failed :");
      Serial.println(Firebase.error());  
      delay(500);
      return;
  }

  Serial.println("Setting successful");
  Serial.println();
  delay(5000);
 
}
