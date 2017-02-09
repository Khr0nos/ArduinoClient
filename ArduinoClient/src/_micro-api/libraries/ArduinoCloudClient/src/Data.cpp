#include "Data.h"

Data::Data() {
    idData = 0;
    idDevice = 6;
    date = "";
    value = "21.8";
    iddatatype = 1;
    dataToDevice = false;
    dataAck = false;
    dataAux = NULL;
}

Data::Data(int device, char* datavalue, int dataType, bool toDevice, bool Ack, char* Aux) {
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

void Data::Serialize(const Data& data, char* json, bool indented) {
    StaticJsonBuffer<POST_DATA_SIZE> buffer; //buffer estàtic

    JsonObject& root = buffer.createObject();
    root["IdhistoricData"] = data.idData;
    root["Iddevice"] = data.idDevice;
    root["HistDataDate"] = data.date;
    root["HistDataValue"] = data.value;
    root["IddataType"] = data.iddatatype;
    root["HistDataToDevice"] = data.dataToDevice;
    root["HistDataAck"] = data.dataAck;
    root["HistDataAux"] = data.dataAux;

    size_t size;
    if (indented) {
        size = root.measurePrettyLength() + 1;
        root.prettyPrintTo(json, size);
    }
    else {
        size = root.measureLength() + 1;
        root.printTo(json, size);
    }
}

bool Data::Deserialize(Data& data, char* json) {
    StaticJsonBuffer<POST_DATA_SIZE> buffer;

    JsonObject& root = buffer.parseObject(json);
    data.idData = root["IdhistoricData"];
    data.idDevice = root["Iddevice"];
    data.date = root["HistDataDate"];
    data.value = root["HistDataValue"];
    data.iddatatype = root["IddataType"];
    data.dataToDevice = root["HistDataToDevice"];
    data.dataAck = root["HistDataAck"];
    data.dataAux = root["HistDataAux"];
    return root.success();
}
