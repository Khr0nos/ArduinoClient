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

/// <summary>
/// Status code enumeration
/// </summary>
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

/// <summary>
/// Arduino CloudClient class. Defines Arduino client for service
/// </summary>
class CloudClient {

public:
	/// <summary>
	/// Default constructor
	/// </summary>
    CloudClient();

	/// <summary>
	/// Custom constructor
	/// </summary>
	/// <param name='url'>
	/// Base url of the service
	/// </param>
	/// <param name='resource'>
	/// Service endpoint path
	/// </param>
	/// <param name='content'>
	/// Content type identifier
	/// </param>
    CloudClient(char* url, char* resource, char* content = "application/json");

	/// <summary>
	/// Default destructor
	/// </summary>
    ~CloudClient();

	/// <summary>
	/// Get single data by id
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode get(int id, String* response);
	/// <summary>
	/// Get all data
	/// </summary>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode get(String* response);
	/// <summary>
	/// Send data
	/// </summary>
	/// <param name='data'>
	/// Data to be sent
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode post(Data& data);
	/// <summary>
	/// Send data
	/// </summary>
	/// <param name='data'>
	/// Data to be sent
	/// </param>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode post(Data& data, String* response);
	/// <summary>
	/// Update data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='data'>
	/// Data to be updated
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode put(int id, Data& data);
	/// <summary>
	/// Update data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='data'>
	/// Data to be updated
	/// </param>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode put(int id, Data& data, String* response);
	/// <summary>
	/// Partial update data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='data'>
	/// Partial update
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode patch(int id, JsonPatch& data);
	/// <summary>
	/// Partial update data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='data'>
	/// Partial update
	/// </param>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode patch(int id, JsonPatch& data, String* response);
	/// <summary>
	/// Delete data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode del(int id);
	/// <summary>
	/// Delete data
	/// </summary>
	/// <param name='id'>
	/// Data identifier
	/// </param>
	/// <param name='response'>
	/// Response from service
	/// </param>
	/// <returns>
	/// Status code from response
	/// </returns>
    StatusCode del(int id, String* response);

	/// <summary>
	/// Set content type
	/// </summary>
	/// <param name='Type'>
	/// New content type
	/// </param>
    void set_ContentType(const char* Type);
	/// <summary>
	/// Add header
	/// </summary>
	/// <param name='header'>
	/// New header
	/// </param>
    void set_Header(const char* header);
	
private:
	/// <summary>
	/// Base URL of service
	/// </summary>
    char* Base_URL;
	/// <summary>
	/// Path to service endpoint
	/// </summary>
    char* Resource;
	/// <summary>
	/// Number of headers defined
	/// </summary>
    int num_headers;
	/// <summary>
	/// Array of headers
	/// </summary>
    const char* headers[10];
	/// <summary>
	/// Type of content to send/receive
	/// </summary>
    const char* contentType;

	/// <summary>
	/// Auxiliar method. Parse request response from internal buffer
	/// </summary>
    static StatusCode get_response(String* response, String buffer);
};
#endif
