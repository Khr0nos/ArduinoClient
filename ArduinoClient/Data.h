// Data.h

#ifndef _DATA_h
#define _DATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class DataClass {
 protected:


 public:
	void init();
};

extern DataClass Data;

#endif

