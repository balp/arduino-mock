
//#include "Arduino.h"
#include "Redbot.h"

static RedBotMotorsMock* redbotMotorMock = NULL;

RedBotMotorsMock* redbotMotorInstance() {
  if(!redbotMotorMock) {
    redbotMotorMock = new RedBotMotorsMock();
  }
  return redbotMotorMock;
}
void releaseRedbotMock() {
  if(redbotMotorMock) {
    delete redbotMotorMock;
    redbotMotorMock = NULL;
  }
}

