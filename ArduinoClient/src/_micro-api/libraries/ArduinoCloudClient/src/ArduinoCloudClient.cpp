/*
 Name:		ArduinoCloudClient.cpp
 Created:	2/5/2017 9:50:10 PM
 Author:	Xavi
 Editor:	http://www.visualmicro.com
*/

#include "ArduinoCloudClient.h"

CloudClient::CloudClient() {
    Base_URL = "http://cloudtfg.azurewebsites.net";
    Resource = "/api/historicdata";
    num_headers = 0;
    contentType = "application/json";
}

CloudClient::CloudClient(char* url, char* resource, char* content) {
    Base_URL = url;
    Resource = resource;
    num_headers = 0;
    contentType = content;
}

CloudClient::~CloudClient() {}

int CloudClient::post(Data& data) {
    return post(data, NULL);
}

int CloudClient::post(Data& data, String* response) {
    char json[256];
    Serialize(data, json);

    Process p;
    p.begin("curl");
    p.addParameter("-k");
    p.addParameter("-H");
    p.addParameter("Content-Type: " + String(contentType)); //afegir headers addicionals si num_headers > 0
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

    int i = buffer.lastIndexOf('}');
    String body = buffer.substring(0, i + 1);
    *response = body;

    int statusCode = (buffer.substring(i + 1)).toInt();
    return statusCode;
}

void CloudClient::set_ContentType(const char* Type) {
    contentType = Type;
}

void CloudClient::set_Header(const char* header) {
    headers[num_headers] = header;
    num_headers++;
}

void CloudClient::Serialize(const Data& data, char* json, bool indented) {
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
    } else {
        size = root.measureLength() + 1;
        root.printTo(json, size);
    }
}

bool CloudClient::Deserialize(Data& data, char* json) {
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
