#pragma once
#include "IW5CheatSP.h"

template <typename T> T(*GameCall(unsigned int address))(...);

unsigned int Scr_GetSelf(unsigned int threadId);
const char * SL_ConvertToString(unsigned int stringValue);

