#include <Arduino.h>
#include "remote_test_site_fsm.hpp"

#define DEBUG_PRINT

RemoteTestSiteFSM fsm = RemoteTestSiteFSM();

void setup()
{
  Serial.begin(115200);
  Serial.println("Remote test site main application");
}

void loop()
{
  fsm.Update();
}
