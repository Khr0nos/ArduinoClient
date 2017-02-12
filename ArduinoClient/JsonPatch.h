#ifndef _JsonPatch_h
#define _JsonPatch_h

#include <ArduinoJson.h>

#define NULL 0

class JsonPatch {
public:

    JsonPatch();
    JsonPatch(char * field, JsonVariant value);
    ~JsonPatch();

    void Serialize(const JsonPatch& data, char* json, bool indented = false);
    bool Deserialize(JsonPatch& data, char* json);

    void add_Data(char * field, JsonVariant value);
private:
    JsonVariant patchData;
};

#endif
