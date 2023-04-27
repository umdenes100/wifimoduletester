#include "Enes100.h"
int fails = 0;
void setup() {
  // put your setup code here, to run once:
   Enes100.begin("It's lit", FIRE, 1, 8, 9);  // Aruco ID of 3. Rx Pin of 8. Tx Pin of 9.
   delay(1000);
   Enes100.println("Successfully connected to Vision System. Send functionality is working.");
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Enes100.updateLocation();
  Enes100.updateLocation();
  if (Enes100.location.x == -1) {
    Enes100.println("Recieved correct location for Aruco Number 1, this wifi module is in full working order.");
    while (true);
  } else {
    if (fails > 3) {
      Enes100.println("Did not recieve correct location, module may not be receiving properly.");
      Enes100.println("This module may have an issue, please alert a TF.");
      while (true);
    }else {
      fails +=1;
      //allow the module to retry 
    }
  }
  delay(500);
}
