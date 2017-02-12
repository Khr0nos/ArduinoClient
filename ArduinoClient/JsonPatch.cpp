#include "JsonPatch.h"

JsonPatch::JsonPatch() {
    StaticJsonBuffer<200> buffer;
    patchData = buffer.createArray();
}

JsonPatch::JsonPatch(char* field, JsonVariant value) {
    StaticJsonBuffer<200> buffer;
    patchData = buffer.createArray();
    JsonArray& array = patchData.as<JsonArray&>();
    JsonObject& nested = array.createNestedObject();
    nested["op"] = "replace";
    nested["path"] = field;
    nested["value"] = value;
    //patchData = array;
    /*JsonObject& elem = buffer.createObject();
    elem["op"] = "replace";
    elem["path"] = field;
    elem["value"] = value;
    array.add(elem);*/
}

JsonPatch::~JsonPatch() {}

void JsonPatch::Serialize(const JsonPatch& data, char* json, bool indented) {
    JsonArray& array = data.patchData.as<JsonArray&>();
    size_t size;
    if (indented) {
        size = array.measurePrettyLength() + 1;
        array.prettyPrintTo(json, size);
    }
    else {
        size = array.measureLength() + 1;
        array.printTo(json, size);
    }
}

bool JsonPatch::Deserialize(JsonPatch& data, char* json) {
    StaticJsonBuffer<500> buffer;

    data.patchData = buffer.parseArray(json);
}

void JsonPatch::add_Data(char* field, JsonVariant value) {
    JsonArray& array = patchData.as<JsonArray&>();
    JsonObject& nested = array.createNestedObject();
    nested["op"] = "replace";
    nested["path"] = field;
    nested["value"] = value;
}
