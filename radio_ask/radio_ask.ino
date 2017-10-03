#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 10, 11, 5);

void setup() {
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");

}

unsigned long t = millis();
const int pause_ms = 200;

void loop() {
  if (millis() - t > pause_ms) {
    t = millis();
    const char *msg = "hello";
    driver.setModeTx();
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
  }

  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  driver.setModeRx();
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    // Message with a good checksum received, dump it.
    //    driver.printBuffer("Got:", buf, buflen);
    Serial.println("received: ");
    for (uint8_t i = 0; i < buflen; i++)
    {
      if (i % 16 == 15)
        Serial.println(buf[i], HEX);
      else
      {
        Serial.print(buf[i], HEX);
        Serial.print(' ');
      }
    }
    Serial.println("");
  }

}
