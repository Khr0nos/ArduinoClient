#ifndef _Data_h
#define _Data_h

#define NULL 0

class Data {

public:
    Data();
    Data(int device, char* datavalue, int dataType, bool toDevice = false, bool Ack = false, char* Aux = NULL);
    ~Data();

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