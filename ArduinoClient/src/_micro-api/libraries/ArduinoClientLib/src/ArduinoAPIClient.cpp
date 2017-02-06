/*
 Name:		ArduinoAPIClient.cpp
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#include "ArduinoAPIClient.h"

ArduinoAPIClient::ArduinoAPIClient() {
}

ArduinoAPIClient::~ArduinoAPIClient() {
    //request.flush();
    //request.close();
}

Data::Data() {
    idData = 0;
    idDevice = 3;
    date = "";
    value = "0.0";
    iddatatype = 1;
    dataToDevice = false;
    dataAck = false;
    dataAux = "";
}

Data::Data(int device, String datavalue, int dataType, bool toDevice, bool Ack, String Aux) {
    idData = 0;
    idDevice = device;
    date = "";
    value = datavalue;
    iddatatype = dataType;
    dataToDevice = toDevice;
    dataAck = Ack;
    dataAux = Aux;
}

Data::~Data() {}

void Data::Serialize(char* json, size_t maxSize, bool indented) {
    StaticJsonBuffer<POST_DATA_SIZE> buffer;    //buffer estàtic

    JsonObject& root = buffer.createObject();
    root["IdhistoricData"] = idData;
    root["Iddevice"] = idDevice;
    root["HistDataDate"] = date;
    root["HistDataValue"] = value;
    root["IddataType"] = iddatatype;
    root["HistDataToDevice"] = dataToDevice;
    root["HistDataAck"] = dataAck;
    root["HistDataAux"] = dataAux;

    if (indented) {
        root.prettyPrintTo(json, maxSize);
    } else {
        root.printTo(json, maxSize);
    }
}

bool Data::Deserialize(Data& data, char* json) {
    StaticJsonBuffer<POST_DATA_SIZE> buffer;

    JsonObject& root = buffer.parseObject(json);
    data.idData = root["IdhistoricData"];
    data.idDevice = root["Iddevice"];
    data.date = root["HistDataDate"].asString();
    data.value = root["HistDataValue"].asString();
    data.iddatatype = root["IddataType"];
    data.dataToDevice = root["HistDataToDevice"];
    data.dataAck = root["HistDataAck"];
    data.dataAux = root["HistDataAux"].asString();
    return root.success();
}
