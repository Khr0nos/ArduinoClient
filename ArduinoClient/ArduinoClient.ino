/*
 Name:		ArduinoClient.ino
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#include <ArduinoCloudClient.h>
#include <Data.h>
#include <Bridge.h>

CloudClient client("https://cloudtfg.azurewebsites.net", "/api/historicdata");
int interval = 8000;
int randomvalue;

// the setup function runs once when you press reset or power the board
void setup() {
    // Initialize Bridge
    Bridge.begin();

    // Initialize Serial
    SerialUSB.begin(9600);

    // Wait until a Serial Monitor is connected.
    while (!SerialUSB) {}
    SerialUSB.println("Prova de client amb JSON");

    randomSeed(analogRead(0));
}

// the loop function runs over and over again until power down or reset
void loop() {
    randomvalue = random(15, 25);
    char* data = "0";
    sprintf(data, "%i", randomvalue);
    Data d(6, data, 1);
    String content;
    int code = client.post(d, &content);

    SerialUSB.println("Body response");
    SerialUSB.println(content);
    SerialUSB.println("status code");
    SerialUSB.println(code);

    if (code == 201) {  // 201 Created
        StaticJsonBuffer<400> buffer;  //ajustar mida?
        JsonObject& response = buffer.parseObject(content);

        if (response.success()) {
            SerialUSB.println("Response parsed ok");
            interval = response["Interval"];  // actualitzar interval proporcionat pel servei
        } else {
            SerialUSB.println("parse error");
            interval = 8000;
        }
    }
    
    delay(interval);
}
