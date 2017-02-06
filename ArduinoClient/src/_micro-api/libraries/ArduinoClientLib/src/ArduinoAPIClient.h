/*
 Name:		ArduinoAPIClient.h
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#ifndef _ArduinoClient_h
#define _ArduinoClient_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
    #include <Process.h>
    #include <ArduinoJson.h>
#else
	#include "WProgram.h"
#endif

#define POST_DATA_SIZE (JSON_OBJECT_SIZE(8))

class Data {

public:
    Data();
    Data(int device, String datavalue, int dataType, bool toDevice = false, bool Ack = false, String Aux = "");
    ~Data();

    void Serialize(char* json, size_t maxSize, bool indented = false);
    bool Deserialize(Data& data, char* json);

private:
    int idData;
    int idDevice;
    String date;
    String value;
    int iddatatype;
    bool dataToDevice;
    bool dataAck;
    String dataAux;
};

class ArduinoAPIClient {

public:
    ArduinoAPIClient();
    ~ArduinoAPIClient();

    

private:
    //Process request;
    String Base_URL;
    String Resource;
    Data data;
};

#endif

