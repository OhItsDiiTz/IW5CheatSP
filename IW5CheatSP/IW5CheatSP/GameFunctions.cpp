#include "GameFunctions.h"

template <typename T> T(*GameCall(unsigned int address))(...) {
	T(*func)(...) = (T(*)(...))address;
	return func;
}

unsigned int Scr_GetSelf(unsigned int threadId) {
	return GameCall<unsigned int>(0x004D2FD0)(threadId);
}

const char * SL_ConvertToString(unsigned int stringValue) {
	return GameCall<const char *>(0x00414290)(stringValue);
}

