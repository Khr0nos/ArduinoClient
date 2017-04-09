#pragma once
#ifndef _Data_h
#define _Data_h

#include <ArduinoJson.h>

#define NULL 0
#define POST_DATA_SIZE (JSON_OBJECT_SIZE(8))
/// <summary>
/// Data class. Defines data format of service
/// </summary>
class Data {

public:
	/// <summary>
	/// Default constructor
	/// </summary>
    Data();
	/// <summary>
	/// Custom constructor
	/// </summary>
	/// <param name='device'>
	/// Device identifier
	/// </param>
	/// <param name='datavalue'>
	/// Data value
	/// </param>
	/// <param name='dataType'>
	/// Data type identifier
	/// </param>
	/// <param name = 'toDevice'>
	/// Optional. Indicate sending to device
	/// </param>
	/// <param name = 'Ack'>
	/// Optional. Indicate acknowledgement from device
	/// </param>
	/// <param name = 'Aux'>
	/// Optional. Auxiliar field
	/// </param>
    Data(int device, char* datavalue, int dataType, bool toDevice = false, bool Ack = false, char* Aux = NULL);
	/// <summary>
	/// Default destructor
	/// </summary>
    ~Data();

	/// <summary>
	/// Serialization of data into string
	/// </summary>
	/// <param name='data'>
	/// Data to be serialized
	/// </param>
	/// <param name='json'>
	/// Output serialized string
	/// </param>
	/// <param name='indented'>
	/// Use of indentation in serialization
	/// </param>
    static void Serialize(const Data& data, char* json, bool indented = false);
	/// <summary>
	/// Deserialization of Data
	/// </summary>
	/// <param name='data'>
	/// Output data
	/// </param>
	/// <param name='json'>
	/// Json string containing data
	/// </param>
    static bool Deserialize(Data& data, char* json);

	/// <summary>
	/// Data identifier
	/// </summary>
    int idData;
	/// <summary>
	/// Device identifier
	/// </summary>
    int idDevice;
	/// <summary>
	/// Date and time of creation
	/// </summary>
    char* date;
	/// <summary>
	/// Data value
	/// </summary>
    char* value;
	/// <summary>
	/// Data type identifier
	/// </summary>
    int iddatatype;
	/// <summary>
	/// Indicates if data sent to device
	/// </summary>
    bool dataToDevice;
	/// <summary>
	/// Indicates if data is acknowledged
	/// </summary>
    bool dataAck;
	/// <summary>
	/// Auxiliar field
	/// </summary>
    char* dataAux;

};

#endif