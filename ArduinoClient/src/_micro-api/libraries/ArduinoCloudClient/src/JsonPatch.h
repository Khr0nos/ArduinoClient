#ifndef _JsonPatch_h
#define _JsonPatch_h

#include <ArduinoJson.h>

#define NULL 0
/// <summary>
/// JsonPatch class. Defines list of partial updates
/// </summary>
class JsonPatch {
public:
	/// <summary>
	/// Default constructor
	/// </summary>
    JsonPatch();
	/// <summary>
	/// Custom constructor. Initialization with one partial update
	/// </summary>
	/// <param name='field'>
	/// data field to be updated
	/// </param>
	/// <param name='value'>
	/// New value
	/// </param>
    JsonPatch(char * field, JsonVariant value);
	/// <summary>
	/// Default destructor
	/// </summary>
    ~JsonPatch();

	/// <summary>
	/// Serialization of partial update into string
	/// </summary>
	/// <param name='data'>
	/// Partial update to be serialized
	/// </param>
	/// <param name='json'>
	/// Output serialized string
	/// </param>
	/// <param name='indented'>
	/// Use of indentation in serialization
	/// </param>
    static void Serialize(const JsonPatch& data, char* json, bool indented = false);
	/// <summary>
	/// Deserialization of partial update into JsonPatch
	/// </summary>
	/// <param name='data'>
	/// Output Partial update
	/// </param>
	/// <param name='json'>
	/// Json string containing partial update
	/// </param>
    static bool Deserialize(JsonPatch& data, char* json);

	/// <summary>
	/// Add partial update to list
	/// </summary>
	/// <param name='field'>
	/// data field to be updated
	/// </param>
	/// <param name='value'>
	/// New value
	/// </param>
    void add_Data(char * field, JsonVariant value);
private:
	/// <summary>
	/// Private list of partial updates
	/// </summary>
    JsonVariant patchData;
};

#endif
