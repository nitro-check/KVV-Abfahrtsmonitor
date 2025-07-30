
#include "StateChangeController.h"
#include "search.h"
#include "ImplementedHardware.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //Initialize implemented hardware
  ImplementedHardware& hardware = ImplementedHardware::getInstance();

  StateChangeController controller(
      new StateActionExecutor(),
      new State(State::SETUP),
      new SystemVariables()
  );

  controller.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}