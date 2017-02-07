/*
 Name:		ArduinoCloudClient.h
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
    #include "Data.h"
#else
	#include "WProgram.h"
#endif

#define POST_DATA_SIZE (JSON_OBJECT_SIZE(8))

class CloudClient {

public:
    CloudClient();
    CloudClient(char* url, char* resource, char* content);
    ~CloudClient();

    int post(Data& data);
    int post(Data& data, char* response);

    void set_ContentType(const char* Type);
    void set_Header(const char* header);

    void Set_Data(Data& data);
    void Serialize(char* json, bool indented = false);
    bool Deserialize(char* json);

private:
    char* Base_URL;
    char* Resource;
    int num_headers;
    const char* headers[10];
    const char* contentType;
    Data data;
};

#endif
