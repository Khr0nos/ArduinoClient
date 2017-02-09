#ifndef _Data_h
#define _Data_h

#include <ArduinoJson.h>

#define NULL 0
#define POST_DATA_SIZE (JSON_OBJECT_SIZE(8))

class Data {

public:
    Data();
    Data(int device, char* datavalue, int dataType, bool toDevice = false, bool Ack = false, char* Aux = NULL);
    ~Data();

    static void Serialize(const Data& data, char* json, bool indented = false);
    static bool Deserialize(Data& data, char* json);

    int idData;
    int idDevice;
    char* date;
    char* value;
    int iddatatype;
    bool dataToDevice;
    bool dataAck;
    char* dataAux;

};

#endif