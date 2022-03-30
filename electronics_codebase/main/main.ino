/**
   PostHTTPClient.ino

    Created on: 21.11.2016

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* this can be run with an emulated server on host:
        cd esp8266-core-root-dir
        cd tests/host
        make ../../libraries/ESP8266WebServer/examples/PostServer/PostServer
        bin/PostServer/PostServer
   then put your PC's IP address in SERVER_IP below, port 9080 (instead of default 80):
*/
//#define SERVER_IP "10.0.1.7:9080" // PC address with emulation on host
#define SERVER_IP "http://thesunrider.pythonanywhere.com"

#ifndef STASSID
#define STASSID "lasec_security"
#define STAPSK  "lasec@123"
#endif

#define LED1_PIN 0
#define LED2_PIN 2


bool LED1_status = false;
bool LED2_status = false;

void setup() {

  Serial.begin(115200);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.println();

  WiFi.begin(STASSID, STAPSK);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // wait for WiFi connection
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
  HTTPClient http;
  String payload;

  Serial.print("[HTTP] begin...\n");
  // configure traged server and url
  http.begin(client, SERVER_IP "/device_status"); //HTTP

  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header and body
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");

          String status_dev = payload;
    Serial.println(status_dev);
    if (status_dev.length() > 1) {
      int led1 = status_dev.substring(0, 1).toInt();
      int led2 = status_dev.substring(2, 3).toInt();
      Serial.println("startman");
      Serial.println(led1);
      Serial.println(led2);
      Serial.println();

      if (led1 == 1)
        LED1_status = true;
      else 
        LED1_status = false;


      if (led2 == 1)
        LED2_status = true;
      else 
        LED2_status = false;


      if (LED1_status)
        digitalWrite(LED1_PIN, HIGH);
        
      else
        digitalWrite(LED1_PIN, LOW);

      if (LED2_status)
        digitalWrite(LED2_PIN, HIGH);
      else
        digitalWrite(LED2_PIN, LOW);


      delay(700);
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      delay(500);
    }
    
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();

  }
}
