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

class JsonPatch;

enum StatusCode {
    Ok = 200,
    Created = 201,
    No_Content = 204,
    Bad_Request = 400,
    Unauthorized = 401,
    Forbidden = 403,
    Not_Found = 404,
    Conflict = 409
};

class CloudClient {

public:
    CloudClient();
    CloudClient(char* url, char* resource, char* content = "application/json");
    ~CloudClient();

    StatusCode get(int id, String* response);
    StatusCode get(String* response);
    StatusCode post(Data& data);
    StatusCode post(Data& data, String* response);
    StatusCode put(Data& data);
    StatusCode put(Data& data, String* response);
    StatusCode patch(int id, JsonPatch& data);
    StatusCode patch(int id, JsonPatch& data, String* response);
    StatusCode del(int id);
    StatusCode del(int id, String* response);

    void set_ContentType(const char* Type);
    void set_Header(const char* header);

private:
    char* Base_URL;
    char* Resource;
    int num_headers;
    const char* headers[10];
    const char* contentType;

    static StatusCode get_response(String* response, String buffer);
};
#endif
