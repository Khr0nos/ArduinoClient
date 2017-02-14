/*
 Name:		ArduinoCloudClient.cpp
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#include "ArduinoCloudClient.h"

CloudClient::CloudClient() {
    Base_URL = "https://cloudtfg.azurewebsites.net";
    Resource = "/api/historicdata/";
    num_headers = 0;
    contentType = "application/json";
}

CloudClient::CloudClient(char* url, char* resource, char* content) {
    Base_URL = url;
    String res = String(resource);
    if (res.charAt(res.length() - 1) != '/') resource += '/';
    Resource = resource;
    num_headers = 0;
    contentType = content;
}

CloudClient::~CloudClient() {}

StatusCode CloudClient::get(int id, String* response) {
    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("GET");
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource) + String(id));
    p.run();

    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::get(String * response) {
    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("GET");
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource));
    p.run();

    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::post(Data& data) {
    return post(data, NULL);
}

StatusCode CloudClient::post(Data& data, String* response) {
    char json[256];
    Data::Serialize(data, json);

    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("POST");
    p.addParameter("-d");
    p.addParameter(json);
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource));
    p.run();
    
    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::put(Data& data) {
    return put(data, NULL);
}

StatusCode CloudClient::put(Data& data, String* response) {
    char json[256];
    Data::Serialize(data, json);

    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("PUT");
    p.addParameter("-d");
    p.addParameter(json);
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource));
    p.run();

    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::patch(int id, JsonPatch& data) {
    return patch(id, data, NULL);
}

StatusCode CloudClient::patch(int id, JsonPatch& data, String* response) {
    char json[256];
    JsonPatch::Serialize(data, json);

    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("PATCH");
    p.addParameter("-d");
    p.addParameter(json);
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource) + String(id));
    p.run();

    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::del(int id) {
    return del(id, NULL);
}

StatusCode CloudClient::del(int id, String* response) {
    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType));
    for (int i = 0; i < num_headers; i++) {
        p.addParameter("-H");
        p.addParameter(headers[i]);
    }
    p.addParameter("-X");
    p.addParameter("DELETE");
    p.addParameter("-s");
    p.addParameter("-w");
    p.addParameter("%{http_code}");
    p.addParameter(String(Base_URL) + String(Resource) + String(id));
    p.run();

    String buffer = "";
    while (p.available() > 0) {
        char c = p.read();
        buffer.concat(c);
    }

    //clean headers
    num_headers = 0;

    return get_response(response, buffer);
}

StatusCode CloudClient::get_response(String* response, String buffer) {
    int i = buffer.lastIndexOf('}');
    String body = buffer.substring(0, i + 1);
    *response = body;

    return StatusCode((buffer.substring(i + 1)).toInt());
}

void CloudClient::set_ContentType(const char* Type) {
    contentType = Type;
}

void CloudClient::set_Header(const char* header) {
    headers[num_headers] = header;
    num_headers++;
}

