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
