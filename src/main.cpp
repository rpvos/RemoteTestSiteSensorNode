#define DEBUG_PRINT 1

#include <Arduino.h>
#include "remote_test_site_fsm.hpp"

RemoteTestSiteFSM fsm = RemoteTestSiteFSM();

void setup()
{
  Serial.begin(9600);
  Serial.println("Remote test site sensor application");
  // Serial speed of LoRa
  Serial1.begin(115200);
  // Serial speed of Murata soil sensor
  Serial2.begin(9600);
}

void loop()
{
  fsm.Update();
}
