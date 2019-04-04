#include "webhandler.h"

extern ESP8266WebServer server;
extern int RELAY_PIN;

void handleRelay() {
  for (uint8_t i = 0; i < server.args(); i++)
  {
      Serial.print(server.argName(i));
      Serial.print(" : ");
      Serial.println(server.arg(i).c_str());
    if (server.argName(i) == "rst") // 1 0
    {
      if (atoi(server.arg(i).c_str()))
      {
        Serial.println("HIGH");
        digitalWrite(RELAY_PIN, HIGH);
        delay(5000);
        Serial.println("LOW");
        digitalWrite(RELAY_PIN, LOW);
        server.sendHeader("Access-Control-Allow-Origin", "*");
        server.send(200, "text/plain", "OK");
        delay(10000);
        Serial.println("READY");
      }
    }
  }
}
