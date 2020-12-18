#pragma once
#include "IW5CheatSP.h"


union VariableUnion {
	int intValue;
	unsigned int uintValue;
	float floatValue;
	unsigned int stringValue;
	const float *vectorValue;
	const char *codePosValue;
	unsigned int pointerValue;
	unsigned int entityOffset;
};


struct VariableValue {
	VariableUnion u;
	int type;
};
