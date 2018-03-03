
/*
 * Aktualizacje do programu będą tylko dostępne na github:
 * github.com/mateuszpiela
 * lub na stronie głównej
 * mateuszpiela.altervista.org
 */

#define DHT_ENABLED
#if defined DHT_ENABLED
#include <DHT.h>
//Ustawienia czujnika
#define DHTPIN 4  //PIN
DHT dht;
#endif

//SZYBKOŚĆ PORTU SERIAL
#define BAUDRATE_SER 9600

// NIE DOTYKAĆ (Wersja Softa)
String soft_version = "0.0.1 Alpha";
// NIE DOTYKAĆ
String text = "";

void setup() {
  Serial.begin(BAUDRATE_SER);
  #if defined DHT_ENABLED
  dht.setup(DHTPIN);
  #endif
  
}

void loop() {
  if(Serial.available() > 0) {
  text = Serial.readStringUntil('\n');
  if (text == "") {

  }
  else if (text == "/funkcje") {
    #if defined DHT_ENABLED
    Serial.println("DHT");
    #else
    Serial.println("NODHT");
    #endif
  }
  else if (text == "/wersja") {
    Serial.println(soft_version);
  }
  #if defined DHT_ENABLED
  else if (text == "/temp") {
  float t = dht.getTemperature();
   if (isnan(t))
   {
    Serial.println("ERROR");
   }
   else
   {
    Serial.println(t);
   }
  }
  else if (text == "/wilg"){
  float h = dht.getHumidity();
   if (isnan(h))
   {
    Serial.println("ERROR");
   }
   else
   {
    Serial.println(h);
   }
  }
  #endif
  }
}
