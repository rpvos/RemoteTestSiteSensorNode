#include <Arduino.h>
#include "remote_test_site_fsm.hpp"

RemoteTestSiteFSM fsm;

void setup()
{
  Serial.begin(9600);
  Serial.println("Remote test site main application");

  fsm = RemoteTestSiteFSM();
}

void loop()
{
  fsm.Update();
}
