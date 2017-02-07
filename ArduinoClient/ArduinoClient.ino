#include <ArduinoCloudClient.h>
#include <Data.h>

/*
 Name:		ArduinoClient.ino
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#include <Bridge.h>

// the setup function runs once when you press reset or power the board
void setup() {
    // Initialize Bridge
    Bridge.begin();

    // Initialize Serial
    SerialUSB.begin(9600);

    // Wait until a Serial Monitor is connected.
    while (!SerialUSB) {}
    SerialUSB.println("Prova de client amb JSON");

    CloudClient client;
    Data d(6, "23.2", 1);
    char* response = NULL;
    int code = client.post(d, response);

    SerialUSB.println(response);
    SerialUSB.println(code);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
