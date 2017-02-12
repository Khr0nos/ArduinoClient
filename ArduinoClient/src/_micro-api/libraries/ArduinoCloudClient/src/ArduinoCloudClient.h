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
    #include "JsonPatch.h"
#else
	#include "WProgram.h"
#endif

class CloudClient {

public:
    CloudClient();
    CloudClient(char* url, char* resource, char* content = "application/json");
    ~CloudClient();

    int get(int id, String* response);
    int get(String* response);
    int post(Data& data);
    int post(Data& data, String* response);
    int put(Data& data);
    int put(Data& data, String* response);
    int patch(int id, JsonPatch& data);
    int patch(int id, JsonPatch& data, String* response);
    int del(int id);
    int del(int id, String* response);

    void set_ContentType(const char* Type);
    void set_Header(const char* header);

private:
    char* Base_URL;
    char* Resource;
    int num_headers;
    const char* headers[10];
    const char* contentType;

    static int get_response(String* response, String buffer);
};

#endif
